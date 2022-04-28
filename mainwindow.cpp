#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include <QIntValidator>
#include "client.h"
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QVector>
#include "fournisseurs.h"

#include <QPieSlice>
#include <QPieSeries>
#include <QtCharts/QChartView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>

#include <QPrinter>
#include <QtPrintSupport/QPrinter>
#include <QPrintDialog>
#include <QTextDocument>
#include <QTextStream>
#include <QTextDocument>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->lineEdit_id->setValidator(new QIntValidator(0, 9999999, this));
ui->tab_client->setModel(c.afficher());

ui->tableViewAffichageA->setModel(FRN.afficher());
ui->lineEdit_id_2A->setValidator(new QIntValidator(0, 99999999, this));
ui->lineEdit_telA->setValidator(new QIntValidator(0, 99999999, this));

//////

int ret=A.connect_arduino(); // lancer la connexion à arduino
switch(ret){
case(0):qDebug()<< "arduino is available and connected to : "<< A.getArduino_port_name();
    break;
case(1):qDebug() << "arduino is available but not connected to :" <<A.getArduino_port_name();
   break;
case(-1):qDebug() << "arduino is not available";
}
 QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
 //le slot update_label suite à la reception du signal readyRead (reception des données).
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_bt_ajouter_clicked()
{
    //recuperation des entrees
    int id_client=ui->lineEdit_id->text().toInt();//toInt converssion chaine->entier
    int age=ui->lineEdit_age->text().toInt();//toInt converssion chaine->entier

    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();


    Client c(id_client,nom,prenom,adresse,age);
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
    int age=ui->lineEdit_age->text().toInt();//toInt converssion chaine->entier



    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString adresse=ui->lineEdit_adresse->text();
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
    Client c(id_client,nom,prenom,adresse,age);
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
void MainWindow::on_pushButton_7_clicked()
{
    Client c1;
        ui->tab_client->setModel(c.tri());
}


void MainWindow::on_bt_chercher_clicked()
{
    QString search=ui->lineEdit_id_suppr->text();
    ui->tab_client->setModel(c.rechercher(search));
}


void MainWindow::on_pushButton_pdf_clicked()
{
    QPrinter print;
        print.setPrinterName("imprimer");
        QPrintDialog dialog(&print, this); //(QPrinter *printer, QWidget *parent = nullptr)
        if(dialog.exec()==QDialog::Rejected) return;//signal non arrive
        ui->tab_client->render(&print);
}

void MainWindow::on_pushButton_clicked()
{
    MainWindow::makePlot();

}
QVector<double> MainWindow::statistiques()
{
    QSqlQuery q;
    QVector<double> stat(5);
    stat[0]=0;
    stat[1]=0;
    stat[2]=0;
    stat[3]=0;
    stat[4]=0;
    q.prepare("SELECT age FROM clients WHERE age<=18");
    q.exec();
    while (q.next())
    {
        stat[0]++;

    }
    q.prepare("SELECT age FROM clients WHERE 18<age and age<=25");
    q.exec();
    while (q.next())
    {
        stat[1]++;

    }
    q.prepare("SELECT age FROM clients WHERE 25<age and age<=30");
    q.exec();
    while (q.next())
    {
        stat[2]++;

    }
    q.prepare("SELECT age FROM clients WHERE 30<age and age<=40");
    q.exec();
    while (q.next())
    {
        stat[3]++;

    }
    q.prepare("SELECT age FROM clients WHERE 40<age ");
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
    bars1->setData(x3, MainWindow::statistiques());////fonction statistiques
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
    Ticks<<1<<2<<3<<4<<5<<6<<7;//////
    QVector<QString> labels;
    labels<<"0-18"<<"18-25"<<"25-30"<<"30-40"<<"40+"<<"ans";////////
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
    plotGradient.setColorAt(0, QColor(00, 50, 80));
    plotGradient.setColorAt(1, QColor(10, 20, 50));
    ui->customplot->setBackground(plotGradient);
    QLinearGradient axisRectGradient;
    axisRectGradient.setStart(0, 0);
    axisRectGradient.setFinalStop(0, 350);
    axisRectGradient.setColorAt(0, QColor(10, 50, 80));//
    axisRectGradient.setColorAt(1, QColor(0, 0, 30));
    ui->customplot->axisRect()->setBackground(axisRectGradient);

    ui->customplot->rescaleAxes();
    ui->customplot->xAxis->setRange(0, 7);
    ui->customplot->yAxis->setRange(0, 10);


}

void MainWindow::update_label()
{
    data=A.read_from_arduino();

    if(data=="1")

        ui->label_8->setText("ON"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON

    else if (data=="0")

        ui->label_8->setText("OFF");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON}

}

void MainWindow::on_pushButton_AjouterA_clicked()
{
    int id = ui->lineEdit_id_2A->text().toInt();
    int num = ui->lineEdit_telA->text().toInt();
    QString email = ui->lineEdit_emailA->text();
    QString produit = ui->lineEdit_produitA->text();
    QString date_arrivee = ui->lineEdit_email_2A->text();
    QString nom = ui->lineEdit_nom_2A->text();
    int etoiles = ui->lineEdit_etoilesA->text().toInt();
    Fournisseurs F(id, num, email, produit, date_arrivee, nom, etoiles);
    bool test = F.ajouter();

    if (test){
        ui->tableViewAffichageA->setModel(FRN.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Ajout effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Ajouter non effectué"),
                              QMessageBox::Cancel
                              );
    }
}

void MainWindow::on_pushButton_SupprimerA_clicked()
{
    int id = ui->lineEdit_id_suppressionA->text().toInt();
    bool test = FRN.supprimer(id);

    if (test){
        ui->tableViewAffichageA->setModel(FRN.afficher());
        QMessageBox::information(nullptr, QObject::tr("Database is open"),
                              QObject::tr("Suppression effectué"),
                              QMessageBox::Ok
                              );
    }else{
        QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                              QObject::tr("Suppression non effectué"),
                              QMessageBox::Cancel
                              );
    }
}

