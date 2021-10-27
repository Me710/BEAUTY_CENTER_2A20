#include "employe.h"
#include <iostream>
#include <QString>
#include "connection.h"
#include <QSqlDatabase>

using namespace std;

Employe::Employe(){}
Employe::Employe(int cin,QString nom,QString prenom)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
}
Employe::Employe(int cin,QString nom,QString prenom,QString mail,long tel,QString fonction,char sexe,QString adresse,double salaire)
{
    this->cin=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->tel=tel;
    this->fonction=fonction;
    this->sexe=sexe;
    this->adresse=adresse;
    this->salaire=salaire;
}

Employe::~Employe(){}

//implementation des mutateurs
void Employe::set_cin(int cin){this->cin=cin;}
void Employe::set_prenom(QString prenom){this->prenom=prenom;}
void Employe::set_nom(QString nom){this->nom=nom;}
void Employe::set_mail(QString mail){this->mail=mail;}
void Employe::set_tel(long tel){this->tel=tel;}
void Employe::set_fonction(QString fonction){this->fonction=fonction;}
void Employe::set_sexe(char sexe){this->sexe=sexe;}
void Employe::set_adresse(QString adresse){this->adresse=adresse;}
void Employe::set_salaire(double salaire){this->salaire=salaire;}

//implementation des acesseurs
int Employe::get_cin(){return cin;}
QString Employe::get_prenom(){return prenom;}
QString Employe::get_nom(){return nom;}
QString Employe::get_mail(){return mail;}
long Employe::get_tel(){return tel;}
QString Employe::get_fonction(){return fonction;}
char Employe::get_sexe(){return sexe;}
QString Employe::get_adresse(){return adresse;}
double Employe::get_salaire(){return salaire;}

//implementation des CRUDs
bool Employe::ajouter()
{
    QSqlQuery query;
    //QString res = QString::number(cin);

    query.prepare("insert into employe (cin, nom, prenom)" "values(:cin, :nom, :prenom)");

    //Création des variables liées
    query.bindValue(":cin",cin);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);

    return query.exec();//exec() envoie la requete pour l'exécuter

}

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select *from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));

    return model;
}

bool Employe::supprimer(int cin)
{
    QSqlQuery query;
    //QString res=QString::number(cin);
    query.prepare("Delete from employe where cin=:cin");
    query.bindValue(":cin",cin);

    return query.exec();

}
