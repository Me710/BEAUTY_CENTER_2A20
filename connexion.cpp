#include "connexion.h"
#include <exception>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

Connexion::Connexion() {}

bool Connexion::createConnect(){
    bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("SMART_BEAUTY_CENTER");
    db.setUserName("iheb");
    db.setPassword("iheb");
    db.open();
    test=true;

    return  test;
}

void Connexion::closeConnect(){
    db.close();
}
