/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPlainTextEdit *plainTextEdit;
    QGroupBox *groupBox_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QPlainTextEdit *plainTextEdit_2;
    QGroupBox *groupBox_3;
    QScrollArea *scrollArea_3;
    QWidget *scrollAreaWidgetContents_3;
    QPlainTextEdit *plainTextEdit_3;
    QPushButton *Save_Button;
    QPushButton *Save_As_Button;
    QPushButton *New_Button;
    QPushButton *Open_Button;
    QPushButton *Convert_Button;
    QLabel *label;
    QStatusBar *statusbar;
    QMenuBar *menubar;
    QMenu *menuHex_Bin_Char_Editor;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 90, 201, 431));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(0, 20, 201, 411));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 199, 409));
        plainTextEdit = new QPlainTextEdit(scrollAreaWidgetContents);
        plainTextEdit->setObjectName("plainTextEdit");
        plainTextEdit->setGeometry(QRect(0, 0, 201, 411));
        scrollArea->setWidget(scrollAreaWidgetContents);
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(250, 90, 201, 431));
        scrollArea_2 = new QScrollArea(groupBox_2);
        scrollArea_2->setObjectName("scrollArea_2");
        scrollArea_2->setGeometry(QRect(0, 20, 201, 411));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 199, 409));
        plainTextEdit_2 = new QPlainTextEdit(scrollAreaWidgetContents_2);
        plainTextEdit_2->setObjectName("plainTextEdit_2");
        plainTextEdit_2->setGeometry(QRect(0, 0, 201, 411));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(480, 90, 291, 431));
        scrollArea_3 = new QScrollArea(groupBox_3);
        scrollArea_3->setObjectName("scrollArea_3");
        scrollArea_3->setGeometry(QRect(0, 20, 291, 411));
        scrollArea_3->setWidgetResizable(true);
        scrollAreaWidgetContents_3 = new QWidget();
        scrollAreaWidgetContents_3->setObjectName("scrollAreaWidgetContents_3");
        scrollAreaWidgetContents_3->setGeometry(QRect(0, 0, 289, 409));
        plainTextEdit_3 = new QPlainTextEdit(scrollAreaWidgetContents_3);
        plainTextEdit_3->setObjectName("plainTextEdit_3");
        plainTextEdit_3->setGeometry(QRect(0, 0, 291, 411));
        scrollArea_3->setWidget(scrollAreaWidgetContents_3);
        Save_Button = new QPushButton(centralwidget);
        Save_Button->setObjectName("Save_Button");
        Save_Button->setGeometry(QRect(280, 10, 83, 29));
        Save_As_Button = new QPushButton(centralwidget);
        Save_As_Button->setObjectName("Save_As_Button");
        Save_As_Button->setGeometry(QRect(180, 10, 83, 29));
        New_Button = new QPushButton(centralwidget);
        New_Button->setObjectName("New_Button");
        New_Button->setGeometry(QRect(90, 10, 83, 29));
        Open_Button = new QPushButton(centralwidget);
        Open_Button->setObjectName("Open_Button");
        Open_Button->setGeometry(QRect(0, 10, 83, 29));
        Convert_Button = new QPushButton(centralwidget);
        Convert_Button->setObjectName("Convert_Button");
        Convert_Button->setGeometry(QRect(690, 50, 83, 29));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 40, 511, 21));
        MainWindow->setCentralWidget(centralwidget);
        groupBox->raise();
        groupBox_3->raise();
        Save_Button->raise();
        Save_As_Button->raise();
        New_Button->raise();
        Open_Button->raise();
        groupBox_2->raise();
        Convert_Button->raise();
        label->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        menubar->setDefaultUp(false);
        menuHex_Bin_Char_Editor = new QMenu(menubar);
        menuHex_Bin_Char_Editor->setObjectName("menuHex_Bin_Char_Editor");
        MainWindow->setMenuBar(menubar);

        menubar->addAction(menuHex_Bin_Char_Editor->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Hexadecimal", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Character", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Binary", nullptr));
        Save_Button->setText(QCoreApplication::translate("MainWindow", "Save", nullptr));
        Save_As_Button->setText(QCoreApplication::translate("MainWindow", "Save As", nullptr));
        New_Button->setText(QCoreApplication::translate("MainWindow", "New", nullptr));
        Open_Button->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        Convert_Button->setText(QCoreApplication::translate("MainWindow", "Convert", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Current file: ", nullptr));
        menuHex_Bin_Char_Editor->setTitle(QCoreApplication::translate("MainWindow", "Hex-Bin-Char Editor", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
