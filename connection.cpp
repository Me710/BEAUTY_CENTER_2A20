#include "connection.h"

connection::connection(){}

bool connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODC");
    bool test=false;
    db.setDatabaseName("test-bd");
    db.setUserName("Christian");
    db.setPassword("Christian");

    if(db.open()) test=true;

    return test;

}

void connection::closeconnection()
{
    db.close();
}
