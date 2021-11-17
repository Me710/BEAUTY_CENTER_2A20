#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_employes.h"
#include <QMessageBox>
#include <QDebug>
#include "employe.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
    bool test;
    test = C.createconnection("system","system","system");
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("conncetion sucessful (login).""Click Cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("conncetion failed(login).\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

//Authentification
void MainWindow::on_pushButton_seConnecter_clicked()
{
    Dialog_Employes E;
    QString username = ui->lineEdit_login->text();
    QString password = ui->lineEdit_motdepasse->text();


        if(C.Authentification(username,password))
        {
            ui->label_statuts->setText("Statuts: Mot de passe/Login correctes");
            C.closeconnection();
            hide();

            bool test=C.createconnection("test-bd","Christian","Christian");

            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("conncetion sucessful.""Click Cancel to exit."),QMessageBox::Cancel);
                E.setModal(true);
                E.exec();
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("conncetion failed.\n""Click Cancel to exit."),QMessageBox::Cancel);
            }
        }
        else
        {
            QMessageBox::warning(this,"AUTHENTIFICATION ECHOUE","MOT DE PASSE/LOGIN INCORRECTES!");

        }


}

void MainWindow::on_pushButton_outils_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->stackedWidget_2->setCurrentIndex(2);
}

void MainWindow::on_pushButton_reinitialiser_mdp_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);
}

void MainWindow::on_pushButton_inscription_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
    //ui->comboBox_mail_inscris->setModel(Empl.afficherValeur("mail"));
}

void MainWindow::on_pushButton_valider_inscription_clicked()
{
    QSqlQuery query;
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_mdp->text();
    QString password2=ui->lineEdit_mdp2->text();
    //QString mail=ui->comboBox_mail_inscris->currentText();

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
            QMessageBox::information(this,"OK","Login Créé avec succes\n");
            ui->lineEdit_username->setText("");
            ui->lineEdit_mdp->setText("");
            ui->lineEdit_mdp2->setText("");
        }
        else
        {
            QMessageBox::critical(this,"NOT OK","Echec de création du Login");
        }
    }
}

void MainWindow::on_pushButton_accueil_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::on_pushButton_changer_mdp_clicked(){ui->stackedWidget_2->setCurrentIndex(1);}

void MainWindow::on_pb_se_connecter_admin_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_retour_3_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_retour_1_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_retour_2_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_pb_accueil_clicked(){ui->stackedWidget->setCurrentIndex(0);}
