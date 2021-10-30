#include <QApplication>
#include <QMessageBox>
#include <QtDebug>
#include <QApplication>
#include <QSqlQuery>
#include "mainwindow.h"
#include "login.h"
#include "connexion.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.createConnect();
    Login w;
    if(test)
    {
        w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"), QMessageBox::Ok);

    }
    else    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    w.show();

    return a.exec();
}
