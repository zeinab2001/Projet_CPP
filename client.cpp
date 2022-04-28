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
Client::Client(int id_client,QString nom,QString prenom,QString adresse,int age)
{
    this->id_client=id_client;
    this->nom=nom;
    this->prenom=prenom;
    this->adresse=adresse;
    this->age=age;

}
//Getters Devolepement
int Client::getid_client(){return id_client;}
int Client::getage(){return age;}

QString Client::getnom(){return nom;}
QString Client::getprenom(){return prenom;}
QString Client::getadresse(){return adresse;}
//Setters Devolepement
void Client::setid_client(int id_client){this->id_client=id_client;}
void Client::setage(int age){this->age=age;}

void Client::setnom(QString nom){this->nom=nom;}
void Client::setprenom(QString prenom){this->prenom=prenom;}
void Client::setadresse(QString adresse){this->adresse=adresse;}

bool Client::ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id_client);
    QString age_string=QString::number(age);


    query.prepare("INSERT INTO clients (id_client, nom, prenom,adresse,age) "
                  "VALUES (:id_client, :nom, :prenom, :adresse, :age)");
    query.bindValue(":id_client", id_string);
    query.bindValue(":age", age);

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
         model->setHeaderData(4, Qt::Horizontal, QObject::tr("Age"));


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
    QString age_string=QString::number(age);

    query.prepare("update clients set id_client=:id_client, nom=:nom, prenom=:prenom,adresse=:adresse,age=:age where id_client=:id_client ");
    query.bindValue(":id_client", id_string);
    query.bindValue(":age", age_string);

    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);

    return query.exec();
}

QSqlQueryModel * Client::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM clients ORDER BY id_client");
        return model;
}

QSqlQueryModel * Client::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from clients where  id_client='"+rech+"' ");

        return model ;

}
