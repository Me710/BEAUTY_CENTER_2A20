#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
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
    Connection c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    return a.exec();
}
