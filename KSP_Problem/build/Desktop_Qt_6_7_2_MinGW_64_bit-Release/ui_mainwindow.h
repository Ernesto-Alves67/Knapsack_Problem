/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *le_nomeArquivo;
    QToolButton *btn_loadFile;
    QPushButton *btn_exec;
    QPushButton *btn_parar;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *te_problem_data;
    QTextEdit *te_outDisplay;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 85, 127);"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(16777215, 16777215));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        groupBox_2->setFont(font);
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);\n"
"color: rgb(0, 0, 0);"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        label_5->setFont(font1);

        horizontalLayout->addWidget(label_5);

        le_nomeArquivo = new QLineEdit(groupBox_2);
        le_nomeArquivo->setObjectName("le_nomeArquivo");
        le_nomeArquivo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(le_nomeArquivo);

        btn_loadFile = new QToolButton(groupBox_2);
        btn_loadFile->setObjectName("btn_loadFile");
        btn_loadFile->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);"));

        horizontalLayout->addWidget(btn_loadFile);

        btn_exec = new QPushButton(groupBox_2);
        btn_exec->setObjectName("btn_exec");
        QFont font2;
        font2.setPointSize(11);
        btn_exec->setFont(font2);
        btn_exec->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);"));

        horizontalLayout->addWidget(btn_exec);

        btn_parar = new QPushButton(groupBox_2);
        btn_parar->setObjectName("btn_parar");
        btn_parar->setFont(font2);

        horizontalLayout->addWidget(btn_parar);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setFont(font);
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);\n"
"color: rgb(0, 0, 0);"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setFont(font);
        groupBox_3->setStyleSheet(QString::fromUtf8("background-color: rgb(130, 130, 130);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_3);
        verticalLayout_3->setObjectName("verticalLayout_3");
        te_problem_data = new QTextEdit(groupBox_3);
        te_problem_data->setObjectName("te_problem_data");
        QFont font3;
        font3.setPointSize(9);
        font3.setBold(true);
        te_problem_data->setFont(font3);
        te_problem_data->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(0, 223, 0);"));

        verticalLayout_3->addWidget(te_problem_data);


        verticalLayout->addWidget(groupBox_3);

        te_outDisplay = new QTextEdit(groupBox);
        te_outDisplay->setObjectName("te_outDisplay");
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font4.setPointSize(14);
        font4.setBold(true);
        te_outDisplay->setFont(font4);
        te_outDisplay->setStyleSheet(QString::fromUtf8("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(te_outDisplay);


        verticalLayout_4->addWidget(groupBox);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Knapsack Problem", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Entradas", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Load File", nullptr));
#if QT_CONFIG(statustip)
        le_nomeArquivo->setStatusTip(QCoreApplication::translate("MainWindow", "Capacidade total em pesos.", nullptr));
#endif // QT_CONFIG(statustip)
        le_nomeArquivo->setPlaceholderText(QCoreApplication::translate("MainWindow", "D:\\arquivo\\especifica\303\247\303\243o\\do\\problema", nullptr));
        btn_loadFile->setText(QCoreApplication::translate("MainWindow", "Choose File", nullptr));
        btn_exec->setText(QCoreApplication::translate("MainWindow", "Execute", nullptr));
        btn_parar->setText(QCoreApplication::translate("MainWindow", "Stop/Clear", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Sa\303\255da", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Dados do Problema:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
