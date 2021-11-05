#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <iostream>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>

using namespace std;

class Employe
{
private:
    int cin_e;
    QString prenom;
    QString nom;
    QString mail;
    int tel;
    QString fonction;
    QString sexe;
    QString adresse;
    int salaire;
    int age;

    //double revenue;

public:
     Employe();//Constructeur par defaut
     Employe(int,QString,QString,QString,int,QString,QString,QString,int,int);
    ~Employe();//Destructeur

     //Mutateurs
    void set_cin(int);
    void set_prenom(QString);
    void set_nom(QString);
    void set_mail(QString);
    void set_tel(int);
    void set_fonction(QString);
    void set_sexe(QString);
    void set_adresse(QString);
    void set_salaire(int);


    //Acesseurs
    int get_cin();
    QString get_prenom();
    QString get_nom();
    QString get_mail();
    int get_tel();
    QString get_fonction();
    QString get_sexe();
    QString get_adresse();
    int get_salaire();

    //CRUDs
    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherValeur(QString valeur);
    bool supprimer(int);
    bool modifier();
    QSqlQueryModel * rechercher(int);
};



#endif // EMPLOYE_H
