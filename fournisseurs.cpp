#include "fournisseurs.h"

Fournisseurs::Fournisseurs()
{

}
Fournisseurs::Fournisseurs(int ID, int Num, QString Email, QString Produit, QString Date_Arrivee, QString Nom){
    this->ID=ID;
    this->Num=Num;
    this->Email=Email;
    this->Produit=Produit;
    this->Date_Arrivee=Date_Arrivee;
    this->Nom=Nom;
}
bool Fournisseurs::ajouter(){
    QSqlQuery query;
    QString res1 = QString::number(ID);
    QString res2 = QString::number(Num);
    query.prepare("insert into Fournisseurs values (:id, :num, :produit, :date_arrivee, :email, :Nom, NULL)");
    query.bindValue(":id", res1);
    query.bindValue(":num", res2);
    query.bindValue(":email", Email);
    query.bindValue(":produit", Produit);
    query.bindValue(":date_arrivee", Date_Arrivee);
    query.bindValue(":Nom", Nom);
    return query.exec();
}
QSqlQueryModel* Fournisseurs::afficher(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date d'arrivée"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
bool Fournisseurs::supprimer(int id){
    QSqlQuery query;
    QString res = QString::number(id);
    query.prepare("delete from FOURNISSEURS where ID_FOURNISSEUR = :id");
    query.bindValue(":id", res);
    return query.exec();
}
bool Fournisseurs::modifier(){
    QSqlQuery query;
    QString res1 = QString::number(ID);
    QString res2 = QString::number(Num);
    query.prepare("update fournisseurs SET NUM_TEL_FOURNISSEUR = :num, PRODUIT_FOURNISSEUR = :produit , DATE_ARRIVEE = :date_arrivee, EMAIL_FOURNISSEUR = :email, NOM_FOURNISSEUR = :Nom where ID_FOURNISSEUR = :id");
    query.bindValue(":id", res1);
    query.bindValue(":num", res2);
    query.bindValue(":email", Email);
    query.bindValue(":produit", Produit);
    query.bindValue(":date_arrivee", Date_Arrivee);
    query.bindValue(":Nom", Nom);
    return query.exec();
}
QSqlQueryModel* Fournisseurs::trier(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs order by ID_FOURNISSEUR");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date d'arrivée"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
QSqlQueryModel* Fournisseurs::trierNom(){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs order by NOM_FOURNISSEUR");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date d'arrivée"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
QSqlQueryModel* Fournisseurs::chercher(QString field){
    QSqlQueryModel * model = new QSqlQueryModel();
    model->setQuery("select * from fournisseurs where (NOM_FOURNISSEUR) LIKE '%"+field+"%' ");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Numéro de téléphone"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Produit"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Date d'arrivée"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Email"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Nom"));

    return model;
}
