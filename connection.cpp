#include "connection.h"
#include <QMessageBox>
#include <QDebug>

connection::connection(){}

bool connection::createconnection(QString DbName,QString UName,QString Pwd)
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test=false;

    db.setDatabaseName(DbName);
    db.setUserName(UName);
    db.setPassword(Pwd);

    if(db.open()) test=true;

    return test;

}

void connection::closeconnection()
{
    db.close();
}

bool connection::Authentification(QString username,QString password)
{
    QSqlQuery query;


    query.prepare("select *from login where username=? and password=?");

    query.addBindValue(username);
    query.addBindValue(password);


    if(query.exec())
        {
            int count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                //ui->label_statuts->setText("Statuts: Mot de passe/Login correctes");
                //hide();
                //E.setModal(true);
                //E.exec();
                return true;
            }
            if(count<1)
            {
                //QMessageBox::warning(this,"Authentification échoué","Mot de passe/Login incorrectes");
                //ui->label_statuts->setText("Statuts: Mot de passe/Login incorrectes");
                return false;
            }

        }
        else
        {
            return false;
             //QMessageBox::warning(this,"Probleme d'envoie de la requete!","Une erreur s'est produit lors du traitement de la requete!");
        }
    return false;
}
