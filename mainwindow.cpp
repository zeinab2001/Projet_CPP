#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->lineEdit_id->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_client->setModel(c.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_ajouter_clicked()
{
    //recuperation des entrees
    int id_client=ui->lineEdit_id->text().toInt();//toInt converssion chaine->entier
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();


    Client c(id_client,nom,prenom,adresse);
    QString id_string=QString::number(id_client);
//||id_string.isEmpty()
    if(nom.isEmpty()||prenom.isEmpty()||adresse.isEmpty()||id_client==0)
    {
       QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Case Obligatoire!\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
    }

    else
        if(!(nom.contains(QRegExp("^[A-Za-z]+$")))||!(prenom.contains(QRegExp("^[A-Za-z]+$"))))
        {

            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Veuillez entrer une chaine!\n"
                                                 "Click Cancel to exit. "),QMessageBox::Cancel);
        }
    else
    {
           bool test=c.ajouter();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Ajout effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
        ui->tab_client->setModel(c.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Ajout non effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
}


}

void MainWindow::on_bt_supprimer_clicked()
{
    Client c1;
    c1.setid_client(ui->lineEdit_id_suppr->text().toInt());
    bool test=c1.supprimer(c1.getid_client());
    QMessageBox msgBox;

    if(test)
    {
        msgBox.setText("Suppression Avec Succes");
        ui->tab_client->setModel(c.afficher());
    }
    else
        msgBox.setText("Echec de suppression");
    msgBox.exec();

}

void MainWindow::on_bt_id_modif_clicked()
{
    int id_client=ui->lineEdit_id->text().toInt();//toInt converssion chaine->entier
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
<<<<<<< HEAD
    if(nom.isEmpty()||prenom.isEmpty()||adresse.isEmpty())
=======
    if(nom.isEmpty()||prenom.isEmpty()||adresse.isEmpty()||id_client==0)
>>>>>>> GestionClients
    {
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Case Obligatoire!\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
    }

    else
        if(!(nom.contains(QRegExp("^[A-Za-z]+$")))||!(prenom.contains(QRegExp("^[A-Za-z]+$"))))
        {
<<<<<<< HEAD
=======

            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Veuillez entrer une chaine!\n"
                                                 "Click Cancel to exit. "),QMessageBox::Cancel);
        }
    else
    {
>>>>>>> GestionClients

            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                     QObject::tr("Veuillez entrer une chaine!\n"
                                                 "Click Cancel to exit. "),QMessageBox::Cancel);
        }
else
        {
    Client c(id_client,nom,prenom,adresse);
    bool test=c.modifier(id_client);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("OK"),
                                 QObject::tr("Modification effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
        ui->tab_client->setModel(c.afficher());

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                                 QObject::tr("Modification non effectue.\n"
                                             "Click Cancel to exit. "),QMessageBox::Cancel);
}
}
}
