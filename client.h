#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class Client
{
public:
    Client();
    Client(QString,QString,int,QString,int,QString,QString);
    QString get_nom();
    QString get_prenom();
    QString get_adresseMail();
    QString get_adressePostale();
    QString get_sexe();
    int get_cin();
    int get_tel();
    void set_nom(QString);
    void set_prenom(QString);
    void set_adresseMail(QString);
    void set_adressePostale(QString);
    void set_sexe(QString);
    void set_cin(int);
    void set_tel(int);
    bool ajouter();
    bool modifier(QString,QString,int,QString,int,QString, QString);
    QSqlQueryModel * afficher();
    QSqlQueryModel * rechercher(const QString);
    bool supprimer(int);
    void chercher();

private:
    QString nom,prenom,adresseMail,adressePostale,sexe;
    int cin,tel;
};

#endif // CLIENT_H
