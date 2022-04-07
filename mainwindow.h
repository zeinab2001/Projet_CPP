#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>

////////////
#include <QDesktopServices>
#include <QUrl>
#include <QVector>
#include<QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_ajouter_clicked();

    void on_bt_supprimer_clicked();

    void on_bt_id_modif_clicked();

    void on_bt_chercher_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_pdf_clicked();

    void on_pushButton_clicked();

    void makePlot();

    QVector<double> statistiques();

private:
    Ui::MainWindow *ui;
    Client c;
};
#endif // MAINWINDOW_H
