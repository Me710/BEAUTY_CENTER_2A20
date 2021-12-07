#ifndef PRODUIT_H
#define PRODUIT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include<QtDebug>
#include<QObject>
#include<QTableView>
#include<QPainter>
using namespace std;

//class
class Produit{
private:
    int code;
    QString nom;
    int prix;
    int qualite;
    int stock;
   // int code_barre;
public:
    Produit();
    Produit(int ,QString,int,int,int);
   //methode
    bool ajouter(); //authentification
    QSqlQueryModel* afficher();
    bool update();  //authentification
    bool supprmier(int);   //authentification
    Produit PDF();
    QSqlQueryModel * recherche(int CODE);
    int gerer_code_barre(); //authentification
    Produit upload();   //authentification
   // void clearTable(QTableView * table);
    //void rechercher(QTableView *table, int x);
    QSqlQueryModel *tri_code();
     QSqlQueryModel *tri_prix();
      QSqlQueryModel *tri_stock();
    //getters
    int getcode(){return code;}
    QString getnom(){return nom ;}
    int getqualite(){return qualite;}
    int getprix(){return prix;}
    int getstock(){return stock;}
    //setters
    void setcode(int code){this->code=code;}
    void setnom(QString nom){this->nom=nom;}
    void setprix(float prix);
    void setqualite(float qualite){this->qualite=qualite;}
    void setstock(int stock){this->stock=stock;}
   QSqlQueryModel* afficher_code();
 //fonctionnalit"s de base realtives a l'entite






//~Produit();
};

#endif // PRODUIT_H
