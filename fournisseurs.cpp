#include "fournisseurs.h"
#include <QtDebug> //Erreur au niv d l'ajout
#include <QObject> //Erreur au niv QSqlQueryModel
Fournisseurs::Fournisseurs()
{

}
Fournisseurs::Fournisseurs(int ID, int Num, QString Email, QString Produit, QString Date_Arrivee, QString Nom, int Etoiles){
    this->ID=ID;
    this->Num=Num;
    this->Email=Email;
    this->Produit=Produit;
    this->Date_Arrivee=Date_Arrivee;
    this->Nom=Nom;
    this->Etoiles=Etoiles;
}
bool Fournisseurs::ajouter(){
    QSqlQuery query;
    QString res1 = QString::number(ID);
    QString res2 = QString::number(Num);
    QString res3 = QString::number(Etoiles);
    query.prepare("insert into Fournisseurs values (:id, :num, :produit, :date_arrivee, :email, :Nom, :Etoiles)");
    query.bindValue(":id", res1);
    query.bindValue(":num", res2);
    query.bindValue(":email", Email);
    query.bindValue(":produit", Produit);
    query.bindValue(":date_arrivee", Date_Arrivee);
    query.bindValue(":Nom", Nom);
    query.bindValue(":Etoiles", res3);

    return query.exec();
}
QSqlQueryModel* Fournisseurs::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs");
    return model;
}
bool Fournisseurs::supprimer(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from FOURNISSEURS where ID_FOURNISSEUR = :id");
    query.bindValue(":id", res);
    return query.exec();
}
bool Fournisseurs::modifier(int id){
        QSqlQuery query;
        QString res1 = QString::number(id);
        QString res2 = QString::number(Num);
        QString res3 = QString::number(Etoiles);
        query.prepare("update fournisseurs SET NB_ETOILES  = :Etoiles,  NUM_TEL_FOURNISSEUR = :num, PRODUIT_FOURNISSEUR = :produit , DATE_ARRIVEE = :date_arrivee, EMAIL_FOURNISSEUR = :email, NOM_FOURNISSEUR = :Nom where ID_FOURNISSEUR = :id");
        query.bindValue(":id", res1);
        query.bindValue(":num", res2);
        query.bindValue(":email", Email);
        query.bindValue(":produit", Produit);
        query.bindValue(":date_arrivee", Date_Arrivee);
        query.bindValue(":Nom", Nom);
        query.bindValue(":Etoiles", res3);

        return query.exec();
}
QSqlQueryModel* Fournisseurs::trier(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs order by ID_FOURNISSEUR");
    return model;
}
QSqlQueryModel* Fournisseurs::trierNom(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs order by NOM_FOURNISSEUR");
    return model;
}
QSqlQueryModel* Fournisseurs::chercher(QString field){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs where (NOM_FOURNISSEUR) LIKE '%"+field+"%' ");
    return model;
}
