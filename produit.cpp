#include"produit.h"

Produit::Produit()
{
            // code=0;
             nom="";
             prix=0;
             qualite=0;
             stock=0;
        }
Produit::Produit(int code,QString nom,int prix,int qualite,int stock)
{this->code=code;
this->nom=nom;
    this->prix=prix;
    this->qualite=qualite;
    this->stock=stock;
}
//ajouter un produit
bool Produit::ajouter()
{   QSqlQuery query;
    QString code_string=QString::number(code);
     QString prix_string=QString::number(prix);
      QString qualite_string=QString::number(qualite);
       QString stock_string=QString::number(stock);
    query.prepare("INSERT INTO PRODUITS (CODE,NOM,PRIX,QUALITE,STOCK) VALUES(:code, :nom, :prix,:qualite,:stock)");
      query.bindValue(":code",code);
      query.bindValue(":nom",nom);
      query.bindValue(":prix",prix);
      query.bindValue(":qualite",qualite);
     query.bindValue(":stock",stock);

return  query.exec();}


QSqlQueryModel * Produit::afficher()
{   QSqlQueryModel *model=new QSqlQueryModel();
         model->setQuery("SELECT * FROM PRODUITS");
return model;
}

bool Produit::supprmier(int code)
{
    QSqlQuery query;
    query.prepare("DELETE FROM PRODUITS where code=:code");
    query.bindValue(0,code);
return query.exec();
}
bool Produit::update()
{
    QSqlQuery  query;
query.prepare("UPDATE PRODUITS SET nom=:nom,prix=:prix,qualite=:qualite,stock=:stock WHERE code=:code");
query.bindValue(":code",code);
query.bindValue(":nom",nom);
query.bindValue(":prix",prix);
query.bindValue(":qualite",qualite);
query.bindValue(":stock",stock);
return query.exec();
}

QSqlQueryModel*  Produit ::afficher_code()
{QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select code from PRODUITS");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
return model;
}
