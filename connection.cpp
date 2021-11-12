#include "connection.h"

connection::connection(){}
bool connection::creatconnection()
{
    bd = QSqlDatabase::addDatabase("QODBC");
bool test=false;
bd.setDatabaseName("projet");
bd.setUserName("khalil");
bd.setPassword("khalil");
if(bd.open()) test=true;
return test;
}

void connection::closeconnection(){bd.close();}
