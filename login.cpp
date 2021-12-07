#include "login.h"
#include <QString>
#include <QSqlQuery>

using namespace std;

Login::Login()
{
    username="admin";
    password="admin";
    code = "_";
}

Login::Login(QString username,QString password)
{
    this->username=username;
    this->password=password;
}

QSqlQueryModel * Login::afficherUsername()
{
    QSqlQueryModel * model =new QSqlQueryModel();
    QString query="select username from login";


    model->setQuery(query);

    return model;
}

bool Login::ajouterLogin()
{
    QSqlQuery query;

    query.prepare("insert into login values(:username,:password)");

    //Création des variables liées
    query.bindValue(":username",username);
    query.bindValue(":password",password);



    return query.exec();//exec() envoie la requete pour l'exécuter

}

bool Login::modifierLogin()
{
    QSqlQuery query;
    query.prepare("update login set password=:password where username=:username");

    query.bindValue(":username",username);
    query.bindValue(":password",password);

    return query.exec();
}
