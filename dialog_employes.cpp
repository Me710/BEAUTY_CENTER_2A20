#include "dialog_employes.h"
#include "ui_dialog_employes.h"
#include "employe.h"
#include <QMessageBox>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>

Dialog_Employes::Dialog_Employes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Employes)
{
    ui->setupUi(this);
    //les Validators pour les types entiers ou numbers
    ui->lineEdit_cin->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_cin_modif->setValidator(new QIntValidator(0,999999,this));
    ui->lineEdit_age->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_age_modif->setValidator(new QIntValidator(0,99,this));
    ui->lineEdit_tel_modif->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_tel->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_salaire_modif->setValidator(new QIntValidator(0,99999,this));
    ui->lineEdit_salaire->setValidator(new QIntValidator(0,99999,this));
    ui->tableView->setModel(Empl.afficher());
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
    bool test=false;
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

    //Appel du constructeur parametré
    Employe E(cin,nom,prenom,mail,tel,fonction,sexe,adresse,salaire,age);

    //controle de saisirs
    bool test_nom = E.ChaineValide(nom);
    bool test_prenom = E.ChaineValide(prenom);
    bool test_adresse = E.ChaineValide(adresse);


    if(test_nom && test_prenom && test_adresse)
    {
        test=E.ajouter();
        if(test)//si requete executer ==>QMessageBox::information
        {
            ui->label_nom_verif->setText("");
            ui->label_prenom_verif->setText("");
            ui->label_adresse_verif->setText("");
            ui->label_mail_verif->setText("");
            ui->lineEdit_rechercher->setText("");
            ui->lineEdit_nom_modif->setText("");
            ui->lineEdit_prenom_modif->setText("");
            ui->lineEdit_mail_modif->setText("");
            ui->lineEdit_adresse_modif->setText("");
            ui->lineEdit_tel_modif->setText("");
            ui->lineEdit_age_modif->setText("");
            //ui->comboBox_sex_modif->setText("");
            ui->lineEdit_salaire_modif->setText("");
            //ui->comboBox_fonction_modif->currentText();
            ui->tableView->setModel(Empl.afficher());
            ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
            ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
            ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
            QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

        }
        else//si la requete non executer ==>QMessageBox::critical
        {
            ui->label_mail_verif->setText("CIN déjà existant/Mail incorrecte!");
            ui->label_nom_verif->setText("");
            ui->label_prenom_verif->setText("");
            ui->label_adresse_verif->setText("");
            //QMessageBox::critical(nullptr,QObject::tr("Not OK"),
              //                     QObject::tr("Ajout non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }
    }
    else
    {
        //Signalisation des controles
        if(!test_nom){ui->label_nom_verif->setText("Nom invalid");}else{ui->label_nom_verif->setText("");}
        if(!test_prenom){ui->label_prenom_verif->setText("Prenom invalid");}else{ui->label_prenom_verif->setText("");}
        if(!test_adresse){ui->label_adresse_verif->setText("Adresse invalid");}else{ui->label_adresse_verif->setText("");}

    }


}

void Dialog_Employes::on_pushButton_afficher_clicked()
{
    ui->tableView->setModel(Empl.afficher());
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

    bool test_nom = E.ChaineValide(nom);
    bool test_prenom = E.ChaineValide(prenom);
    bool test_adresse = E.ChaineValide(adresse);

    if(test_nom && test_prenom && test_adresse)
    {
        bool test=E.modifier();
        if(test)//si requete executer ==>QMessageBox::information
        {
            ui->tableView->setModel(Empl.afficher());
            ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
            ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
            ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));


            ui->label_nom_modif_verif->setText("");
            ui->label_prenom_modif_verif->setText("");
            ui->label_adresse_modif_verif->setText("");
            ui->label_mail_modif_verif->setText("");
            ui->lineEdit_rechercher->setText("");
            ui->lineEdit_cin_modif->setText("");
            ui->lineEdit_nom_modif->setText("");
            ui->lineEdit_prenom_modif->setText("");
            ui->lineEdit_mail_modif->setText("");
            ui->lineEdit_adresse_modif->setText("");
            ui->lineEdit_tel_modif->setText("");
            ui->lineEdit_age_modif->setText("");
            ui->comboBox_sex_modif->setCurrentText(0);
            ui->lineEdit_salaire_modif->setText("");
            ui->comboBox_fonction_modif->setCurrentText(0);

            QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Modification effectué avec succes\n""Click Cancel to exit."),QMessageBox::Cancel);


        }
        else//si la requete non executer ==>QMessageBox::critical
        {
            ui->label_mail_modif_verif->setText("CIN déjà existant/Mail incorrecte!");
            ui->label_nom_modif_verif->setText("");
            ui->label_prenom_modif_verif->setText("");
            ui->label_adresse_modif_verif->setText("");
           // QMessageBox::critical(nullptr,QObject::tr("Not OK"),
             //                      QObject::tr("Modification non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
        }

    }
    else
    {
        //Signalisation des controles
        if(!test_nom){ui->label_nom_modif_verif->setText("Nom invalid");}else{ui->label_nom_verif->setText("");}
        if(!test_prenom){ui->label_prenom_modif_verif->setText("Prenom invalid");}else{ui->label_prenom_verif->setText("");}
        if(!test_adresse){ui->label_adresse_modif_verif->setText("Adresse invalid");}else{ui->label_adresse_verif->setText("");}

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
            ui->comboBox_fonction_modif->setCurrentText(query.value(10).toString());
            ui->lineEdit_salaire_modif->setText(query.value(7).toString());
            ui->lineEdit_adresse_modif->setText(query.value(5).toString());
            ui->lineEdit_cin_modif->setText(query.value(0).toString());
            ui->lineEdit_age_modif->setText(query.value(8).toString());
            ui->lineEdit_tel_modif->setText(query.value(1).toString());
            ui->comboBox_sex_modif->setCurrentText(query.value(6).toString());
        }
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                               QObject::tr("Transfere de donnees Non effectué.\n""Click Cancel to exit."),QMessageBox::Cancel);
    }

}

