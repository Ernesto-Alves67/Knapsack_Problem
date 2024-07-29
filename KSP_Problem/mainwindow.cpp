#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QThread>
#include "knapsackrunner.h"



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
/**
 * @details Destrutor da classe.
*/
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::aviso_para_usuario(QString mensagem)
{
    QMessageBox msgBox;
    msgBox.setText(mensagem);
    msgBox.exec();
}
bool MainWindow::checa_peso_n_itens()
{
    if(ui->sb_capMochila->value() == 0 ||ui->sb_numItens->value() == 0){return false;}
    else{return true;}
}
bool MainWindow::checa_utilidadeEPesoPorItem()
{
    if(ui->cb_peso->currentIndex() == 0 || ui->le_pesoItem->text() == " "||ui->cb_util->currentIndex() == 0 || ui->le_utilItem->text() == " "){return false;}
    else{return true;}
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
 * @brief A função abaixo captura o sinal de clique em "Executar"
 * @details Obtém o parametros do problema e chama "init_thread_execution"
*/
void MainWindow::on_btnExec_clicked()
{
    if(!(checa_utilidadeEPesoPorItem() && checa_peso_n_itens())){
        aviso_para_usuario("Os pesos/item estão vazios! Escolha random ou entre com os valores.");
        return;
    }else{ui->te_outDisplay->append(">> Execução iniciada...");}
    //ui->te_outDisplay->append(">> Execução iniciada...");
    if(ui->sb_capMochila->value() > 0 && ui->sb_numItens->value() > 0){

        pair<int, double> resultado; // par<utilidade_maxima, tempoExecuçao>

        if (ui->le_nomeArquivo->text().isEmpty()) {
            // ---------- Entrada manual de especificações
            problemData.setCapacidade(ui->sb_capMochila->value());
            problemData.setNItens(ui->sb_numItens->value());
            if (ui->cb_peso->currentIndex() == 1) {
                problemData.setPesos(problemData.gerRandPesoUtil(problemData.getNItens(), problemData.getCapacidade()));
            }
            else {
                if(ui->cb_peso->currentIndex() == 0 && ui->le_pesoItem->text() == " "){
                    aviso_para_usuario("Os pesos/item estão vazios! Escolha random ou entre com os valores.");
                }
                problemData.setPesos(problemData.strToArray(ui->le_pesoItem->text().toStdString())); }
            if (ui->cb_util->currentIndex() == 1) {
                problemData.setUtilidades(problemData.gerRandPesoUtil(problemData.getNItens(), problemData.getCapacidade()));
            }
            else {
                if(ui->cb_util->currentIndex() == 0 && ui->le_utilItem->text() == " "){
                    aviso_para_usuario("As utilidades/items estão vazias! Escolha random ou entre com os valores.");
                }
                problemData.setUtilidades(problemData.strToArray(ui->le_utilItem->text().toStdString())); }
            init_thread_execution();
        }
        else { /// Entra aqui somente se usuario passar um arquivo de texto com as especificações do problema.
            // ---------- Arquivo de Especificações lido.
            init_thread_execution();
        }

        /// Formatando os dados para exibir os resultados para a versã sem Threads
        // QString sresult = QString::number(resultado.first);
        // QString stime = QString::number(resultado.second,'f',7);

        // ui->te_outDisplay->append(">> Solução encontrada: Utilidade maxima => " + sresult + "\n Time: "+stime + "seconds");
        // //ui->te_outDisplay->append(">> " + info);
        // string items;
        // string max_u = to_string(maxUtility);
        // for (int item : itemsSelected) {
        //     string item_ = to_string(item);
        //     items = items+item_+",";
        // }
        // ui->te_outDisplay->append(">> Itens Escolhidos: "+ QString::fromStdString(items)+" MaxU: "+ QString::fromStdString(max_u));
        // ui->te_outDisplay->append("=====================================================================================");
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
/**
 * @brief A função abaixo recebe os resultados da solução.
 * @details Formata o tempo de execução e exibe a utilidade da mochila para capacidade N e quantidade de itens M.
*/
void MainWindow::resultReady(std::pair<int, double> result)
{
    QString sresult = QString::number(result.first);
    QString stime = QString::number(result.second,'f',5);
    //ui->te_outDisplay->append(">> Execução concluída.");
    ui->te_outDisplay->append("Utilidade Maxima: "+sresult+" \n Tempo de execução: "+stime+"seconds");
    ui->te_outDisplay->append("==================================================");
}
/**
 * @brief A função abaixo da inicio a execução da solução do problema da mochila por meio de uma thread.
 * @details Efetuação a execução da solução, passa o resultado para reseultready
*/
void MainWindow::init_thread_execution(){
    QThread *thread = new QThread;
    KnapsackRunner *runner = new KnapsackRunner(&problemData);
    runner->moveToThread(thread);

    connect(thread, &QThread::started, runner, &KnapsackRunner::run);
    connect(runner, &KnapsackRunner::resultReady, this, &MainWindow::resultReady);
    connect(runner, &KnapsackRunner::resultReady, thread, &QThread::quit);
    connect(runner, &KnapsackRunner::resultReady, runner, &KnapsackRunner::deleteLater);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    thread->start();
}
