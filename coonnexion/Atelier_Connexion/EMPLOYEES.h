#ifndef EMPLOYEES_H
#define EMPLOYEES_H

#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>


class EMPLOYEES
{
public:
    EMPLOYEES();
    EMPLOYEES(int,QString,QString,int,QString);
    int get_id();
    QString get_nom();
    QString get_prenom();
    int get_age();
    QString get_adresse();



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier(int,QString,QString,int,QString);

    QSqlQueryModel * chercher_nom(QString);
    QSqlQueryModel * chercher_adresse(QString);
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_age();
    QSqlQueryModel * trier_id();


private:
    QString nom,prenom,adresse;
    int id,age;
};

#endif // EMPLOYEES_H
