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
    int cin;
    QString prenom;
    QString nom;
    QString mail;
    long tel;
    QString fonction;
    char sexe;
    QString adresse;
    double salaire;
    int jourNais;
    int moisNais;
    int anneeNais;
    //double revenue;

public:
     Employe();//Constructeur par defaut
     Employe(int,QString,QString);
     Employe(int,QString,QString,QString,long,QString,char,QString,double);
    ~Employe();//Destructeur

     //Mutateurs
    void set_cin(int);
    void set_prenom(QString);
    void set_nom(QString);
    void set_mail(QString);
    void set_tel(int);
    void set_fonction(QString);
    void set_sexe(char);
    void set_adresse(QString);
    void set_salaire(double);


    //Acesseurs
    int get_cin();
    QString get_prenom();
    QString get_nom();
    QString get_mail();
    int get_tel();
    QString get_fonction();
    char get_sexe();
    QString get_adresse();
    double get_salaire();

    //CRUDs
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    QSqlQueryModel * rechercher(int);
    bool modifier(int);
};



#endif // EMPLOYE_H
