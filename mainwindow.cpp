#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_employes.h"
#include <QMessageBox>
#include <QDebug>
#include "employe.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Authentification
void MainWindow::on_pushButton_seConnecter_clicked()
{
    Dialog_Employes E;
    QSqlQuery query;
    /*QString username = ui->lineEdit_login->text();
    QString password = ui->lineEdit_motdepasse->text();*/

    query.prepare("select *from login where username=? and password=?");
    /*query.addBindValue(":username",username);
    query.addBindValue(":password",password);*/

    query.addBindValue(ui->lineEdit_login->text());
    query.addBindValue(ui->lineEdit_motdepasse->text());

    if(query.exec())
        {
            int count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                ui->label_statuts->setText("Statuts: Mot de passe/Login correctes");
                hide();
                E.setModal(true);
                E.exec();
            }
            if(count<1)
            {
                QMessageBox::warning(this,"Authentification échoué","Mot de passe/Login incorrectes");
                ui->label_statuts->setText("Statuts: Mot de passe/Login incorrectes");
            }

        }
        else
        {
             QMessageBox::warning(this,"Probleme d'envoie de la requete!","Une erreur s'est produit lors du traitement de la requete!");
        }
}

void MainWindow::on_pushButton_outils_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(1);
}

void MainWindow::on_pushButton_reinitialiser_mdp_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_inscription_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    ui->comboBox_mail_inscris->setModel(Empl.afficherValeur("mail"));
}

void MainWindow::on_pushButton_valider_inscription_clicked()
{
    QSqlQuery query;
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_mdp->text();
    QString password2=ui->lineEdit_mdp2->text();
    QString mail=ui->comboBox_mail_inscris->currentText();

     query.prepare("insert into login (username, password)" "values(:username, :password)");

    if(password != password2)
    {
        ui->label_verification_infos->setText("Mot de passe de confirmation different");
    }
    else
    {
        query.bindValue(":password",password);
        query.bindValue(":username",username);

        if(query.exec())
        {
            QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Inscription effectué avec succes\n""Click Cancel to exit."),QMessageBox::Cancel);
            ui->lineEdit_username->setText("");
            ui->lineEdit_mdp->setText("");
            ui->lineEdit_mdp2->setText("");
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                     QObject::tr("Inscription non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
}

void MainWindow::on_pushButton_accueil_clicked(){ui->stackedWidget->setCurrentIndex(0);}
