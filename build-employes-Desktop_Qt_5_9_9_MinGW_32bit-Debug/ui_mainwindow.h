/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QGroupBox *groupBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_5;
    QPushButton *pushButton_3;
    QWidget *tab_5;
    QWidget *tab_2;
    QWidget *tab_3;
    QWidget *tab_4;
    QWidget *tab_6;
    QGroupBox *groupBox;
    QListView *listView;
    QScrollBar *horizontalScrollBar;
    QPushButton *pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1319, 600);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(85, 170, 255);\n"
"background-color: rgb(170, 0, 0);\n"
""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 711, 531));
        tabWidget->setStyleSheet(QLatin1String("background-color: rgb(170, 0, 0);\n"
"font: italic 15pt \"Monotype Corsiva\";"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        lineEdit = new QLineEdit(tab);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(250, 50, 113, 22));
        lineEdit_2 = new QLineEdit(tab);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(250, 100, 113, 22));
        lineEdit_3 = new QLineEdit(tab);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));
        lineEdit_3->setGeometry(QRect(250, 150, 113, 22));
        lineEdit_4 = new QLineEdit(tab);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));
        lineEdit_4->setGeometry(QRect(250, 210, 113, 22));
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 40, 171, 31));
        label->setStyleSheet(QLatin1String("font: italic 22pt \"Monotype Corsiva\";\n"
""));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 100, 111, 31));
        label_2->setStyleSheet(QLatin1String("\n"
"\n"
"font: italic 22pt \"Monotype Corsiva\";\n"
""));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(80, 160, 91, 31));
        label_3->setStyleSheet(QLatin1String("\n"
"\n"
"\n"
"font: italic 22pt \"Monotype Corsiva\";"));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(90, 210, 71, 41));
        label_4->setStyleSheet(QLatin1String("\n"
"\n"
"font: italic 22pt \"Monotype Corsiva\";"));
        pushButton = new QPushButton(tab);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(450, 60, 111, 41));
        pushButton->setStyleSheet(QLatin1String("color rgb(170, 85, 127qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0)));\n"
"border-color: rgb(170, 85, 127);\n"
"font: italic 15pt \"Monotype Corsiva\";"));
        pushButton_2 = new QPushButton(tab);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(450, 190, 101, 41));
        pushButton_2->setStyleSheet(QLatin1String("\n"
"font: italic 15pt \"Monotype Corsiva\";"));
        pushButton_4 = new QPushButton(tab);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(590, 130, 93, 41));
        groupBox_2 = new QGroupBox(tab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(30, 310, 591, 121));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 50, 56, 16));
        lineEdit_5 = new QLineEdit(groupBox_2);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));
        lineEdit_5->setGeometry(QRect(120, 50, 181, 22));
        pushButton_3 = new QPushButton(groupBox_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 50, 111, 41));
        pushButton_3->setStyleSheet(QLatin1String("\n"
"font: italic 15pt \"Monotype Corsiva\";"));
        tabWidget->addTab(tab, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        tabWidget->addTab(tab_5, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        tabWidget->addTab(tab_6, QString());
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(730, 110, 561, 301));
        groupBox->setStyleSheet(QLatin1String("\n"
"\n"
"font: italic 22pt \"Monotype Corsiva\";"));
        listView = new QListView(groupBox);
        listView->setObjectName(QStringLiteral("listView"));
        listView->setGeometry(QRect(20, 61, 521, 211));
        listView->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        horizontalScrollBar = new QScrollBar(groupBox);
        horizontalScrollBar->setObjectName(QStringLiteral("horizontalScrollBar"));
        horizontalScrollBar->setGeometry(QRect(20, 250, 521, 20));
        horizontalScrollBar->setOrientation(Qt::Horizontal);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(970, 440, 111, 41));
        pushButton_5->setStyleSheet(QLatin1String("\n"
"font: italic 15pt \"Monotype Corsiva\";"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1319, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Identifiant", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Pr\303\251nom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Ajouter", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Modifier", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "suppression", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "ID", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "Supprimer", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "gestion des employ\303\251s", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "tri.rechercher", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "PDF", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Excel", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Chat", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "gestions des commandes", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "Listes des employ\303\251s", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "EXCEL", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
