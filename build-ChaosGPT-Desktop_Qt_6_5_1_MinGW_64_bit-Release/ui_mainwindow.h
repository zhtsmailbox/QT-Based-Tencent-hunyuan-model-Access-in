/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionChatGPT;
    QAction *actionDeepseek;
    QAction *actionChasoGPT;
    QAction *actionOther;
    QAction *actionNew_Contect;
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTextEdit *input;
    QPushButton *sendMsg;
    QTextEdit *output;
    QMenuBar *menubar;
    QMenu *menuGPT;
    QMenu *menuChange_source;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(729, 582);
        actionChatGPT = new QAction(MainWindow);
        actionChatGPT->setObjectName("actionChatGPT");
        actionDeepseek = new QAction(MainWindow);
        actionDeepseek->setObjectName("actionDeepseek");
        actionChasoGPT = new QAction(MainWindow);
        actionChasoGPT->setObjectName("actionChasoGPT");
        actionOther = new QAction(MainWindow);
        actionOther->setObjectName("actionOther");
        actionNew_Contect = new QAction(MainWindow);
        actionNew_Contect->setObjectName("actionNew_Contect");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        input = new QTextEdit(centralwidget);
        input->setObjectName("input");
        input->setMaximumSize(QSize(16777215, 100));

        gridLayout_2->addWidget(input, 6, 0, 1, 1);

        sendMsg = new QPushButton(centralwidget);
        sendMsg->setObjectName("sendMsg");
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sendMsg->sizePolicy().hasHeightForWidth());
        sendMsg->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(sendMsg, 6, 1, 1, 1);

        output = new QTextEdit(centralwidget);
        output->setObjectName("output");

        gridLayout_2->addWidget(output, 0, 0, 1, 2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 729, 20));
        menuGPT = new QMenu(menubar);
        menuGPT->setObjectName("menuGPT");
        menuChange_source = new QMenu(menubar);
        menuChange_source->setObjectName("menuChange_source");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuGPT->menuAction());
        menubar->addAction(menuChange_source->menuAction());
        menuGPT->addAction(actionNew_Contect);
        menuChange_source->addAction(actionChatGPT);
        menuChange_source->addAction(actionDeepseek);
        menuChange_source->addAction(actionChasoGPT);
        menuChange_source->addAction(actionOther);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionChatGPT->setText(QCoreApplication::translate("MainWindow", "ChatGPT", nullptr));
        actionDeepseek->setText(QCoreApplication::translate("MainWindow", "Deepseek", nullptr));
        actionChasoGPT->setText(QCoreApplication::translate("MainWindow", "ChasoGPT", nullptr));
        actionOther->setText(QCoreApplication::translate("MainWindow", "Other", nullptr));
        actionNew_Contect->setText(QCoreApplication::translate("MainWindow", "New Contect", nullptr));
        sendMsg->setText(QCoreApplication::translate("MainWindow", "Send", nullptr));
        menuGPT->setTitle(QCoreApplication::translate("MainWindow", "GPT", nullptr));
        menuChange_source->setTitle(QCoreApplication::translate("MainWindow", "Change source", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
