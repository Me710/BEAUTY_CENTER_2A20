#ifndef PUBLICITES_H
#define PUBLICITES_H
#include<QString>
#include<QDate>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Publicites
{

public:
    Publicites(); //constructeur par defaut
    Publicites(int,QString,QDate,QString,int); //constr parametre
    int getID_P();
    QString getnom();
    QDate getdatep();
    QString getdescription();
    int getprix();
    void setID_P(int);
    void setnom(QString);
    void setdatep(QDate);
    void setdescription(QString);
    void setprix(int);
    bool ajouter();
    bool supprimer(int);
    QSqlQueryModel* afficher();
    bool modifier(int);
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_prix();
    QSqlQueryModel *tri_nom();
    QSqlQueryModel *rechercher(QString);

private:
    int ID_P;
    QString nom, description;
    QDate datep;
    int prix;

};

#endif // PUBLICITES_H
