#include <QIntValidator>
#include <QMessageBox>
#include "QString"
#include <QSqlQuery>
#include <QDebug>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->LEcin->setValidator(new QIntValidator(0, 999999999, this));
    ui->LEtel->setValidator(new QIntValidator(0, 99999999, this));
    ui->tabClient->setModel(cl.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PBajouter_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_PBmodifier_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PBsupprimer_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_PBafficher_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_retour_1_clicked()
{
    this->ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    QString nom=ui->LEnom->text();
    QString prenom=ui->LEprenom->text();
    int cin=ui->LEcin->text().toInt();
    QString mail=ui->LEmail->text();
    int tel=ui->LEtel->text().toUInt();
    QString adresse=ui->LEadresse->text();
    QString sexe;
    if(ui->RBfemme->isChecked()){
        sexe="Femme";
    }
    else {
        sexe="Homme";
    }

    Client c(nom, prenom, cin, mail, tel, adresse, sexe);
    bool test=c.ajouter();
    if(test){
        QMessageBox::information(this,"Ajout","Ajout avec succes");
        ui->tabClient->setModel(cl.afficher());
    }
    else
        QMessageBox::information(this,"Ajout","Echec d'ajout");
}


void MainWindow::on_PBsupprimer_2_clicked()
{
    Client cl1; cl1.set_cin(ui->LEcinsupp->text().toUInt());
    bool test=cl1.supprimer(cl1.get_cin());

    if(test){
        QMessageBox::information(this,"Supp","Suppression avec succes");
        ui->tabClient->setModel(cl.afficher());
    }
    else
        QMessageBox::information(this,"Supp","Echec de suppression");
}
