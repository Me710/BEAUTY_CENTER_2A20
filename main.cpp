#include "mainwindow.h"

#include<string>
#include <QApplication>
#include<QMessageBox>
#include"connection.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connection c;
    bool test=c.creatconnection();
    MainWindow w;
    if(test)
    {
    w.show();
    QMessageBox::information(nullptr,QObject::tr("database is open'"),
      QObject::tr("connection successful.\n"
                  "clicl cancel to exit."),QMessageBox::Cancel);
   }
    else
        QMessageBox::critical(nullptr,QObject::tr("database is not open'"),
          QObject::tr("connection failled.\n"
                      "clicl cancel to exit."),QMessageBox::Cancel);
    return a.exec();
}

