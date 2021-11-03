#include "employe.h"
#include <iostream>
#include <QString>
#include "connection.h"
#include <QSqlDatabase>

using namespace std;

Employe::Employe(){}
Employe::Employe(int cin,QString nom,QString prenom,QString mail,int tel,QString fonction,QString sexe,QString adresse,int salaire,int age)
{
    this->cin_e=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->tel=tel;
    this->fonction=fonction;
    this->sexe=sexe;
    this->adresse=adresse;
    this->salaire=salaire;
    this->age=age;
    this->fonction=fonction;
}

Employe::~Employe(){}

//implementation des mutateurs
void Employe::set_cin(int cin_e){this->cin_e=cin_e;}
void Employe::set_prenom(QString prenom){this->prenom=prenom;}
void Employe::set_nom(QString nom){this->nom=nom;}
void Employe::set_mail(QString mail){this->mail=mail;}
void Employe::set_tel(int tel){this->tel=tel;}
void Employe::set_fonction(QString fonction){this->fonction=fonction;}
void Employe::set_sexe(QString sexe){this->sexe=sexe;}
void Employe::set_adresse(QString adresse){this->adresse=adresse;}
void Employe::set_salaire(int salaire){this->salaire=salaire;}

//implementation des acesseurs
int Employe::get_cin(){return cin_e;}
QString Employe::get_prenom(){return prenom;}
QString Employe::get_nom(){return nom;}
QString Employe::get_mail(){return mail;}
int Employe::get_tel(){return tel;}
QString Employe::get_fonction(){return fonction;}
QString Employe::get_sexe(){return sexe;}
QString Employe::get_adresse(){return adresse;}
int Employe::get_salaire(){return salaire;}

//implementation des CRUDs
bool Employe::ajouter()
{
    QSqlQuery query;
    //QString res_ = QString::number(cin);

    query.prepare("insert into employe (cin_e, nom, prenom, mail, adresse, tel, fonction, sexe, salaire, age)" "values(:cin_e, :nom, :prenom, :mail, :adresse, :tel, :fonction, :sexe, :salaire, :age)");

    //Création des variables liées
    query.bindValue(":cin_e",cin_e);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);
    query.bindValue(":sexe",sexe);
    query.bindValue(":salaire",salaire);
    query.bindValue(":age",age);
    query.bindValue(":fonction",fonction);

    /*query.bindValue(":fonction",fonction);*/

    return query.exec();//exec() envoie la requete pour l'exécuter

}

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select *from employe");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));
    /*model->setHeaderData(1,Qt::Horizontal,QObject::tr("Nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("Prenom"));*/

    return model;
}

bool Employe::supprimer(int cin_e)
{
    QSqlQuery query;
    //QString res=QString::number(cin);
    query.prepare("Delete from employe where cin_e=:cin_e");
    query.bindValue(":cin_e",cin_e);

    return query.exec();

}

QSqlQueryModel * Employe::rechercher(int cin_e)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    //QString res=QString::number(cin);
    QSqlQuery query;
    query.prepare("select *from employe where cin_e=:cin_e");
    query.bindValue(":cin_e",cin_e);
    query.exec();

    model->setQuery(query);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));

    return model;
}

bool Employe::modifier()
{
    QSqlQuery query;
    query.prepare("update employe set cin_e=:cin_e, nom=:nom, prenom=:prenom, mail=:mail, adresse=:adresse, tel=:tel, fonction=:fonction, sexe=:sex, salaire=:salaire, age=:age where cin_e=:cin_e");

    query.bindValue(":cin_e",cin_e);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":adresse",adresse);
    query.bindValue(":tel",tel);
    query.bindValue(":sexe",sexe);
    query.bindValue(":salaire",salaire);
    query.bindValue(":age",age);
    query.bindValue(":fonction",fonction);

    return query.exec();
}
