#ifndef CONNECTION_H
#define CONNECTION_H
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlQuery>
class connection
{
    QSqlDatabase bd;
public:
    connection();
    bool creatconnection();
    void closeconnection();
};

#endif // CONNECTION_H
