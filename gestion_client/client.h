#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(QString,QString,int,QString,int,QString,int);
    QString get_nom();
    QString get_prenom();
    QString get_adresseMail();
    QString get_sexe();
    int get_cin();
    int get_tel();
    int get_montantDepenser();
    void set_nom(QString);
    void set_prenom(QString);
    void set_adresseMail(QString);
    void set_montantDepenser(int);
    void set_sexe(QString);
    void set_cin(int);
    void set_tel(int);
    bool ajouter();
    bool modifier();
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher_cin(int);
    QSqlQueryModel * rechercher_tel(int);
    QSqlQueryModel * rechercher_montant(int);
    QSqlQueryModel * rechercher_cinTEL(int, int);
    QSqlQueryModel * rechercher_telMONTANT(int, int);
    QSqlQueryModel * rechercher_cinMONTANT(int, int);
    QSqlQueryModel * rechercher_global(int, int, int);
    QSqlQueryModel* afficher_cin();
    bool supprimer(int);
    void chercher();


private:
    QString nom,prenom,adresseMail,sexe;
    int cin,tel,montantDepenser;
};

#endif // CLIENT_H
