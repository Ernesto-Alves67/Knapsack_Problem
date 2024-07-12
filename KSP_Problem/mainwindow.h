#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ksp_core.h"
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

    // ---------------------- Utils
    Mochila problemData;
    void selectFile();
    // ---------------------- Botoes
    void onTipoEntradaIndexChanged(int index);
    void on_btnExec_clicked();
    void on_btnParar_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
