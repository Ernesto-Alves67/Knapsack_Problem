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
    ui->te_problem_data->setReadOnly(true);
    ui->te_problem_data->setCursor(Qt::ArrowCursor);
    connect(ui->btn_exec, &QPushButton::clicked, this, &MainWindow::on_btnExec_clicked);
    connect(ui->btn_parar, &QPushButton::clicked, this, &MainWindow::on_btnParar_clicked);
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

/**
 * @brief A função abre o dialog para o usuario selecionar um arquivo com as especificações do problema.
 * @details Leitura do arquivo selecionado, e definição dos parametros para o problema no objeto do tipo Mochila.
*/
void MainWindow::selectFile() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select File"), "", tr("All Files (*)"));

    if (!fileName.isEmpty()) {

        ui->le_nomeArquivo->setText(fileName);
        ui->le_nomeArquivo->setReadOnly(true);
        problemData.lerArquivo(fileName.toStdString());

        show_problem_data();
    }
    else {
        // Handle error opening the file
        QMessageBox::warning(this, tr("Error"), tr("Unable to open file: ") + fileName);
    }
}

// ================= Exibe os dados do problema a ser resolvido
void MainWindow::show_problem_data(){
    ui->te_problem_data->append("= Parâmetros =================================");
    ui->te_problem_data->append("Pesos: "+QString::fromStdString(problemData.arrToString(problemData.getPesos())));
    ui->te_problem_data->append("Utilidades: "+QString::fromStdString(problemData.arrToString(problemData.getUtilidades())));
    ui->te_problem_data->append("Peso Total da Mochila: "+QString::number(problemData.getCapacidade()));
    ui->te_problem_data->append("Nº items disponiveis para escolha: "+QString::number(problemData.getNItens()));
}
/**
 * @brief A função abaixo captura o sinal de clique em "Executar"
 * @details Obtém o parametros do problema e chama "init_thread_execution"
*/
void MainWindow::on_btnExec_clicked()
{
    init_thread_execution();

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
    ui->te_outDisplay->append("Utilidade Máxima: "+sresult+" \n Tempo de execução: "+stime+"seconds");
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


