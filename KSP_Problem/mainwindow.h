#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ksp_core.h"
#include "knapsackrunner.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    // ---------------------- Utils
    void resultReady(std::pair<int, double> result);
    void selectFile();
    void aviso_para_usuario(QString mensagem);
    bool checa_utilidadeEPesoPorItem();
    bool checa_peso_n_itens();
    void init_thread_execution();
    // ---------------------- Botoes
    void onTipoEntradaIndexChanged(int index);
    void on_btnExec_clicked();
    void on_btnParar_clicked();
private:
    Ui::MainWindow *ui;
    Mochila problemData;
};
#endif // MAINWINDOW_H
