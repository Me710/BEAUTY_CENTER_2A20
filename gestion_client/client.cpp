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
    montantDepenser=0;
}

Client::Client(QString nom,QString prenom,int cin,QString adresseMail, int tel, QString sexe, int montantDepenser){
    this->nom=nom;
    this->prenom=prenom;
    this->cin=cin;
    this->adresseMail=adresseMail;
    this->tel=tel;
    this->sexe=sexe;
    this->montantDepenser=montantDepenser;
}

QString Client::get_nom(){return  nom;}
QString Client::get_prenom(){return prenom;}
QString Client::get_adresseMail(){return adresseMail;}
QString Client::get_sexe(){return sexe;}
int Client::get_montantDepenser(){return montantDepenser;}
int Client::get_cin(){return cin;}
int Client::get_tel(){return tel;}
void Client::set_nom(QString nom){this->nom=nom;}
void Client::set_prenom(QString prenom){this->prenom=prenom;}
void Client::set_adresseMail(QString adresseMail){this->adresseMail=adresseMail;}
void Client::set_sexe(QString sexe){this->sexe=sexe;}
void Client::set_montantDepenser(int montantDepenser){this->montantDepenser=montantDepenser;}
void Client::set_cin(int cin){this->cin=cin;}
void Client::set_tel(int tel){this->tel=tel;}

bool Client::ajouter()
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString tel_string= QString::number(tel);
    QString montantDepenser_string= QString::number(montantDepenser);
    query.prepare("INSERT INTO CLIENTS (NOM, PRENOM, CIN_C, ADRESSE_MAIL, TEL, SEXE, MONTANT_DEPENSER)"
                  "VALUES (:nom, :prenom, :cin, :adresseMail, :tel, :sexe, :montantDepenser)");
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresseMail", adresseMail);
    query.bindValue(":tel", tel_string);
    query.bindValue(":montantDepenser", montantDepenser_string);
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

QSqlQueryModel* Client::afficher_cin()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT CIN_C FROM CLIENTS");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN_C"));
    return model;
}

bool Client::supprimer(int cin){
    QSqlQuery query;
    query.prepare("Delete from CLIENTS where CIN_C=:cin");
    query.bindValue(0, cin);

    return query.exec();
}

bool Client::modifier()
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString tel_string= QString::number(tel);
    QString montantDepenser_string= QString::number(montantDepenser);
    query.prepare("UPDATE CLIENTS SET NOM=:nom, PRENOM=:prenom, CIN_C=:cin, ADRESSE_MAIL=:adresseMail, TEL=:tel, SEXE=:sexe, MONTANT_DEPENSER=:montantDepenser where CIN_C=:cin");
    query.bindValue(":cin", cin_string);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresseMail", adresseMail);
    query.bindValue(":tel", tel_string);
    query.bindValue(":montantDepenser", montantDepenser_string);
    query.bindValue(":sexe", sexe);

    return query.exec();
}

QSqlQueryModel * Client::rechercher_cin(int cin)
{
    QSqlQuery qry;
    qry.prepare("select * from CLIENTS where CIN_C=:cin");
    qry.bindValue(":cin",cin);
    qry.exec();
    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);

    return model;
}

QSqlQueryModel * Client::rechercher_tel(int tel)
{
    QSqlQuery qry;
    qry.prepare("select * from CLIENTS where TEL=:tel");
    qry.bindValue(":tel",tel);
    qry.exec();
    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);

    return model;
}

QSqlQueryModel * Client::rechercher_montant(int montant)
{
    QSqlQuery qry;
    qry.prepare("select * from CLIENTS where MONTANT_DEPENSER=:montant");
    qry.bindValue(":montant",montant);
    qry.exec();
    QSqlQueryModel *model= new QSqlQueryModel;
    model->setQuery(qry);

    return model;
}

QSqlQueryModel *Client:: rechercher_cinTEL(int cin, int tel)
{
    QSqlQuery *qry= new QSqlQuery();
    qry->prepare("select * from CLIENTS where CIN_C=:cin and TEL=:tel");
    qry->bindValue(":cin",cin);
    qry->bindValue(":tel",tel);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);

    return model;
}

QSqlQueryModel *Client:: rechercher_telMONTANT(int tel, int montant)
{
    QSqlQuery *qry= new QSqlQuery();
    qry->prepare("select * from CLIENTS where TEL=:tel and MONTANT_DEPENSER=:montant");
    qry->bindValue(":tel",tel);
    qry->bindValue(":montant",montant);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);

    return model;
}

QSqlQueryModel *Client:: rechercher_cinMONTANT(int cin, int montant)
{
    QSqlQuery *qry= new QSqlQuery();
    qry->prepare("select * from CLIENTS where CIN_C=:cin and MONTANT_DEPENSER=:montant");
    qry->bindValue(":cin",cin);
    qry->bindValue(":montant",montant);
    qry->exec();

    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery(*qry);

    return model;
}

QSqlQueryModel *Client:: rechercher_global(int cin, int tel, int montant)
{
    QSqlQuery *qry= new QSqlQuery();
        qry->prepare("select * from CLIENTS where CIN_C=:cin and TEL=:tel and MONTANT_DEPENSEr=:montant");
        qry->bindValue(":cin",cin);
        qry->bindValue(":tel",tel);
        qry->bindValue(":montant",montant);
        qry->exec();

        QSqlQueryModel *model = new QSqlQueryModel();
        model->setQuery(*qry);

        return model;
}