void MainWindow::on_pushButton_ModifierA_clicked()
{

    int id = ui->lineEdit_id_2A->text().toInt();
    int num = ui->lineEdit_telA->text().toInt();
    QString email = ui->lineEdit_emailA->text();
    QString produit = ui->lineEdit_produitA->text();
    QString date_arrivee = ui->lineEdit_email_2A->text();
    QString nom = ui->lineEdit_nom_2A->text();
    int etoiles = ui->lineEdit_etoilesA->text().toInt();
    Fournisseurs F(id, num, email, produit, date_arrivee, nom, etoiles);
    bool test = F.modifier(id);

    if (test){
            ui->tableViewAffichageA->setModel(F.afficher());
            QMessageBox::information(nullptr, QObject::tr("Database is open"),
                                  QObject::tr("Modification effectué"),
                                  QMessageBox::Ok
                                  );
        }else{
            QMessageBox::critical(nullptr, QObject::tr("Database is not open"),
                                  QObject::tr("Modification non effectué"),
                                  QMessageBox::Cancel
                                  );
        }
}

void MainWindow::on_pushButton_2A_clicked()
{
ui->tableViewAffichageA->setModel(FRN.trier());
}

void MainWindow::on_pushButton_5A_clicked()
{
    ui->tableViewAffichageA->setModel(FRN.trierNom());

}

void MainWindow::on_pushButton_ActualiserA_clicked()
{
    ui->tableViewAffichageA->setModel(FRN.afficher());

}

void MainWindow::on_pushButton_chercherA_clicked()
{
    QString rech_field = ui->lineEdit_nom_rechercheA->text();
    ui->tableViewAffichageA->setModel(FRN.chercher(rech_field));
}

