#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //setlocale(LC_ALL, "Portuguese_Brazil");
    ui->te_outDisplay->setReadOnly(true);
    ui->te_outDisplay->setCursor(Qt::ArrowCursor);
    connect(ui->btn_exec, &QPushButton::clicked, this, &MainWindow::on_btnExec_clicked);
    connect(ui->btn_parar, &QPushButton::clicked, this, &MainWindow::on_btnParar_clicked);
    connect(ui->cb_util, &QComboBox::currentIndexChanged, this, &MainWindow::onTipoEntradaIndexChanged);
    connect(ui->cb_peso, &QComboBox::currentIndexChanged, this, &MainWindow::onTipoEntradaIndexChanged);
    connect(ui->btn_loadFile, &QPushButton::clicked, this, &MainWindow::selectFile);
}

MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief A função abre o dialog para o usuario selecionar um arquivo com as especificações do problema.
 * @details Leitura do arquivo selecionado, e definição dos parametros para o problema no objeto do tipo Mochila.
*/
void MainWindow::selectFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"), "", tr("All Files (*)"));

    if (!fileName.isEmpty()) {
        Mochila data;
        data.lerArquivo(fileName.toStdString());
        ui->sb_numItens->setValue(data.getNItens());
        ui->sb_capMochila->setValue(data.getCapacidade());
        ui->le_pesoItem->setText(QString::fromStdString(data.arrToString(data.getPesos())));
        ui->le_utilItem->setText(QString::fromStdString(data.arrToString(data.getUtilidades())));
        problemData = data;
    }
    else {
        // Handle error opening the file
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file: ") + fileName);
    }
}
/**
 * @brief A função gerencia a criação de pesos e utilidades
 * @details Desabilita
*/
void MainWindow::onTipoEntradaIndexChanged(int index) {
    // Disable the line edit based on the selected index
    if (ui->cb_util->hasFocus()) {
        ui->le_utilItem->setEnabled(index == 0);
    }
    else {
        ui->le_pesoItem->setEnabled(index == 0);
    }
}
/**
 * @brief A função abaixo da inicio a execução da solução do problema da mochila.
 * @details Efetuação a execução da solução, e exibe os resultados para o usuário.
*/
void MainWindow::on_btnExec_clicked()
{
    if(ui->sb_capMochila->value() > 0 && ui->sb_numItens->value() > 0){
        //int resultado; // Valor da capacidade maxima
        pair<int, double> resultado; // Valor da capacidade maxima
        pair<int, vector<int>> result;
        int r =0;
        ui->te_outDisplay->append(">> Execução iniciada.");
        if (ui->le_nomeArquivo->text().isEmpty()) {
            // ---------- Entrada manual de especificações
            problemData.setCapacidade(ui->sb_capMochila->value());
            problemData.setNItens(ui->sb_numItens->value());
            if (ui->cb_peso->currentIndex() == 1) {
                problemData.setPesos(problemData.gerRandPesoUtil(problemData.getNItens(), problemData.getCapacidade()));
            }
            else { problemData.setPesos(problemData.strToArray(ui->le_pesoItem->text().toStdString())); }
            if (ui->cb_util->currentIndex() == 1) {
                problemData.setUtilidades(problemData.gerRandPesoUtil(problemData.getNItens(), problemData.getCapacidade()));
            }
            else { problemData.setUtilidades(problemData.strToArray(ui->le_utilItem->text().toStdString())); }

            resultado = problemData.solveKSP();
            result = problemData.solveKSP_2();
            r= problemData.knapsack();
        }
        else { /// Entra aqui somente se usuario passar um arquivo de texto com as especificações do problema.
            // ---------- Arquivo de Especificações lido.
            resultado = problemData.solveKSP();
        }
        int maxUtility = result.first;
        vector<int> itemsSelected = result.second;
        /// Formatando os dados para exibir os resultados
        string pesoS = problemData.arrToString(problemData.getPesos());
        string utilS = problemData.arrToString(problemData.getUtilidades());
        QString sresult = QString::number(resultado.first);
        QString stime = QString::number(resultado.second,'f',7);
        QString reduceResult = QString::number(r);
        QString info = "Pesos:" + QString::fromStdString(pesoS) + "\n>> Utils.:" + QString::fromStdString(utilS);
        ui->te_outDisplay->append(">> Solução encontrada: Utilidade maxima => " + reduceResult + " Time: "+stime + "seconds");
        //ui->te_outDisplay->append(">> " + info);
        string items;
        string mu = to_string(maxUtility);
        for (int item : itemsSelected) {
            string item_ = to_string(item);
            items = items+item_+",";
        }
        ui->te_outDisplay->append(">> Itens Escolhidos: "+ QString::fromStdString(items)+" MaxU: "+ QString::fromStdString(mu));
        ui->te_outDisplay->append("=====================================================================================");
    }else{
        QMessageBox msgBox;
        msgBox.setText("A capacidade e qtd. itens não pode ser 0.");
        msgBox.exec();
    }
}
/// ---------------- Interrope a execução
void MainWindow::on_btnParar_clicked()
{
    ui->te_outDisplay->clear();
    ui->te_outDisplay->append("Execução interrompida!");
}

