#include "dialog.h"
#include "ui_dialog.h"
#include"produit.h"
#include<QMessageBox>
#include<QComboBox>
#include<QtGui>
#include<QIntValidator>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->tab_produit->setModel(P.afficher());
    ui->comboBox->setModel(P.afficher_code());
    ui->comboBox_2->setModel(P.afficher_code());
    }

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_valider_clicked()
{   ui->setupUi(this);
    int code=ui->le_code->text().toInt();
    ui->le_code->setValidator(new QIntValidator(0,999,this));
    /*ui->setupUi(this);
       ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
       ui->le_prix->setValidator(new QIntValidator(0,9999, this));*/
    QString nom=ui->le_nom->text();
    int prix=ui->le_prix->text().toInt();
    int qualite=ui->la_qualite->text().toInt();
    int stock=ui->le_stock->text().toInt();
    Produit P(code,nom,prix,qualite,stock);

    bool test=P.ajouter();
     if(test)
     { ui->tab_produit->setModel(P.afficher());
         ui->comboBox->setModel(P.afficher_code());
         ui->comboBox_2->setModel(P.afficher_code());
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                QObject::tr("ajout effectue.\n"
                                            "clicl cancel to exit."),QMessageBox::Cancel);}
     else
     QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                                QObject::tr("ajout non effectue.\n"
                                            "clicl cancel to exit."),QMessageBox::Cancel);
}

void Dialog::on_supprimer_clicked()
{
    Produit P1;
    P1.setcode(ui->comboBox->currentText().toInt());

    bool test=P1.supprmier(P1.getcode());
        if(test)
        {  ui->tab_produit->setModel(P1.afficher());
            ui->comboBox->setModel(P.afficher_code());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("suppression effectue.\n"
                                           "clicl cancel to exit."),QMessageBox::Cancel);
        }

    else
        {
            ui->tab_produit->setModel(P1.afficher());
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("suppression non effectue.\n"
                                           "clicl cancel to exit."),QMessageBox::Cancel);
        }

}

void Dialog::on_pushButton_clicked()
{
    Produit P1;
    //P1.setcode(ui->code_supp->text().toInt());
    bool test=P1.supprmier(P1.getcode());
        if(test)
        {   ui->comboBox->setModel(P1.afficher_code());
        QMessageBox::information(nullptr,QObject::tr("OK"),
                               QObject::tr("suppression effectue effectue.\n"
                                           "clic cancel to exit."),QMessageBox::Cancel);
        }

    else
        {
    QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                               QObject::tr("suppression non effectue.\n"
                                           "clic cancel to exit."),QMessageBox::Cancel);
        }
}

void Dialog::on_update_clicked()
{   //Produit P;
    P.setcode(ui->comboBox_2->currentText().toInt());
    int code=ui->le_code_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    int prix=ui->le_prix_2->text().toInt();
    int qualite=ui->la_qualite_2->text().toInt();
    int stock=ui->le_stock_2->text().toInt();
    Produit P(code,nom,prix,qualite,stock);
    bool test=P.update();
    if(test)
    {   ui->comboBox_2->setModel(P.afficher_code());
    QMessageBox::information(nullptr,QObject::tr("OK"),
                           QObject::tr("update effectue.\n"
                                       "clic cancel to exit."),QMessageBox::Cancel);
    ui->tab_produit->setModel(P.afficher());
    }
else
    {ui->tab_produit->setModel(P.afficher());
QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                           QObject::tr("update non effectue.\n"
                                       "clic cancel to exit."),QMessageBox::Cancel);}
}



void Dialog::on_comboBox_currentIndexChanged(int index)
{

}

void Dialog::on_comboBox_2_currentIndexChanged(int index)
{

}