void MainWindow::on_pushButton_3A_clicked()
{
    QString strStream;

                         QTextStream out(&strStream);

                         const int rowCount = ui->tableViewAffichageA->model()->rowCount();
                         const int columnCount = ui->tableViewAffichageA->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString();
                         out <<"<html>\n"
                               "<head>\n"
                                "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             << "<title>ERP - COMmANDE LIST<title>\n "
                             << "</head>\n"
                             "<body bgcolor=#ffffff link=#5000A0>\n"
                                "<h1 style=\"text-align: center;\"><strong> "+TT+"</strong></h1>"
                                +"<img src=C:\\Users\\maato\\Desktop\\Nouveau%20dossier\\fahed.pdf />"
                                "<h1 style=\"text-align: center;\"><strong> ****  LISTE DES FOURNISSEURS   **** </strong></h1>"


                             "<table style=\"text-align: center; font-size: 20px;\" border=1>\n "
                               "</br> </br>";
                         // headers
                         out << "<thead><tr bgcolor=#d6e5ff>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tableViewAffichageA->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tableViewAffichageA->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tableViewAffichageA->isColumnHidden(column)) {
                                     QString data =ui->tableViewAffichageA->model()->data(ui->tableViewAffichageA->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table>\n"
                             "</body>\n"
                             "</html>\n";

                         QTextDocument *document = new QTextDocument();
                         document->setHtml(strStream);

                         QPrinter printer;

                         QPrintDialog *dialog = new QPrintDialog(&printer, nullptr);
                         if (dialog->exec() == QDialog::Accepted) {
                             document->print(&printer);
                         }

                         delete document;
}

void MainWindow::on_pushButton_4A_clicked()
{
    //ui->stackedWidget_2->setCurrentIndex(1);
                QSqlQueryModel * model= new QSqlQueryModel();
                model->setQuery("select * from fournisseurs where NB_ETOILES < 5 ");
                float taille=model->rowCount();
                model->setQuery("select * from fournisseurs where NB_ETOILES  between 5 and 10 ");
                float taillee=model->rowCount();
                model->setQuery("select * from fournisseurs where NB_ETOILES >10 ");
                float tailleee=model->rowCount();
                float total=taille+taillee+tailleee;
                QString a=QString("fournisseur avec une mauvaise qualité de produit  . "+QString::number((taille*100)/total,'f',2)+"%" );
                QString b=QString("fournisseur avec une moyenne qualité de produit   .  "+QString::number((taillee*100)/total,'f',2)+"%" );
                QString c=QString("fournisseur avec une bonne qualité de produit  ."+QString::number((tailleee*100)/total,'f',2)+"%" );
                QPieSeries *series = new QPieSeries();
                series->append(a,taille);
                series->append(b,taillee);
                series->append(c,tailleee);
                if (taille!=0)
                {QPieSlice *slice = series->slices().at(0);
                    slice->setLabelVisible();
                    slice->setPen(QPen());}
                if ( taillee!=0)
                {
                    // Add label, explode and define brush for 2nd slice
                    QPieSlice *slice1 = series->slices().at(1);
                    //slice1->setExploded();
                    slice1->setLabelVisible();
                }
                if(tailleee!=0)
                {
                    // Add labels to rest of slices
                    QPieSlice *slice2 = series->slices().at(2);
                    //slice1->setExploded();
                    slice2->setLabelVisible();
                }
                // Create the chart widget
                QChart *chart = new QChart();
                // Add data to chart with title and hide legend
                chart->addSeries(series);
                chart->setTitle("distribution fournisseurs :Nombre Des fournisseurs "+ QString::number(total));
                chart->legend()->hide();
                // Used to display the chart
                QChartView *chartView = new QChartView(chart);
                chartView->setRenderHint(QPainter::Antialiasing);
                chartView->resize(1000,500);
                chartView->show();
}

void MainWindow::on_pb_imageA_clicked()
{
    QFileDialog dialog(this);
        dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
        dialog.setViewMode(QFileDialog::Detail);
        QString fileName =QFileDialog::getOpenFileName(this, tr("Open Images"), "C:/Users/Ben Arab/Desktop/GestClients", tr("Image Files (*.png *.jpg *.bmp)"));
    //to select and show the picture
        if (!fileName.isEmpty())
        {
            QImage image(fileName);
                ui->label_pic->setPixmap(QPixmap::fromImage(image));
        }
}

void MainWindow::on_pushButton_6_sombreA_clicked()
{
    QFile styleSheetFile("C:/Users/Ben Arab/Desktop/GestClients/Combinear.qss");
                styleSheetFile.open(QFile::ReadOnly);
                QString styleSheet = QLatin1String (styleSheetFile.readAll());
                MainWindow::setStyleSheet(styleSheet);
}

void MainWindow::on_pushButton_6_blancA_clicked()
{
    QFile styleSheetFile("C:/Users/Ben Arab/Desktop/GestClients/Integrid.qss");
                styleSheetFile.open(QFile::ReadOnly);
                QString styleSheet = QLatin1String (styleSheetFile.readAll());
                MainWindow::setStyleSheet(styleSheet);
}
