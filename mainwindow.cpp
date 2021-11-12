#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QMessageBox>
#include<QDebug>
#include<QIntValidator>
#include <QTableWidget>
#include <QRegularExpressionValidator>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_prix->setValidator(new QIntValidator(0,9999, this));
    ui->tab_Commande->setModel(C.Afficher());
#define NOM_RX "^([0-9]+[,.]?[ ]?|[0-9]+['-]?)+$"
 QRegularExpression rxNom(NOM_RX);
 QRegularExpressionValidator *valiNom= new QRegularExpressionValidator(rxNom,this);
 ui->le_id->setValidator(valiNom);
 ui->le_prix->setValidator(valiNom);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    int id=ui->le_id->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QDate date_p=ui->le_date_passage->date();
   QString date_passage=date_p.toString("yyyy/dd/MM");
   QDate date_l=ui->le_date_livraison->date();
    QString date_livraison= date_l.toString("yyyy/dd/MM");





    Commande C (id,prix,date_passage,date_livraison);

bool test=C.Ajouter ();
    QMessageBox msgbox;

       if(test)

           {msgbox.setText("Ajout avec succes.");
           ui->tab_Commande->setModel(C.Afficher());
                      ui->le_id->setText("");
                      ui->le_prix->setText("");


           }

           else

               msgbox.setText("Echec d'ajout");

           msgbox.exec();


    }





void MainWindow::on_pb_Modifier_clicked()
{
    int id=ui->le_id_Modifier->text().toInt();
    int prix=ui->le_prix_Modifier->text().toInt();
    QDate date_p=ui->le_datep_Modifier->date();
   QString date_passage=date_p.toString("yyyy/dd/MM");
   QDate date_l=ui->le_datel_Modifier->date();
    QString date_livraison= date_l.toString("yyyy/dd/MM");

        Commande C(id,prix,date_passage,date_livraison);
        QSqlQuery query ;
        query.prepare("Select * from SERVICES WHERE id=:id ");
        query.bindValue(":id",id) ;
        query.exec();
        bool alreadyExist = false;
            alreadyExist = query.next();
            if(alreadyExist)
            {
        bool test=C.Modifier();
        QMessageBox msgbox;
        if(test)
            {
            msgbox.setText("Modification avec succes.");
                ui->tab_Commande->setModel(C.Afficher());
                ui->le_id_Modifier->setText("");
                ui->le_prix_Modifier->setText("");
            }
            else
                msgbox.setText("Echec de modification");
            msgbox.exec();
            }
          else
                         {
                             QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                             QObject::tr("ID INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                         }
}

void MainWindow::on_pb_Supprimer_clicked()
{

        Commande C1;
        C1.setid(ui->le_id_Supprimer->text().toInt());
        QSqlQuery query ;
        query.prepare("Select * from SERVICES WHERE id=:id ");
        query.bindValue(":id",C1.getid()) ;
        query.exec();
        bool alreadyExist = false;
            alreadyExist = query.next();
            if(alreadyExist)
            {
        bool test=C1.Supprimer(C1.getid());
        QMessageBox msgbox;
        if(test)
            {msgbox.setText("Suppression avec succes.");
                ui->tab_Commande->setModel(C.Afficher());
                ui->le_id_Supprimer->setText("");
            }
            else
                msgbox.setText("Echec de suppression");
            msgbox.exec();
            }
          else
                         {
                             QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                             QObject::tr("ID INTROUVABLE .\n" "Click Cancel to exit."), QMessageBox::Cancel);
                         }

}

