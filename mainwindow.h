#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "client.h"
#include <QMainWindow>
#include "fournisseurs.h"
////////////
#include <QDesktopServices>
#include <QUrl>
#include <QVector>
#include<QMainWindow>
///
#include "arduino.h"

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

    //statisstiques
    void on_pushButton_clicked();

    void makePlot();
    void update_label();
    QVector<double> statistiques();
    ////////








    void on_pushButton_AjouterA_clicked();

    void on_pushButton_SupprimerA_clicked();

    void on_pushButton_ModifierA_clicked();

    void on_pushButton_2A_clicked();

    void on_pushButton_5A_clicked();

    void on_pushButton_ActualiserA_clicked();

    void on_pushButton_chercherA_clicked();

    void on_pushButton_3A_clicked();

    void on_pushButton_4A_clicked();

    void on_pb_imageA_clicked();

    void on_pushButton_6_sombreA_clicked();

    void on_pushButton_6_blancA_clicked();

private:
    Ui::MainWindow *ui;
    Client c;
    arduino A;
    QByteArray data;
     Fournisseurs FRN;
};
#endif // MAINWINDOW_H
