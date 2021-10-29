#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
using namespace std;

//class
class Produit{
private:
    int code;
    QString nom;
    float prix;
    float qualite;
    int stock;
   // int code_barre;
public:
    Produit();
    Produit(int ,QString,float,float,int);
   //methode
    void ajouter(); //authentification
    void update();  //authentification
    void supprmier();   //authentification
    void trier_produit();
    Produit recherche_produit();
    Produit PDF();
    int gerer_code_barre(); //authentification
    Produit upload();   //authentification
//getters
    int getcode(){return code;}
    QString getnom(){return nom ;}
    float getqualite(){return qualite;}
    float getprix(){return prix;}
    int getstock(){return stock;}
    //setters
    void setcode(int code){this->code=code;}
    void setnom(QString nom){this->nom=nom;}
    void setprix(float prix);
    void setqualite(float qualite){this->qualite=qualite;}
    void setstock(int stock){this->stock=stock;}

 //fonctionnalit"s de base realtives a l'entite

    bool supprimer(int);
QSqlQueryModel * afficher();



~Produit();};
#endif // PRODUIT_H
