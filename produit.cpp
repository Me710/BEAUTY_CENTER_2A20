#include"produit.h"

Produit::Produit()
{
            code=0;
             nom="";
            prix=0;
            qualite=0;
            stock=0;
        }
Produit::Produit(int code,QString nom,float prix,float qualite,int stock)
{this->code=code;
this->nom=nom;
    this->prix=prix;
    this->qualite=qualite;
    this->stock=stock;
}
void Produit::ajouter()
{   //QSqlQuery query;
  //  QString res = QString ::numbre(id);


}

QSqlQueryModel * Produit ::afficher()
{
    //TO DO
}

bool Produit ::supprimer(int id)
{
    //to do
}
