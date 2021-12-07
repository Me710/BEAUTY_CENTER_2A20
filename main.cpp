#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connection.h"
#include "mainwindow.h"
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc,argv);
    QTranslator t;
    QStringList languages;
    languages << "anglais" << "arabic" << "espagnol" << "french";
    QString lang=QInputDialog::getItem(NULL,"Select Language","Language",languages);
    if (lang=="arabic")
    {
        t.load(":/arabic.qm");
    }else if(lang=="espagnol")
    {
        t.load(":/espagnol.qm");
    }else if(lang=="anglais")
    {
        t.load(":/anglais.qm");
    }if(lang !="french")
    {
        a.installTranslator(&t);
    }
    /*connection c;
    bool test;
    test = c.createconnection("system","system","system");*/

    MainWindow w;
     w.show();

    return a.exec();

}
