#include "Employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Employe::Employe()
{
id=0; nom=" "; prenom="";

}
Employe::Employe(int id ,QString nom ,QString prenom)
{this->id=id;this->nom=nom;this->prenom=prenom;}
int Employe::getid(){return id;}
QString Employe::  getnom(){return nom;}
QString Employe:: getprenom(){return prenom;}
void Employe::setid(int id){this->id=id;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
bool Employe
::ajouter()
{

QSqlQuery query;
QString id_string=QString::number(id);
query.prepare("INSERT INTO employe (id, nom, prenom) "
              "VALUES (:id, :forename, :surname)");
query.bindValue(":id", id_string);
query.bindValue(":forename", nom);
query.bindValue(":surname", prenom);
return query.exec();

}
bool Employe::supprimer(int id)
{
    QSqlQuery query ;
    query.prepare("Delete from etudiant where id=:id");

    query.bindValue(0, id);
    return query.exec();

}
QSqlQueryModel*Employe::afficher()
{
   QSqlQueryModel * model=new QSqlQueryModel();
   model->setQuery("SELECT* FROM employee");
   model->setHeaderData(0, Qt::Horizontal, QObject:: tr("identifiant"));
   model->setHeaderData(1, Qt::Horizontal,QObject:: tr("nom"));
   model->setHeaderData(2, Qt::Horizontal,QObject:: tr("prenom"));

    return model;
}


bool Employe::modifier(int id,QString nom,QString prenom)
{ QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("update evenement set id=:id,nom=:nom,prenom=:prenom,");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);



    return    query.exec();
}
