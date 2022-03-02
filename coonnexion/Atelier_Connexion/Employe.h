#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    bool ajouter();
    QSqlQueryModel*  afficher();
    bool supprimer(int);

    bool modifier(int,QString,QString);

    QSqlQueryModel * chercher_nom(QString);
    QSqlQueryModel * chercher_adresse(QString);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_nom();
    QSqlQueryModel * trier_age();

private :
    int id;
    QString nom,prenom;



};

#endif // Employe_H
