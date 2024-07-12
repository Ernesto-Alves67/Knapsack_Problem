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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label_5;
    QLineEdit *le_nomeArquivo;
    QToolButton *btn_loadFile;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpinBox *sb_capMochila;
    QLabel *label_2;
    QSpinBox *sb_numItens;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *le_utilItem;
    QComboBox *cb_util;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *le_pesoItem;
    QComboBox *cb_peso;
    QPushButton *btn_exec;
    QPushButton *btn_parar;
    QPushButton *btn_exec_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
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
        horizontalLayout_5 = new QHBoxLayout(centralwidget);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setMinimumSize(QSize(0, 0));
        groupBox_2->setMaximumSize(QSize(320, 16777215));
        groupBox_2->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);\n"
"color: rgb(0, 0, 0);"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName("label_5");
        QFont font;
        font.setPointSize(11);
        label_5->setFont(font);

        horizontalLayout->addWidget(label_5);

        le_nomeArquivo = new QLineEdit(groupBox_2);
        le_nomeArquivo->setObjectName("le_nomeArquivo");
        le_nomeArquivo->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(le_nomeArquivo);

        btn_loadFile = new QToolButton(groupBox_2);
        btn_loadFile->setObjectName("btn_loadFile");
        btn_loadFile->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);"));

        horizontalLayout->addWidget(btn_loadFile);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(groupBox_2);
        label->setObjectName("label");
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        sb_capMochila = new QSpinBox(groupBox_2);
        sb_capMochila->setObjectName("sb_capMochila");
        QFont font1;
        font1.setPointSize(10);
        sb_capMochila->setFont(font1);
        sb_capMochila->setMaximum(1000000);

        horizontalLayout_2->addWidget(sb_capMochila);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(20, 0));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        sb_numItens = new QSpinBox(groupBox_2);
        sb_numItens->setObjectName("sb_numItens");
        sb_numItens->setMaximum(1000000);

        horizontalLayout_2->addWidget(sb_numItens);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(groupBox_2);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        le_utilItem = new QLineEdit(groupBox_2);
        le_utilItem->setObjectName("le_utilItem");
        le_utilItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_3->addWidget(le_utilItem);

        cb_util = new QComboBox(groupBox_2);
        cb_util->addItem(QString());
        cb_util->addItem(QString());
        cb_util->setObjectName("cb_util");

        horizontalLayout_3->addWidget(cb_util);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName("label_4");
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        le_pesoItem = new QLineEdit(groupBox_2);
        le_pesoItem->setObjectName("le_pesoItem");
        le_pesoItem->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        horizontalLayout_4->addWidget(le_pesoItem);

        cb_peso = new QComboBox(groupBox_2);
        cb_peso->addItem(QString());
        cb_peso->addItem(QString());
        cb_peso->setObjectName("cb_peso");

        horizontalLayout_4->addWidget(cb_peso);


        verticalLayout_3->addLayout(horizontalLayout_4);

        btn_exec = new QPushButton(groupBox_2);
        btn_exec->setObjectName("btn_exec");
        btn_exec->setFont(font);
        btn_exec->setStyleSheet(QString::fromUtf8("background-color: rgb(122, 122, 122);"));

        verticalLayout_3->addWidget(btn_exec);

        btn_parar = new QPushButton(groupBox_2);
        btn_parar->setObjectName("btn_parar");
        btn_parar->setFont(font);

        verticalLayout_3->addWidget(btn_parar);

        btn_exec_2 = new QPushButton(groupBox_2);
        btn_exec_2->setObjectName("btn_exec_2");

        verticalLayout_3->addWidget(btn_exec_2);


        horizontalLayout_5->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(16777215, 16777215));
        groupBox->setStyleSheet(QString::fromUtf8("background-color: rgb(179, 179, 179);"));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName("verticalLayout");
        te_outDisplay = new QTextEdit(groupBox);
        te_outDisplay->setObjectName("te_outDisplay");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Yu Gothic UI Semibold")});
        font2.setBold(true);
        te_outDisplay->setFont(font2);
        te_outDisplay->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(te_outDisplay);


        horizontalLayout_5->addWidget(groupBox);

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
        btn_loadFile->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Capacidade:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Qtd. Itens:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Utilidade/item:", nullptr));
        le_utilItem->setInputMask(QString());
        le_utilItem->setPlaceholderText(QCoreApplication::translate("MainWindow", "[u1,u2,u3,...Un]", nullptr));
        cb_util->setItemText(0, QCoreApplication::translate("MainWindow", "Self entry", nullptr));
        cb_util->setItemText(1, QCoreApplication::translate("MainWindow", "Random", nullptr));

#if QT_CONFIG(whatsthis)
        cb_util->setWhatsThis(QCoreApplication::translate("MainWindow", "Defined by user or Randonly defined.", nullptr));
#endif // QT_CONFIG(whatsthis)
        label_4->setText(QCoreApplication::translate("MainWindow", "Peso/item:", nullptr));
        le_pesoItem->setPlaceholderText(QCoreApplication::translate("MainWindow", "[p1,p2,p3,....Pn]", nullptr));
        cb_peso->setItemText(0, QCoreApplication::translate("MainWindow", "Self Entry", nullptr));
        cb_peso->setItemText(1, QCoreApplication::translate("MainWindow", "Random", nullptr));

#if QT_CONFIG(whatsthis)
        cb_peso->setWhatsThis(QCoreApplication::translate("MainWindow", "Defined by user or Randonly defined.", nullptr));
#endif // QT_CONFIG(whatsthis)
        btn_exec->setText(QCoreApplication::translate("MainWindow", "Executar", nullptr));
        btn_parar->setText(QCoreApplication::translate("MainWindow", "Parar", nullptr));
        btn_exec_2->setText(QCoreApplication::translate("MainWindow", "Exec_", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Sa\303\255da", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
