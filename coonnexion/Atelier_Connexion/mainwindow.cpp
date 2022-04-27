#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "EMPLOYEES.h"
#include <QMessageBox>
#include <QSqlQuery>
#include "qcustomplot.h"
#include <QVector>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
     ui(new Ui::MainWindow)
{

    int ret=A.connect_arduino(); //lancer la connexion a arduino
    switch(ret){
    case(0):qDebug()<<"arduino is available and connected to :" <<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available";

    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); //permet de lancer le slot update_label suite à la reception du signal readyRead(reception des données)
}






MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(E.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_clicked()
{
   EMPLOYEES e;
        int id = ui->le_id->text().toInt();
        QString nom= ui->le_nom->text();
        QString prenom= ui->le_prenom->text();
        int age= ui->lineEdit_age->text().toInt();
        QString adresse= ui->la_adresse->text();

     EMPLOYEES E (id,nom,prenom,age,adresse);
      bool test=E.ajouter();

      if(test)
    {
          ui->tableView->setModel(E.afficher());//refresh
          QMessageBox msgBox ;
   QMessageBox::information(this,"information","employee ajouté");
               ui->le_id->setText("");
               ui->le_nom->setText("");
               ui->le_prenom->setText("");
               ui->lineEdit_age->setText("");
               ui->la_adresse->setText("");
               ui->lineEdit_age->setText("");
  }

  else

  {
  QMessageBox msgBox ;
    msgBox.setText("employee non ajouté ");

  }
}


void MainWindow::on_pb_supprimer_clicked()
{
    int id = ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toInt();
    bool test=E.supprimer(id);
    if(test)
    {
        ui->tableView->setModel(E.afficher());//refresh
        QMessageBox msgBox ;
        QMessageBox::information(this,"information","employee supprimé");
    }

    else
    {
        QMessageBox::critical(nullptr, QObject::tr("employee non Supprimer"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
}


void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    ui->le_id->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),0)).toString());
    ui->le_nom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),1)).toString());
    ui->le_prenom->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),2)).toString());
    ui->la_adresse->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());
    ui->lineEdit_age->setText(ui->tableView->model()->data(ui->tableView->model()->index(ui->tableView->selectionModel()->currentIndex().row(),3)).toString());

}


void MainWindow::on_pb_modif_clicked()
{
    int id = ui->le_id->text().toInt();
    QString nom= ui->le_nom->text();
    QString prenom= ui->le_prenom->text();
    QString adresse= ui->la_adresse->text();
    int age= ui->lineEdit_age->text().toInt();


          bool test=E.modifier(id,nom,prenom,age,adresse);
             if (test)
             {
                  ui->tableView->setModel(E.afficher());
                  QMessageBox msgBox ;
           QMessageBox::information(this,"information","employee bien Modifié");
           ui->le_id->setText("");
           ui->le_nom->setText("");
           ui->le_prenom->setText("");
           ui->la_adresse->setText("");
           ui->lineEdit_age->setText("");

                }
}




void MainWindow::on_pushButton_tri_id_clicked()
{
    ui->tableView->setModel(E.trier_id());
}


void MainWindow::on_pushButton_tri_nom_clicked()
{
    ui->tableView->setModel(E.trier_nom());
}


void MainWindow::on_pushButton_tri_age_clicked()
{
    ui->tableView->setModel(E.trier_age());
}

void MainWindow::on_pushButton_chercher_adresse_clicked()
{
    QString valeur=ui->lineEdit_chercher_adresse->text();
        EMPLOYEES *c=new EMPLOYEES();
        ui->tableView->setModel(c->chercher_adresse(valeur));
}

void MainWindow::on_pushButton_chercher_nom_clicked()
{
    QString valeur=ui->lineEdit_chercher_nom->text();
        EMPLOYEES *c=new EMPLOYEES();
        ui->tableView->setModel(c->chercher_nom(valeur));
}


void MainWindow::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/ilyes/bureau/gestion des employés/coonnexion/Atelier_Connexion/Pdf.pdf");
    QPainter painter(&pdf);
    int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(1100,1200,"Liste Des Employee ");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        painter.drawRect(100,100,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(200,3300,"ID Employee");
        painter.drawText(1700,3300,"Nom Employee");
        painter.drawText(3200,3300,"Prenom Employee");
        painter.drawText(4700,3300,"Age Employee");
        painter.drawText(7800,3300,"Adresse Employee");


        QSqlQuery query;


        query.prepare("select * from EMPLOYEES");
        query.exec();
        while (query.next())
        {
            painter.drawText(200,i,query.value(0).toString());
            painter.drawText(1700,i,query.value(1).toString());
            painter.drawText(3200,i,query.value(2).toString());
            painter.drawText(4700,i,query.value(3).toString());
            painter.drawText(7800,i,query.value(4).toString());

           i = i + 500;
        }
        int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ilyes/bureau/gestion des employés/coonnexion/Atelier_Connexion/Pdf.pdf"));
                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                 painter.end();
            }
}


