/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *inputUser;
    QPushButton *btnAddUser;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnMutuals;
    QPushButton *btnFollow;
    QComboBox *comboUserB;
    QComboBox *comboUserA;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnInfluencers;
    QPushButton *btnSuggestions;
    QTextEdit *outputBox;
    QLabel *label;
    QLabel *label_2;
    QPushButton *btnRemoveUser;
    QPushButton *btnUnfollow;
    QPushButton *btnSave;
    QPushButton *btnLoad;
    QGraphicsView *graphView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(910, 632);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        widget = new QWidget(centralwidget);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(150, 140, 390, 308));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        inputUser = new QLineEdit(widget);
        inputUser->setObjectName("inputUser");

        horizontalLayout->addWidget(inputUser);

        btnAddUser = new QPushButton(widget);
        btnAddUser->setObjectName("btnAddUser");

        horizontalLayout->addWidget(btnAddUser);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnMutuals = new QPushButton(widget);
        btnMutuals->setObjectName("btnMutuals");

        horizontalLayout_2->addWidget(btnMutuals);

        btnFollow = new QPushButton(widget);
        btnFollow->setObjectName("btnFollow");

        horizontalLayout_2->addWidget(btnFollow);

        comboUserB = new QComboBox(widget);
        comboUserB->setObjectName("comboUserB");

        horizontalLayout_2->addWidget(comboUserB);

        comboUserA = new QComboBox(widget);
        comboUserA->setObjectName("comboUserA");

        horizontalLayout_2->addWidget(comboUserA);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnInfluencers = new QPushButton(widget);
        btnInfluencers->setObjectName("btnInfluencers");

        horizontalLayout_3->addWidget(btnInfluencers);

        btnSuggestions = new QPushButton(widget);
        btnSuggestions->setObjectName("btnSuggestions");

        horizontalLayout_3->addWidget(btnSuggestions);


        verticalLayout->addLayout(horizontalLayout_3);

        outputBox = new QTextEdit(widget);
        outputBox->setObjectName("outputBox");

        verticalLayout->addWidget(outputBox);


        verticalLayout_2->addLayout(verticalLayout);

        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 40, 381, 61));
        QFont font;
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"font-weight: bold;\n"
"font-size: 22px;\n"
""));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(160, 110, 201, 31));
        label_2->setFont(font);
        label_2->setStyleSheet(QString::fromUtf8("color: #333333;\n"
"font-weight: bold;\n"
"font-size: 18px;\n"
""));
        btnRemoveUser = new QPushButton(centralwidget);
        btnRemoveUser->setObjectName("btnRemoveUser");
        btnRemoveUser->setGeometry(QRect(530, 150, 80, 24));
        btnUnfollow = new QPushButton(centralwidget);
        btnUnfollow->setObjectName("btnUnfollow");
        btnUnfollow->setGeometry(QRect(530, 190, 80, 24));
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName("btnSave");
        btnSave->setGeometry(QRect(690, 50, 80, 24));
        btnLoad = new QPushButton(centralwidget);
        btnLoad->setObjectName("btnLoad");
        btnLoad->setGeometry(QRect(690, 90, 80, 24));
        graphView = new QGraphicsView(centralwidget);
        graphView->setObjectName("graphView");
        graphView->setGeometry(QRect(600, 350, 256, 192));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 910, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        inputUser->setText(QString());
        btnAddUser->setText(QCoreApplication::translate("MainWindow", "Add User", nullptr));
        btnMutuals->setText(QCoreApplication::translate("MainWindow", "Show Mutual Followers ", nullptr));
        btnFollow->setText(QCoreApplication::translate("MainWindow", "Follow", nullptr));
        btnInfluencers->setText(QCoreApplication::translate("MainWindow", "Top Influenxers", nullptr));
        btnSuggestions->setText(QCoreApplication::translate("MainWindow", "Suggest Friends", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Instagram Social Graph Analyzer", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Buiil using c++ and qt", nullptr));
        btnRemoveUser->setText(QCoreApplication::translate("MainWindow", "Remove User", nullptr));
        btnUnfollow->setText(QCoreApplication::translate("MainWindow", "Unfollow", nullptr));
        btnSave->setText(QCoreApplication::translate("MainWindow", "Save Graph", nullptr));
        btnLoad->setText(QCoreApplication::translate("MainWindow", "Load Graph", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
