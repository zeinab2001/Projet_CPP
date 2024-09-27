#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Employe.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
       QString mail=ui->le_mail->text();
   Employe E(id,nom,prenom,mail);
   bool test=E.ajouter();

   QMessageBox msgbox;
   if (test)
      { msgbox.setText("ajout avec succes");
  ui->tab_etudiant->setModel(E.afficher());
   }
           else msgbox.setText("echec d'ajout");
   msgbox.exec();
}

void MainWindow::on_pb_supprimer_clicked()
{
Employe E1;E1.setid(ui->le_id_supp->text().toInt());
bool test=E1.supprimer(E1.getid());
QMessageBox msgbox;
if (test)
   { msgbox.setText("suppression avec succes");
ui->tab_etudiant->setModel(E.afficher());


}
}

}
