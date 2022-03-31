#include "client.h"
#include <QtDebug> //Erreur au niv d l'ajout
#include <QObject> //Erreur au niv QSqlQueryModel
//Constructeur par defaut
Client::Client()
{
id_client=0;
nom="";
prenom="";
adresse="";
}
//Constructeur parametre
Client::Client(int id_client,QString nom,QString prenom,QString adresse)
{
    this->id_client=id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;

}
//Getters Devolepement
int Client::getid_client(){return id_client;}
QString Client::getnom(){return nom;}
QString Client::getprenom(){return prenom;}
QString Client::getadresse(){return adresse;}
//Setters Devolepement
void Client::setid_client(int id_client){this->id_client=id_client;}
void Client::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
void Client::setadresse(QString adresse){this->adresse=adresse;}

bool Client::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id_client);
    query.prepare("INSERT INTO clients (id_client, nom, prenom,adresse) "
                  "VALUES (:id_client, :nom, :prenom, :adresse)");
    query.bindValue(":id_client", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);



    return query.exec();
}

QSqlQueryModel* Client::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

         model->setQuery("SELECT * FROM clients");
         model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant")); // Affichage mais avec un nom de colonnes diff des nom a la base
         model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
         model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
         model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));

    return model;
}

bool Client::supprimer(int id_client)
{

    QSqlQuery query;
    query.prepare("Delete from clients where id_client=:id_client");
    query.bindValue(":id_client",id_client);

    return query.exec();
}

bool Client::modifier(int id_client)
{
    QSqlQuery query;
    QString id_string=QString::number(id_client);
    query.prepare("update clients set id_client=:id_client, nom=:nom, prenom=:prenom,adresse=:adresse where id_client=:id_client ");
    query.bindValue(":id_client", id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);

    return query.exec();
}
