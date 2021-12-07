#include "commande.h"
#include <QSqlQuery>
#include <QtDebug>
#include<QString>
#include <QFile>
#include <QTextDocument>
#include<QTextStream>
#include<QIODevice>
#include<QDate>
#include <QSystemTrayIcon>
#include"connection.h"
Commande::Commande()
{

    id=0; prix=0 ;/* date_passage="2000/01/01"; date_livraison="2000/01/01";*/
}
    Commande::Commande(int id,int prix ,QString date_passage , QString date_livraison)
    {this->id=id; this->prix=prix; this->date_passage=date_passage; this->date_livraison=date_livraison;}


    int Commande::getid(){return id;}
    int Commande::getprix(){return prix;}
    QString Commande::getdate_passage(){return date_passage;}
   QString Commande::getdate_livraison(){return date_livraison;}
    void Commande::setid(int id){this->id=id;}
    void Commande::setprix(int prix){this->prix=prix;}
    void Commande::setdate_passage(QString date_passage){this->date_passage=date_passage;}
    void Commande::setdate_livraison(QString date_livraison){this->date_livraison=date_livraison;}

bool Commande::Ajouter()
{

QSqlQuery query;




          query.prepare("INSERT INTO SERVICES (id, prix,date_passage,date_livraison) "
                        "VALUES (:id, :prix , :date_passage , :date_livraison )");


          query.bindValue(":id", id);
          query.bindValue(":prix", prix);
          query.bindValue(":date_passage", date_passage);
           query.bindValue(":date_livraison", date_livraison);



       return   query.exec();


 }


void Commande::notification(QString cls)
{
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

    notifyIcon->show();
    notifyIcon->showMessage("NOTIFICATION",cls,QSystemTrayIcon::Information,15000);
  //  QSound newMessage(":/mixkit-positive-interface-beep-221.wav");
   // newMessage.play();
}





bool Commande::Supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE from Services where id=:id");
    query.bindValue(":id",id);
    return query.exec();
}


QSqlQueryModel* Commande::Afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM Services");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_passage"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_livraison"));

    return model;
}



bool Commande::Modifier()

{
         QSqlQuery query;
         query.prepare("UPDATE Services set id=:id, prix=:prix, date_passage=:date_passage, date_livraison=:date_livraison where id=:id");
         query.bindValue(":id", id);
         query.bindValue(":date_passage",date_passage);
         query.bindValue(":date_livraison",date_livraison);
         query.bindValue(":prix", prix);
         return query.exec();

}


QSqlQueryModel *Commande::tri_id()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SERVICES order by id" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_passage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_livraison"));


 return model;

}
QSqlQueryModel *Commande::tri_prix()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SERVICES order by prix" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_passage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_livraison"));


 return model;

}

QSqlQueryModel *Commande::tri_date()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from SERVICES order by date_passage " );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("date_passage"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("date_livraison"));


    return model;
}

QSqlQueryModel *Commande::rechercher(QString rech)
{
    QSqlQueryModel *model= new QSqlQueryModel();
    model->setQuery("SELECT * FROM services WHERE id LIKE'%"+rech+"%' or prix LIKE'%"+rech+"%' or date_passage LIKE'%"+rech+"%' or date_livraison LIKE'%"+rech+"%' ");
    return model;


}


void Commande::Write_on_file()
{
    QFile file("C:/Users/leila/Desktop/Agenda.txt");

          if(file.open(QIODevice::WriteOnly | QIODevice::Text))
          {
              QSqlQuery query;
              query.prepare("SELECT * from services ");
              query.bindValue(2,date_passage);
              query.bindValue(3,date_livraison);
              query.exec() ;

              while(query.next())
              {


                  QTextStream stream(&file);
                  stream << "date de passage : " << date_passage << " \n " ;
                  stream << "date de livraison : " << date_livraison << " \n " ;
                  stream << "*********************************************" << " \n " ;

}
          }


}
void Commande::Signal()
{
    QString date_passage = QDate::currentDate().toString("yyyy/dd/MM");
qDebug()<<date_passage;
    QSqlQuery query ;
    query.prepare("SELECT * from services where date_passage ='2021/23/11' ")  ;

    if(query.exec())
            {
                int count=0;
                while(query.next())
                {
                    count++;
                }
                if(count==1)
                {


                    notification("Une commande est prête");




                }
                if(count<1)


                    {
                    notification("Aucune commande est prête");


                    }

    if (count>1)
    {
    notification("plusieurs commandes  prête");


    }

    }

}
