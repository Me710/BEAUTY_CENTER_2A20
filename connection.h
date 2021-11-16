#ifndef CONNECTION_H
#define CONNECTION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class connection
{
    QSqlDatabase db;
public:
    connection();
    bool createconnection(QString,QString,QString);
    void closeconnection();

    bool Authentification(QString,QString);
};

#endif // CONNECTION_H
