#include <QSqlQuery>
#include <QObject>
#include <QDebug>
#include "client.h"

Client::Client()
{
    nom="";
    prenom="";
    cin=0;
    adresseMail="";
    tel=0;
    adressePostale="";
}

Client::Client(QString nom,QString prenom,int cin,QString adresseMail,int tel,QString adressePostale, QString sexe){
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->adresseMail=adresseMail;
    this->tel=tel;
    this->adressePostale=adressePostale;
    this->sexe=sexe;
}

QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_adresseMail(){return adresseMail;}
QString Client::get_adressePostale(){return adressePostale;}
QString Client::get_sexe(){return sexe;}
int Client::get_cin(){return cin;}
int Client::get_tel(){return tel;}
void Client::set_nom(QString nom){this->nom=nom;}
void Client::set_prenom(QString prenom){this->prenom=prenom;}
void Client::set_adresseMail(QString adresseMail){this->adresseMail=adresseMail;}
void Client::set_adressePostale(QString adressePostale){this->adressePostale=adressePostale;}
void Client::set_sexe(QString sexe){this->sexe=sexe;}
void Client::set_cin(int cin){this->cin=cin;}
void Client::set_tel(int tel){this->tel=tel;}

bool Client::ajouter()
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString tel_string= QString::number(tel);
    query.prepare("INSERT INTO CLIENTS (NOM, PRENOM, CIN, ADRESSE_MAIL, TEL, ADRESSE_POSTALE, SEXE)"
                  "VALUES (:nom, :prenom, :cin, :adresseMail, :tel, :adressePostale, :sexe)");
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresseMail", adresseMail);
    query.bindValue(":tel", tel_string);
    query.bindValue(":adressePostale", adressePostale);
    query.bindValue(":sexe", sexe);

    return query.exec();
}

QSqlQueryModel * Client::afficher(){
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT* FROM CLIENTS");
    /*model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("CIN"));*/
    return model;
}

bool Client::supprimer(int cin){
    QSqlQuery query;
    query.prepare("Delete from CLIENTS where cin=:cin");
    query.bindValue(0, cin);

    return query.exec();
}
