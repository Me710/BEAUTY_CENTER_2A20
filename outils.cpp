#include "outils.h"
#include "ui_outils.h"
#include "employe.h"
#include <QMessageBox>

Outils::Outils(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Outils)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(1);
}

Outils::~Outils()
{
    delete ui;
}

void Outils::on_pushButton_reinitialiser_mdp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void Outils::on_pushButton_inscription_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
    ui->comboBox_mail_inscris->setModel(Empl.afficherValeur("mail"));
}

void Outils::on_pushButton_valider_inscription_clicked()
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