QVector<double> MainWindow::Statistique()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT age FROM EMPLOYEES WHERE age<=18");
    q.exec();
    while (q.next())
    {
        stat[0]++;
    }
    q.prepare("SELECT age FROM EMPLOYEES WHERE 18<age and age<=25");
    q.exec();
    while (q.next())
    {
        stat[1]++;
    }
    q.prepare("SELECT age FROM EMPLOYEES WHERE 25<age and age<=30");
    q.exec();
    while (q.next())
    {
        stat[2]++;
    }
    q.prepare("SELECT age FROM EMPLOYEES WHERE 30<age and age<=40");
    q.exec();
    while (q.next())
    {
        stat[3]++;
    }
    q.prepare("SELECT age FROM EMPLOYEES WHERE 40<age ");
    q.exec();
    while (q.next())
    {
        stat[4]++;
    }
    return stat;
}
void MainWindow::makePlot()
{
    // prepare data:
    QVector<double> x3(5), y3(20);
    for (int i=0; i<x3.size(); ++i)
    {
      x3[i] = i+1;

    }
    for (int i=0; i<y3.size(); ++i)
    {
      y3[i] = i+1;

    }

    QCPBars *bars1 = new QCPBars(ui->customplot->xAxis, ui->customplot->yAxis);
    bars1->setWidth(2/(double)x3.size());
    bars1->setData(x3, MainWindow::Statistique());
    bars1->setPen(Qt::NoPen);
    bars1->setBrush(QColor(200, 40, 60, 170));
    ui->customplot->replot();

    // move bars above graphs and grid below bars:
    ui->customplot->addLayer("abovemain", ui->customplot->layer("main"), QCustomPlot::limAbove);
    ui->customplot->addLayer("belowmain", ui->customplot->layer("main"), QCustomPlot::limBelow);
    ui->customplot->xAxis->grid()->setLayer("belowmain");
    ui->customplot->yAxis->grid()->setLayer("belowmain");

    // set some pens, brushes and backgrounds:
    QVector<double> Ticks;
    Ticks<<1<<2<<3<<4<<5<<6<<7;
    QVector<QString> labels;
    labels<<"0-18"<<"18-25"<<"25-30"<<"30-40"<<"40+"<<"ans";
    QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
    textTicker->addTicks(Ticks,labels);
    ui->customplot->xAxis->setTicker(textTicker);
    ui->customplot->xAxis->setSubTicks(false);
    ui->customplot->xAxis->setTickLength(0,4);
    ui->customplot->xAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->yAxis->setBasePen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setTickPen(QPen(Qt::white, 1));
    ui->customplot->xAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->yAxis->setSubTickPen(QPen(Qt::transparent, 1));
    ui->customplot->xAxis->setTickLabelColor(Qt::white);
    ui->customplot->yAxis->setTickLabelColor(Qt::white);
    ui->customplot->xAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setPen(QPen(QColor(140, 140, 140), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->yAxis->grid()->setSubGridPen(QPen(QColor(80, 80, 80), 1, Qt::DotLine));
    ui->customplot->xAxis->grid()->setSubGridVisible(true);
    ui->customplot->yAxis->grid()->setSubGridVisible(true);
    ui->customplot->xAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->yAxis->grid()->setZeroLinePen(Qt::NoPen);
    ui->customplot->xAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    ui->customplot->yAxis->setUpperEnding(QCPLineEnding::esSpikeArrow);
    QLinearGradient plotGradient;
    plotGradient.setStart(0, 0);
    plotGradient.setFinalStop(0, 350);
    plotGradient.setColorAt(0, QColor(10, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}

void MainWindow::on_pushButton_statistique_clicked()
{
    MainWindow::makePlot();
}


void MainWindow::update_label()
{
    data=A.read_from_arduino();
    if (data=="1")
        ui->label_3->setText("ON"); //si les donnes reçues de arduino via la liaison série sont égales a 1
    //alors afficher ON
    else if(data=="0")
        ui->label_3->setText("OFF");
}

void MainWindow::on_pushButton_clicked() //implémentation du slot bouton on
{
    A.write_to_arduino("1"); //envoyer 1 à arduino
}
void MainWindow::on_pushButton_2_clicked() //implémentation du slot bouton off
   A.write_to_arduino("0"); //envoyer 0 a arduino


