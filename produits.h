#ifndef PRODUITS_H
#define PRODUITS_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QSqlQueryModel>

class produits
{
public:
    produits();
    //Constructeurs

       produits(int, int , QString, int , int, int);
       //Getters
       int get_id(){return id;}
       int get_prix(){return prix;}
       QString get_nom(){return nom;}
       int get_quan(){return quan;}
       int get_idf(){return id_f;}
       int get_ids(){return id_s;}
       //Setters
       void set_id(int a){id=a;}
       void set_prix(int a){prix=a;}
       void set_nom(QString b){nom=b;}
       void set_quan(int a){quan=a;}
       void set_idf(int a){id_f=a;}
       void set_ids(int k){id_s=k;}

      //other functions
       QSqlQueryModel * afficher();
       bool ajouter();
       bool supprimer(int);
       bool modifier(int);
       QSqlQueryModel *tri_prix();
       QSqlQueryModel *tri_id();
       QSqlQueryModel *tri_nom();
       QSqlQueryModel *displayClause(QString cls);
       void notification_ajoutProduit();
       void notification_suppProduit();
       void notification_modifProduit();
       void notification_pdf();


private:
    int id;
    int prix;
    QString nom;
    int quan;
    int id_f;
    int id_s;


};

#endif // PRODUITS_H
