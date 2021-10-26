#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    connection c;
    bool test;
    test = c.createconnection();

    MainWindow w;
     w.show();
    if(test)
    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("conncetion sucessful.""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("conncetion failed.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

    return a.exec();

}
