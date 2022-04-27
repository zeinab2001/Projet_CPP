#include "EMPLOYEES.h"
#include <QDebug>
#include <QSqlDatabase>
#include <QString>
#include <QSqlQuery>
#include <QMessageBox>
EMPLOYEES::EMPLOYEES()
{
    id=0;
    nom="";
    prenom="";
    adresse="";
    age=0;
}
EMPLOYEES::EMPLOYEES(int id,QString nom,QString prenom,int age,QString adresse)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->age=age;
  this->adresse=adresse;
}

int EMPLOYEES::get_id(){return id;}
QString EMPLOYEES::get_nom(){return nom;}
QString EMPLOYEES::get_prenom(){return prenom ;}
QString EMPLOYEES::get_adresse(){return adresse;}
int EMPLOYEES::get_age(){return age;}



bool EMPLOYEES::ajouter()
{
QSqlQuery query;

QString res= QString::number(id);

query.prepare("INSERT INTO EMPLOYEES (ID_EMPLOYEE,NOM,PRENOM,ADRESSE,AGE) "
                    "VALUES (:id,:nom,:prenom,:adresse,age,)");

query.bindValue(":id",res);
query.bindValue(":nom",nom);
query.bindValue(":prenom",prenom);
query.bindValue(":adresse",adresse);
query.bindValue(":age",age);

return    query.exec();
}

QSqlQueryModel * EMPLOYEES::afficher()
{
  QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from EMPLOYEES");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
return model;
}

bool EMPLOYEES::supprimer(int id)
{
    QSqlQuery query;


    QString res= QString::number(id);

    query.prepare("Delete from EMPLOYEES where id= :id");
    query.bindValue(":id", res);
    return    query.exec();
}


bool EMPLOYEES::modifier(int id,QString nom,QString prenom,int age,QString adresse)
{ QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("update evenement set id=:id,nom=:nom,prenom=:prenom,age=:age,adresse=:adresse where id=:id");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":age",age);


    return    query.exec();

}

QSqlQueryModel * EMPLOYEES::chercher_nom(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM EMPLOYEES WHERE nom ='"+N+"' ;");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

    return model ;
}
QSqlQueryModel * EMPLOYEES::chercher_adresse(QString N)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM EMPLOYEES WHERE adresse ='"+N+"' ;");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

    return model ;
}
QSqlQueryModel * EMPLOYEES::trier_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM EMPLOYEES ORDER BY id asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

    return model;
}
QSqlQueryModel * EMPLOYEES::trier_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM EMPLOYEES ORDER BY nom asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));

    return model;
}
QSqlQueryModel * EMPLOYEES::trier_age()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * FROM EMPLOYEES ORDER BY age asc");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("adresse"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
    return model;
}
