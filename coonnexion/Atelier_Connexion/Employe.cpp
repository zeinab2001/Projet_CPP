#include "Employe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Employe::Employe()
{
id=0; nom=" "; prenom=""; mail="";

}
Employe:: Employe(int id ,QString nom ,QString prenom,QString mail)
{this->id=id;this->nom=nom;this->prenom=prenom;this->mail=mail;}



int Employe::getid(){return id;}
QString Employe::  getnom(){return nom;}
QString Employe:: getprenom(){return prenom;}
QString Employe:: getmail(){return mail;}
void Employe::setid(int id){this->id=id;}
void Employe::setnom(QString nom){this->nom=nom;}
void Employe::setprenom(QString prenom){this->prenom=prenom;}
void Employe::setmail(QString mail){this->mail=mail;}
bool Employe;


bool Employe::ajouter()
{

QSqlQuery query;
QString id_string=QString::number(id);
query.prepare("INSERT INTO employe (id, nom, prenom, mail) "
              "VALUES (:id, :forename, :surname, :mail)");
query.bindValue(":id", id_string);
query.bindValue(":forename", nom);
query.bindValue(":surname", prenom);
query.bindValue(":mail", mail);
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
   model->setHeaderData(3, Qt::Horizontal,QObject:: tr("mail"));

    return model;
}


bool Employe::modifier(int id,QString nom,QString prenom,QString mail)
{ QSqlQuery query;
    QString res= QString::number(id);

    query.prepare("update evenement set id=:id,nom=:nom,prenom=:prenom,mail=:mail,");
    query.bindValue(":id",res);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);



    return    query.exec();
}
