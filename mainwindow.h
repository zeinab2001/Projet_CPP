#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "fournisseurs.h"
#include <QMainWindow>
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
    void on_pushButton_Ajouter_clicked();

    void on_pushButton_Supprimer_clicked();

    void on_pushButton_Modifier_clicked();



    void on_pushButton_clicked();

    void on_pushButton_Actualiser_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_chercher_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pb_image_clicked();

    void on_pushButton_6_sombre_clicked();

    void on_pushButton_6_blanc_clicked();
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino



    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

private:
    Ui::MainWindow *ui;
    Fournisseurs FRN;
    QByteArray data; // variable contenant les données reçues

    Arduino A; // objet temporaire
};
#endif // MAINWINDOW_H
