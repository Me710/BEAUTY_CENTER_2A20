#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "commande.h"
#include<QMessageBox>
#include<QPdfWriter>
#include<QDebug>
#include<QDesktopServices>
#include<QUrl>
#include<QPainter>
#include<QIntValidator>
#include <QTableWidget>
#include <QFile>
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
 ui->le_date_passage->setDateTime(QDateTime::currentDateTime());
     ui->le_date_livraison->setDateTime(QDateTime::currentDateTime());
     ui->le_datep_Modifier->setDateTime(QDateTime::currentDateTime());
         ui->le_datel_Modifier->setDateTime(QDateTime::currentDateTime());
 C.Signal();
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
C.notification("Commande ajoutée");

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


void MainWindow::on_pushButton_2_clicked()
{
    QPdfWriter pdf("C:/Users/leila/Desktop/LMD.pdf");

        QPainter painter(&pdf);

        int i = 4000;
        painter.setPen(Qt::red);
        painter.setFont(QFont("Arial", 30));

        painter.drawText(3000,1500,"LISTE DES COMMANDES");
        painter.setPen(Qt::blue);
        painter.setFont(QFont("josefin sans", 50));
        painter.drawRect(2700,200,6300,2600);
        painter.drawRect(0,3000,9600,500);
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"ID");
        painter.drawText(1300,3300,"PRIX");
        painter.drawText(2400,3300,"DATE PASSAGE COMMANDE ");
        painter.drawText(6000,3300,"DATE DE LIVRAISON COMMANDE");

        QSqlQuery query;
        query.prepare("select * from SERVICES");
        query.exec();
        while (query.next())
        {
            painter.drawText(300,i,query.value(0).toString());
            painter.drawText(1300,i,query.value(1).toString());
            painter.drawText(2400,i,query.value(2).toString());
            painter.drawText(6300,i,query.value(3).toString());

            i = i +500;
        }

        int reponse = QMessageBox::question(this, "PDF généré", "Afficher le PDF ?", QMessageBox::Yes |  QMessageBox::No);
        if (reponse == QMessageBox::Yes)
        {
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/leila/Desktop/LMD.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    Commande C ;
    ui->tab_Commande->setModel(C.rechercher(arg1));
}





void MainWindow::on_checkBox_verifDate_clicked()
{
    QSqlQuery query;
    query.prepare("SELECT date_livraison from Services where date_livraison = current_date ");
    query.exec() ;
    if(query.next())
    {

        QMediaPlayer* player = new QMediaPlayer;

      player->setMedia(QUrl("C:/Users/leila/Downloads/Smart beauty center/Window Sms.mp3"));
        player->setVolume(50);
        player->play();
    }


}


void MainWindow::on_pb_agenda_clicked()
{
    QPdfWriter pdf("C:/Users/leila/Desktop/Smart beauty center/agenda.pdf");

            QPainter painter(&pdf);

            int i = 4000;
            painter.setPen(Qt::blue);
            painter.setFont(QFont("Arial", 30));
            painter.drawText(3000,1500,"Planning");
            painter.setPen(Qt::black);
            painter.setFont(QFont("Arial", 50));
            // painter.drawText(1100,2000,afficheDC);
            painter.drawRect(2700,200,7300,2600);

            painter.drawRect(0,3000,9600,500);
            painter.setFont(QFont("Arial", 9));
            painter.drawText(300,3300,"date_passage");
            painter.drawText(2300,3300,"date_livraison");
            QSqlQuery query;
            query.prepare("select * from SERVICES");
            query.exec();
            while (query.next())
            {
                painter.drawText(300,i,query.value(2).toString());
                painter.drawText(2300,i,query.value(3).toString());

                i = i +500;
            }

            int reponse = QMessageBox::question(this, "AGENDA", "<Agenda modifié>...Vous Voulez Affichez Le PLANNING ?", QMessageBox::Yes |  QMessageBox::No);
            if (reponse == QMessageBox::Yes)
            {
                QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/leila/Desktop/Smart beauty center/agenda.pdf"));

                painter.end();
            }
            if (reponse == QMessageBox::No)
            {
                painter.end();
            }


}

void MainWindow::on_pb_trie_clicked()
{
    Commande C ;
                QString crit=ui->comboBoxTri->currentText();
                if(crit=="id")
                {
                    ui->tab_Commande->setModel(C.tri_id());
                }
                else if(crit=="prix")
                {
                    ui->tab_Commande->setModel(C.tri_prix());
                }
                else
                {
                    ui->tab_Commande->setModel(C.tri_date());
                }
}
