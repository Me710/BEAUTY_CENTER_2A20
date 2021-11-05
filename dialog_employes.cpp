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
    ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_cin_modif->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_age->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_age_modif->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_tel_modif->setValidator(new QIntValidator(0,999999999,this));
    ui->lineEdit_tel->setValidator(new QIntValidator(0,999999999,this));
    ui->lineEdit_salaire_modif->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_salaire->setValidator(new QIntValidator(0,99999,this));
    ui->tableView->setModel(Empl.afficher());
    ui->listView->setModel(Empl.afficherValeur("prenom"));
    ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
    ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
    ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
}

Dialog_Employes::~Dialog_Employes()
{
    delete ui;
}


void Dialog_Employes::on_pushButton_valider_ajout_clicked()
{
    //Recuperation des informations saisies dans les 3 champs
    int cin=ui->lineEdit_cin->text().toInt();
    QString nom=ui->lineEdit_nom->text();
    QString prenom=ui->lineEdit_prenom->text();
    QString mail=ui->lineEdit_mail->text();
    QString adresse=ui->lineEdit_adresse->text();
    int tel=ui->lineEdit_tel->text().toInt();
    int age=ui->lineEdit_age->text().toInt();
    QString sexe=ui->comboBox_sex->currentText();
    int salaire=ui->lineEdit_salaire->text().toInt();
    QString fonction=ui->comboBox_fonction->currentText();

    Employe E(cin,nom,prenom,mail,tel,fonction,sexe,adresse,salaire,age);
    bool test=E.ajouter();

    if(test)//si requete executer ==>QMessageBox::information
    {
        ui->tableView->setModel(Empl.afficher());
        ui->listView->setModel(Empl.afficherValeur("prenom"));
        ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
        ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
        ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
        QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else//si la requete non executer ==>QMessageBox::critical
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("Ajout non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void Dialog_Employes::on_pushButton_afficher_clicked()
{
    ui->tableView->setModel(Empl.afficher());
    ui->listView->setModel(Empl.afficherValeur("prenom"));
    ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
    ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
    ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
    ui->stackedWidget->setCurrentIndex(1);
}
void Dialog_Employes::on_pushButton_ajouter_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void Dialog_Employes::on_pushButton_modifier_clicked(){ui->stackedWidget->setCurrentIndex(2);}

void Dialog_Employes::on_pushButton_supprimer_clicked(){ui->stackedWidget->setCurrentIndex(3);}

void Dialog_Employes::on_pushButton_mailing_clicked(){ui->stackedWidget->setCurrentIndex(4);}

void Dialog_Employes::on_pushButton_deconnection_clicked()
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

void Dialog_Employes::on_pushButton_valider_modification_clicked()
{
    //Recuperation des informations saisies dans les 3 champs
    int cin=ui->lineEdit_cin_modif->text().toInt();
    QString nom=ui->lineEdit_nom_modif->text();
    QString prenom=ui->lineEdit_prenom_modif->text();
    QString mail=ui->lineEdit_mail_modif->text();
    QString adresse=ui->lineEdit_adresse_modif->text();
    int tel=ui->lineEdit_tel_modif->text().toInt();
    int age=ui->lineEdit_age_modif->text().toInt();
    QString sexe=ui->comboBox_sex_modif->currentText();
    int salaire=ui->lineEdit_salaire_modif->text().toInt();
    QString fonction=ui->comboBox_fonction_modif->currentText();

    Employe E(cin,nom,prenom,mail,tel,fonction,sexe,adresse,salaire,age);
    bool test=E.modifier();

    if(test)//si requete executer ==>QMessageBox::information
    {
        ui->tableView->setModel(Empl.afficher());
        ui->listView->setModel(Empl.afficherValeur("prenom"));
        ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
        ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
        ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
        QMessageBox::information(nullptr, QObject::tr("OK"),
                 QObject::tr("Modification effectué avec succes\n""Click Cancel to exit."),QMessageBox::Cancel);

    }
    else//si la requete non executer ==>QMessageBox::critical
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("Modification non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }


}

void Dialog_Employes::on_pushButton_valider_suppression_clicked()
{
    int cin=ui->comboBox_cin_suppr->currentText().toInt();
    QMessageBox::StandardButton reply = QMessageBox::question(this,"Suppression","Voulez-vous vraiment supprimer cet employe definitivement de la base de donnée?", QMessageBox::Yes | QMessageBox::No);

    if(reply==QMessageBox::Yes)
    {
        bool test=Empl.supprimer(cin);
        ui->tableView->setModel(Empl.afficher());
        ui->comboBox_cin_modif->setModel(Empl.afficherValeur("prenom"));
        ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
        ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
        ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
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


void Dialog_Employes::on_pushButton_verifier_supprimer_clicked()
{
    int cin=ui->comboBox_cin_suppr->currentText().toInt();
    ui->tableView_supprimer->setModel(Empl.rechercher(cin));
}


void Dialog_Employes::on_pushButton_rechercher_empl_clicked()
{
    int cin=ui->lineEdit_rechercher->text().toInt();
    ui->tableView->setModel(Empl.rechercher(cin));
    ui->lineEdit_rechercher->setText("");
}

void Dialog_Employes::on_comboBox_cin_modif_currentIndexChanged(int index)
{
    index=0;
    int cin_e=ui->comboBox_cin_modif->currentText().toInt();
    QSqlQuery query;
    query.prepare("select *from employe where cin_e=:cin_e");
    query.bindValue(":cin_e",cin_e);

    index++;

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_nom_modif->setText(query.value(3).toString());
            ui->lineEdit_prenom_modif->setText(query.value(4).toString());
            ui->lineEdit_mail_modif->setText(query.value(2).toString());
            //ui->comboBox_fonction_modif->setText(query.value(5).toString());
            ui->lineEdit_salaire_modif->setText(query.value(8).toString());
            ui->lineEdit_adresse_modif->setText(query.value(7).toString());
            ui->lineEdit_cin_modif->setText(query.value(0).toString());
            ui->lineEdit_age_modif->setText(query.value(9).toString());
            ui->lineEdit_tel_modif->setText(query.value(1).toString());
            //ui->lineEdit_sexe_modif->setText(query.value(6).toString());

        }
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("Transfere de donnees Non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}
