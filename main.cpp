#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    /*connection c;
    bool test;
    test = c.createconnection("system","system","system");*/

    MainWindow w;
     w.show();

    return a.exec();

}
