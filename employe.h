#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <iostream>

using namespace std;

class Employe
{
public:
    QString cin;
    QString prenom;
    QString nom;
    QString courrier;
    int tel;
    double revenue;
    char sex;
    QString adresse;
    int jourNais;
    int moisNais;
    int anneeNais;

private:
     Employe(){}
    ~Employe(){}
    void setcin(QString n){cin=n;}
    void setprenom(QString n){prenom=n;}
    void setnom(QString n){nom=n;}

    QString get_cin(){return cin;}
    QString get_prenom(){return prenom;}
    QString get_nom(){return nom;}
};



#endif // EMPLOYE_H