void Dialog_Employes::on_pushButton_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/PMS-BLA-5-Chloe/Desktop/SMART_BEAUTY_CENTER/PDFEmploye.pdf");

    QPainter painter(&pdf);

    int i = 4000;
    painter.setPen(Qt::red);
    painter.setFont(QFont("Arial", 30));
    painter.drawPixmap(QRect(200,200,2000,2000),QPixmap("C:/Users/PMS-BLA-5-Chloe/Desktop/resources/logo.png"));
    painter.drawText(3000,1500,"LISTE DES EMPLOYES");
    painter.setPen(Qt::black);
    painter.setFont(QFont("Arial", 50));
    // painter.drawText(1100,2000,afficheDC);
    painter.drawRect(2700,200,7300,2600);
    //painter.drawRect(1500,200,7300,2600);
    //painter.drawPixmap(QRect(7600,70,2000,2600),QPixmap("C:/Users/RH/Desktop/projecpp/image/logopdf.png"));
    painter.drawRect(0,3000,9600,500);
    painter.setFont(QFont("Arial", 9));
    painter.drawText(300,3300,"CIN");
    painter.drawText(2300,3300,"TEL");
    painter.drawText(4300,3300,"MAIL");
    painter.drawText(6300,3300,"NOM");
    painter.drawText(8000,3300,"PRENOM");
    QSqlQuery query;
    query.prepare("select * from EMPLOYE");
    query.exec();
    while (query.next())
    {
        painter.drawText(300,i,query.value(0).toString());
        painter.drawText(2300,i,query.value(1).toString());
        painter.drawText(4300,i,query.value(2).toString());
        painter.drawText(6300,i,query.value(3).toString());
        painter.drawText(8000,i,query.value(4).toString());
        i = i +500;
    }

    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/PMS-BLA-5-Chloe/Desktop/SMART_BEAUTY_CENTER/PDFEmploye.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }

    /*painter.setPen(Qt::black);
    QSqlQuery query;
    query.prepare("select *from employe");

    if(query.exec())
    {

        while(query.next())
        {
           painter.drawText(100,0,query.value(0).toString());
           painter.drawText(900,800,query.value(1).toString());
           painter.drawText(200,200,query.value(2).toString());
           painter.drawText(300,300,query.value(3).toString());
           painter.drawText(400,400,query.value(4).toString());
           painter.drawText(500,500,query.value(5).toString());
        }
    }


    painter.end();

    QMessageBox::information(nullptr, QObject::tr("PDF"),
             QObject::tr("PDF Créer/Modifier avec succes\n""Click Cancel to exit."),QMessageBox::Cancel);*/

}

void Dialog_Employes::on_comboBox_currentIndexChanged(int index)
{
    QString valeur="cin";
    switch(index)
    {
    case 1:
        valeur="nom";
        break;
    case 2:
        valeur="prenom";
        break;
    case 3:
        valeur="salaire";
        break;
    }

    ui->tableView->setModel(Empl.trier(valeur));
}

void Dialog_Employes::on_pushButton_filtre_clicked()
{
    array<int,8> tab={0,0,0,0,0,0,0,0};

    if(ui->checkBox_prenom->isChecked()){tab.at(0)=1;}
    if(ui->checkBox_fonction->isChecked()){tab.at(1)=1;}
    if(ui->checkBox_adresse->isChecked()){tab.at(2)=1;}
    if(ui->checkBox_tel->isChecked()){tab.at(3)=1;}
    if(ui->checkBox_mail->isChecked()){tab.at(4)=1;}
    if(ui->checkBox_salaire->isChecked()){tab.at(5)=1;}
    if(ui->checkBox_age->isChecked()){tab.at(6)=1;}
    if(ui->checkBox_sexe->isChecked()){tab.at(7)=1;}

    ui->tableView->setModel(Empl.afficherFiltrer(tab));

}
