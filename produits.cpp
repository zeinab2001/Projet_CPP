#include "produits.h"
#include <QSystemTrayIcon>

produits::produits()
{

}
produits::produits(int a, int b, QString c, int d, int e, int f)
{
    id=a;
    prix=b;
    nom=c;
    quan=d;
    id_f=e;
    id_s=f;
}
QSqlQueryModel * produits::afficher()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM produits");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_produit"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("quantite"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("id_fournisseur"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("id_service"));

    return model;
}
bool produits::ajouter()
{
    QSqlQuery query;
    QString res = QString::number(id);
    QString res1 = QString::number(prix);
    QString res2 = QString::number(quan);
    QString res3 = QString::number(id_f);
    QString res4 = QString::number(id_s);
    query.prepare("INSERT INTO produits(id_produit,prix,nom,quantite,id_fournisseur,id_service)""VALUES (:id,:prix,:nom,:quan,:id_f,:id_s)");
    query.bindValue(":id",res);
    query.bindValue(":prix",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":quan",res2);
    query.bindValue(":id_f",res3);
    query.bindValue(":id_s",res4);
    return query.exec();
}
bool produits::supprimer(int id)
{
    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM produits WHERE id_produit = :id");
    query.bindValue(":id",res);
    return query.exec();
}
bool produits::modifier(int id_p)
{
    QSqlQuery query;
    QString res = QString::number(id_p);
    QString res1 = QString::number(prix);
    QString res2 = QString::number(quan);
    QString res3 = QString::number(id_f);
    QString res4 = QString::number(id_s);
    query.prepare("UPDATE produits SET prix=:prix,nom=:nom,quantite=:quan,id_fournisseur=:id_f,id_service=:id_s WHERE id_produit=:id_p");
    query.bindValue(":id_p",res);
    query.bindValue(":prix",res1);
    query.bindValue(":nom",nom);
    query.bindValue(":quan",res2);
    query.bindValue(":id_f",res3);
    query.bindValue(":id_s",res4);
    return query.exec();

}



QSqlQueryModel * produits::tri_prix()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM PRODUITS ORDER BY PRIX ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}

QSqlQueryModel * produits::tri_id()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM PRODUITS ORDER BY ID_produit ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}



QSqlQueryModel * produits::tri_nom()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * FROM PRODUITS ORDER BY nom ASC");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}



QSqlQueryModel *produits::displayClause(QString cls)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("SELECT * FROM PRODUITS " +cls);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("quan"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_f"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("id_s"));

    return model;
}

void produits::notification_ajoutProduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Produits ","Nouvau produit ajoutée ",QSystemTrayIcon::Information,15000);
}


void produits::notification_suppProduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Produits ","Produit supprime ",QSystemTrayIcon::Information,15000);
}

void produits::notification_modifProduit()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Produits ","Produit modifie ",QSystemTrayIcon::Information,15000);
}


void produits::notification_pdf()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des Produits ","pdf generee ",QSystemTrayIcon::Information,15000);
}



