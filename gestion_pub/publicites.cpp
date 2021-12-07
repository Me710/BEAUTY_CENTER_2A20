#include "publicites.h"
#include "connection.h"
#include<QSqlQuery>
#include<QDebug>
#include<QObject>
#include<QDateEdit>
#include<QDate>


Publicites::Publicites()
{
//ID_P=0; nom=" "; datep=" "; description=" "; prix=0;
}
Publicites::Publicites(int ID_P,QString nom,QDate datep,QString description,int prix)
{this->ID_P=ID_P; this->nom=nom; this->datep=datep; this->description=description; this->prix=prix;}
int Publicites::getID_P(){return ID_P;}
QString Publicites::getnom(){return nom;}
QDate Publicites::getdatep(){return datep;}
QString Publicites::getdescription(){return description;}
int Publicites::getprix(){return prix;}
void Publicites::setID_P(int ID_P){this->ID_P=ID_P;}
void Publicites::setnom(QString nom){this->nom=nom;}
void Publicites::setdatep(QDate datep){this->datep=datep;}
void Publicites::setdescription(QString description){this->description=description;}
void Publicites::setprix(int prix){this->prix=prix;}

bool Publicites::ajouter()
{
    QSqlQuery query;
    QString id_string=QString::number(ID_P);
    QString prix_string=QString::number(prix);
    query.prepare("INSERT INTO publicites(ID_P, nom, datep, description, prix) VALUES (:ID_P, :nom, :datep, :description, :prix)");
    query.bindValue(":ID_P",id_string);
    query.bindValue(":nom", nom);
    query.bindValue(":datep", datep);
    query.bindValue(":description", description);
    query.bindValue(":prix", prix_string);
    return query.exec();
}
bool Publicites::supprimer(int ID_P)
{
    QSqlQuery query;
    query.prepare("DELETE from publicites where ID_P=:ID_P");
    query.bindValue(0,ID_P);
    return query.exec();
}
QSqlQueryModel* Publicites::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM publicites");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_P"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("datep"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;
}
bool Publicites::modifier(int ID_P)

{        //Connection c;
         //c.createconnect();
         QSqlQuery query;
         query.prepare("UPDATE publicites set ID_P=:ID_P,nom=:nom,datep=:datep,description=:description,prix=:prix where ID_P=:ID_P");
         query.bindValue(":ID_P", ID_P);
         query.bindValue(":nom", nom);
         query.bindValue(":datep", datep);
         query.bindValue(":description", description);
         query.bindValue(":prix", prix);
         return query.exec();

}


QSqlQueryModel *Publicites::tri_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select *from publicites order by ID_P" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_P"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datep"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

 return model;

}
QSqlQueryModel *Publicites::tri_prix()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from publicites order by prix" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_P"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datep"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));


 return model;

}
QSqlQueryModel *Publicites::tri_nom()
{
    QSqlQueryModel *model=new QSqlQueryModel();

    model->setQuery("select * from publicites order by nom" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_P"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("datep"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("description"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;
}
QSqlQueryModel *Publicites::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM publicites WHERE ID_P  LIKE'%"+rech+"%' or nom  LIKE'%"+rech+"%' or datep  LIKE'%"+rech+"%' or prix  LIKE'%"+rech+"%' ");
    return model;
}

