#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "EMPLOYEES.h"
#include <QDialog>
#include <QObject>
#include <QMainWindow>
#include "arduino.h"
#include <QPainter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QUrl>

#include <QVector>

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

private slots:


    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();
    void on_tableView_clicked(const QModelIndex &index);


    void on_pushButton_tri_id_clicked();
    void on_pushButton_tri_nom_clicked();
    void on_pushButton_chercher_adresse_clicked();
    void on_pushButton_chercher_nom_clicked();
    void on_pushButton_pdf_clicked();
    void on_pb_modif_clicked();
    void makePlot();
    QVector<double> Statistique();
    void on_pushButton_statistique_clicked();







    void on_pushButton_tri_age_clicked();

    void update_label(); //slot permettant la mise à jour du label état de la lampe 1
        void on_pushButton_clicked();  //boutoun ON
        void on_pushButton_2_clicked();  //bouton OFF
        void on_pushButton_3_clicked(); //bouton +
        void on_pushButton_4_clicked(); //bouton -

private:
    Ui::MainWindow *ui;
    EMPLOYEES E;
    QByteArrayData;
    Arduino A ;


};



#endif//
