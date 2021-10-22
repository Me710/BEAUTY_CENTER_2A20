#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <iostream>

using namespace std;

class Employe
{
public:
    int cin;
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
     Employe();//Constructeur par defaut
    ~Employe();//Destructeur

     //Mutateurs
    void set_cin(int cin);
    void set_prenom(QString prenom);
    void set_nom(QString nom);
    void set_courrier(QString courrier);

    //Acesseurs
    int get_cin();
    QString get_prenom();
    QString get_nom();
};



#endif // EMPLOYE_H
