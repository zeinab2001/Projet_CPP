#ifndef FOURNISSEURS_H
#define FOURNISSEURS_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Fournisseurs
{
    int ID;
    int Num;
    QString Email;
    QString Produit;
    QString Date_Arrivee;
    QString Nom;
    int Etoiles;
public:
    Fournisseurs();
    Fournisseurs(int, int, QString, QString, QString, QString, int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int);
    QSqlQueryModel * trier();
    QSqlQueryModel * trierNom();
    QSqlQueryModel * chercher(QString);

};

#endif // FOURNISSEURS_H
