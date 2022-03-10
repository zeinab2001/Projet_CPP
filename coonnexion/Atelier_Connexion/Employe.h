#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include<QSqlQueryModel>
#include<QSqlQuery>
class Employe
{
public:
    Employe();
    Employe(int,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString getmail ();
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setmail(QString);
    bool ajouter();
    QSqlQueryModel*  afficher();
    bool supprimer(int);

    bool modifier(int,QString,QString,QString);

    QSqlQueryModel * chercher_nom(QString);
    QSqlQueryModel * chercher_mail(QString);
    QSqlQueryModel * trier_id();
    QSqlQueryModel * trier_nom();


private :
    int id;
    QString nom,prenom,mail;



};

#endif // Employe_H
