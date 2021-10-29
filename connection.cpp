#include "connection.h"

connection::connection(){}
bool connection::creatconnection()
{
    bd = QSqlDatabase::addDatabase("QODBC");
bool test=false;
bd.setDatabaseName("test-bd");
bd.setUserName("system");
bd.setPassword("15021383");
if(bd.open()) test=true;
return test;
}

void connection::closeconnection(){bd.close();}
