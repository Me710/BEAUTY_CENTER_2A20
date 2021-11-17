#include "employe.h"
#include <iostream>
#include <QString>
#include "connection.h"
#include <QSqlDatabase>
#include "dialog_employes.h"
#include <array>
#include <cstddef>

using namespace std;

//CONSTRUCTEUR PAR DEFAUT
Employe::Employe()
{
    cin_e=000001;
    nom="admin";
    prenom="admin";
    mail="nebotchristian6@gmail.com";
    tel=50892332;
    fonction="Gerant";
    sexe ="Homme";
    adresse = "Ariana";
    salaire = 30000;
    age=30;
}

//CONSTRUCTEUR PARAMETRE
Employe::Employe(int cin,QString nom,QString prenom,QString mail,int tel,QString fonction,QString sexe,QString adresse,int salaire,int age)
{
    this->cin_e=cin;
    this->nom=nom;
    this->prenom=prenom;
    this->mail=mail;
    this->tel=tel;
    this->sexe=sexe;
    this->adresse=adresse;
    this->salaire=salaire;
    this->age=age;
    this->fonction=fonction;
}

Employe::~Employe()
{
    /*DEST*/
}

//LES MUTATEURS------------------------------------------------------------------------------------

void Employe::set_cin(int cin_e){this->cin_e=cin_e;}
void Employe::set_prenom(QString prenom){this->prenom=prenom;}
void Employe::set_nom(QString nom){this->nom=nom;}
void Employe::set_mail(QString mail){this->mail=mail;}
void Employe::set_tel(int tel){this->tel=tel;}
void Employe::set_fonction(QString fonction){this->fonction=fonction;}
void Employe::set_sexe(QString sexe){this->sexe=sexe;}
void Employe::set_adresse(QString adresse){this->adresse=adresse;}
void Employe::set_salaire(int salaire){this->salaire=salaire;}

//LES ACESSEURS--------------------------------------------------------------------------------------

int Employe::get_cin(){return cin_e;}
QString Employe::get_prenom(){return prenom;}
QString Employe::get_nom(){return nom;}
QString Employe::get_mail(){return mail;}
int Employe::get_tel(){return tel;}
QString Employe::get_fonction(){return fonction;}
QString Employe::get_sexe(){return sexe;}
QString Employe::get_adresse(){return adresse;}
int Employe::get_salaire(){return salaire;}

//--------------------------LES CRUDs-------------------------------------------------------------------

//AJOUTER-----------------------------------------------------------------------------------------------

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


    return query.exec();//exec() envoie la requete pour l'exécuter

}

//AFFICHER--------------------------------------------------------------------------------------

QSqlQueryModel * Employe::afficher()
{
    QSqlQueryModel * model =new QSqlQueryModel();

    model->setQuery("select *from employe");
   // model->setHeaderData(0,Qt::Horizontal,QObject::tr("CIN"));


    return model;
}

//SUPPRIMER--------------------------------------------------------------------------------------

bool Employe::supprimer(int cin_e)
{
    QSqlQuery query;
    //QString res=QString::number(cin);
    query.prepare("Delete from employe where cin_e=:cin_e");
    query.bindValue(":cin_e",cin_e);

    return query.exec();

}

//RECHERCHER--------------------------------------------------------------------------------------

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

//MODIFIER--------------------------------------------------------------------------------------

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

//AFFICHER_VALEUR----------------------------------------------------------------------------------

QSqlQueryModel * Employe::afficherValeur(QString valeur)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString ch1="select ";
    QString query=" from employe";
    query=ch1+valeur+query;


    model->setQuery(query);

    return model;
}

//TRIER---------------------------------------------------------------------------------------------

QSqlQueryModel * Employe::trier(QString valeur)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString query="select *from employe ORDER by ";
    query=query+valeur;

    model->setQuery(query);

    return model;
}

//FILTRER--------------------------------------------------------------------------------------

QSqlQueryModel * Employe::afficherFiltrer(array<int,8> tab)
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString tabVal[8]={"prenom","fonction","adresse","tel","mail","salaire","age","sexe"};
    QString ch[8]={"","","","","","","",""};
    QString query="select ";
    //int j=0;

    if(tab.at(0)==1){query+="prenom, ";}
    if(tab.at(1)==1){query+="fonction, ";}
    if(tab.at(2)==1){query+="adresse, ";}
    if(tab.at(3)==1){query+="tel, ";}
    if(tab.at(4)==1){query+="mail, ";}
    if(tab.at(5)==1){query+="salaire, ";}
    if(tab.at(6)==1){query+="age, ";}
    if(tab.at(7)==1){query+="sexe, ";}

    query=query+"cin_e,nom from employe";

    qDebug()<<query;

    model->setQuery(query);

    return model;
}

//CHAINE VALIDE--------------------------------------------------------------------------------------

bool Employe::ChaineValide(QString chaine)
{
    int i=0;
    while(i<chaine.size())
    {
        if(chaine[i]=='&' || chaine[i]=='~' || chaine[i]=='"' || chaine[i]=='#' || chaine[i]=='r'||chaine[i]=='='||chaine[i]==':' ||
                chaine[i]=='-' || chaine[i]=='[' || chaine[i]=='|' ||chaine[i]=='_'||chaine[i]=='/'||chaine[i]=='!'||chaine[i]=='+'||
                chaine[i]=='1' ||chaine[i]=='2' ||chaine[i]=='3' ||chaine[i]=='4' ||chaine[i]=='5' ||chaine[i]=='6' ||chaine[i]==']'||
                chaine[i]=='7' ||chaine[i]=='8' ||chaine[i]=='9' ||chaine[i]=='0' ||chaine[i]=='@' ||chaine[i]==')' ||chaine[i]=='}'||
                chaine[i]=='%' ||chaine[i]=='*' ||chaine[i]=='?' ||chaine[i]==',' ||chaine[i]==';' ||chaine[i]=='.')
        {
            return false;
            break;
        }
        i++;
    }

    return true;
}
