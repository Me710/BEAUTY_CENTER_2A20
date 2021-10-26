#include "dialog_employes.h"
#include "ui_dialog_employes.h"
#include "employe.h"
#include <QMessageBox>
#include <QDebug>

Dialog_Employes::Dialog_Employes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Employes)
{
    ui->setupUi(this);
}

Dialog_Employes::~Dialog_Employes()
{
    delete ui;
}

void Dialog_Employes::on_pushButton_valider_clicked()
{
    //Recuperation des informations saisies dans les 3 champs
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();


    Employe E(cin,nom,prenom);
    bool test=E.ajouter();

    if(test)//si requete executer ==>QMessageBox::information
    {
        ui->tableView->setModel(Empl.afficher());
        QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else//si la requete non executer ==>QMessageBox::critical
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void Dialog_Employes::on_pushButton_ajouter_clicked()
{
    ui->label_menu_active->setText("AJOUT D'UN EMPLOYE");
}

void Dialog_Employes::on_pushButton_afficher_clicked()
{
    ui->label_menu_active->setText("AFFICHER LES EMPLOYES");
    ui->tableView->setModel(Empl.afficher());

}

void Dialog_Employes::on_pushButton_modifier_clicked()
{
    ui->label_menu_active->setText("MODIFIER UN EMPLOYE");
}

void Dialog_Employes::on_pushButton_supprimer_clicked()
{
    //ui->label_menu_active->setText("SUPRESSION D'UN EMPLOYE");
    int cin=ui->lineEdit_id_supprimer->text().toInt();
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet employe definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    {
        bool test=Empl.supprimer(cin);
        if(test)//si requete executer ==>QMessageBox::information
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Suppression effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

        }
        else//si la requete non executer ==>QMessageBox::critical
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                   QObject::tr("Suppression non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
    else
    {
       qDebug()<<"Suppresion annulée!!";
    }

    //ui->tableView->show();

}

void Dialog_Employes::on_pushButton_clicked()
{
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Deconnection","Voulez-vous vraiment vous deconnecter?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    {
        QDialog::close();
    }
    else
    {
       qDebug()<<"Connexion restauré!!";
    }
}
