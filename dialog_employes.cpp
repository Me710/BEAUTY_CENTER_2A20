#include "dialog_employes.h"
#include "ui_dialog_employes.h"
#include "employe.h"
#include <QMessageBox>
#include <QDebug>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QFileDialog>
#include <QPixmap>
#include "mail/SmtpMime"
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include "gestion_produit/produit.h"
#include "gestion_produit/qrcode.h"


#include "gestion_pub/publicites.h"
#include <QDate>
#include <QDateEdit>
#include <QIntValidator>
#include <QDebug>
#include <QRegExpValidator>
#include <QTranslator>
#include <QSystemTrayIcon>
#include <QUrl>
#include <QDesktopServices>
#include <QFileInfo>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QTextDocument>

#include "gestion_commande/commande.h"
#include <QIntValidator>
#include <QTableWidget>
#include <QFile>
#include <QRegularExpressionValidator>

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

    //
    ui->le_stock->setValidator(new QIntValidator(0,999,this));
    ui->le_code->setValidator(new QIntValidator(100,999999999,this));
    ui->le_prix->setValidator(new QIntValidator(0,99999,this));
    ui->la_qualite->setValidator(new QIntValidator(0,999,this));
    ui->tab_produit->setModel(P.afficher());
    ui->tab_recehreche->setModel(P.afficher());
    ui->comboBox->setModel(P.afficher_code());
    ui->comboBox_2->setModel(P.afficher_code());

    //
    QPixmap pix("‪C:/Users/ryhab/OneDrive/Bureau/Projet C++/Houba.png");
    ui->label_pic->setPixmap(pix);
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_prix->setValidator(new QIntValidator(0, 999, this));
    ui->tab_publicites->setModel(Pu.afficher());
    #define NOM_RX "^([a-z]+[,.]?[ ]?|[a-z]+['-]?)+$"
    QRegExp rxNom(NOM_RX);
    QRegExpValidator*valiNom= new QRegExpValidator(rxNom,this);
    ui->le_nom->setValidator(valiNom);
    ui->la_desc->setValidator(valiNom);
    ui->la_date->setDateTime(QDateTime::currentDateTime());
    ui->la_date_update->setDateTime(QDateTime::currentDateTime());

    //
    ui->le_id->setValidator(new QIntValidator(0, 99999999, this));
    ui->le_prix->setValidator(new QIntValidator(0,9999, this));
    ui->tab_Commande->setModel(C.Afficher());
    ui->le_id->setValidator(valiNom);
    ui->le_prix->setValidator(valiNom);
    ui->le_date_passage_3->setDateTime(QDateTime::currentDateTime());
    ui->le_date_livraison_3->setDateTime(QDateTime::currentDateTime());
    ui->le_datep_Modifier_3->setDateTime(QDateTime::currentDateTime());
    ui->le_datel_Modifier_3->setDateTime(QDateTime::currentDateTime());
    C.Signal();


    int ret=A.connect_arduino();
    switch (ret) {
    case (0):qDebug()<<"arduino is available and connected to: "<<A.getarduino_port_name();
        break;
    case(1):qDebug()<<"arduino is available but not connected to: "<<A.getarduino_port_name();
        break;
    case(-1):qDebug()<<"arduino is not available";
        break;
    }
    QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label()));
   // ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
}

Dialog_Employes::~Dialog_Employes()
{
    delete ui;
}

void Dialog_Employes::on_pushButton_valider_ajout_clicked()
{
    bool test=false;


    //ui->label_pic->setPixmap(pix);
    //QString fileName = QFileDialog::getOpenFileName(this,
      //  tr("Open File"), "", tr("All Files (*.*)"));
    //QPixmap pix(fileName);

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
            ui->label_nom_verif->clear();
            ui->label_prenom_verif->clear();
            ui->label_adresse_verif->clear();
            ui->label_mail_verif->clear();
            ui->lineEdit_rechercher->clear();
            ui->lineEdit_cin->clear();
            ui->lineEdit_nom->clear();
            ui->lineEdit_prenom->clear();
            ui->lineEdit_mail->clear();
            ui->lineEdit_adresse->clear();
            ui->lineEdit_tel->clear();
            ui->lineEdit_age->clear();
            //ui->comboBox_sex_modif->setText("");
            ui->lineEdit_salaire->clear();
            //ui->comboBox_fonction_modif->currentText();
            ui->tableView->setModel(Empl.afficher());
            ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
            ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
           // ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
            QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Ajout effectué\n""Click Cancel to exit."),QMessageBox::Cancel);

        }
        else//si la requete non executer ==>QMessageBox::critical
        {
            ui->label_mail_verif->setText("CIN déjà existant/Mail incorrecte!");
            ui->label_nom_verif->clear();
            ui->label_prenom_verif->clear();
            ui->label_adresse_verif->clear();
        }
    }
    else
    {
        //Signalisation des controles
        if(!test_nom){ui->label_nom_verif->setText("Nom invalid");}else{ui->label_nom_verif->clear();}
        if(!test_prenom){ui->label_prenom_verif->setText("Prenom invalid");}else{ui->label_prenom_verif->clear();}
        if(!test_adresse){ui->label_adresse_verif->setText("Adresse invalid");}else{ui->label_adresse_verif->clear();}

    }


}

void Dialog_Employes::on_pushButton_afficher_clicked()
{
    ui->tableView->setModel(Empl.afficher());
    ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
    ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
    //ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
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

    if(test_nom && test_prenom && test_adresse && salaire>=0)
    {
        bool test=E.modifier();
        if(test)//si requete executer ==>QMessageBox::information
        {
            ui->tableView->setModel(Empl.afficher());
            ui->comboBox_cin_modif->setModel(Empl.afficherValeur("cin_e"));
            ui->comboBox_cin_suppr->setModel(Empl.afficherValeur("cin_e"));
           // ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));


            ui->label_nom_modif_verif->clear();
            ui->label_prenom_modif_verif->clear();
            ui->label_adresse_modif_verif->clear();
            ui->label_mail_modif_verif->clear();
            ui->lineEdit_rechercher->clear();
            ui->lineEdit_cin_modif->clear();
            ui->lineEdit_nom_modif->clear();
            ui->lineEdit_prenom_modif->clear();
            ui->lineEdit_mail_modif->clear();
            ui->lineEdit_adresse_modif->clear();
            ui->lineEdit_tel_modif->clear();
            ui->lineEdit_age_modif->clear();
            ui->comboBox_sex_modif->clear();
            ui->lineEdit_salaire_modif->clear();
            ui->comboBox_fonction_modif->clear();

            QMessageBox::information(nullptr, QObject::tr("OK"),
                     QObject::tr("Modification effectué avec succes\n""Click Cancel to exit."),QMessageBox::Cancel);


        }
        else//si la requete non executer ==>QMessageBox::critical
        {
            ui->label_mail_modif_verif->setText("CIN déjà existant/Mail incorrecte!");
            ui->label_nom_modif_verif->clear();
            ui->label_prenom_modif_verif->clear();
            ui->label_adresse_modif_verif->clear();
        }

    }
    else
    {
        //Signalisation des controles
        if(!test_nom){ui->label_nom_modif_verif->setText("Nom invalid");}else{ui->label_nom_verif->setText("");}
        if(!test_prenom){ui->label_prenom_modif_verif->setText("Prenom invalid");}else{ui->label_prenom_verif->setText("");}
        if(!test_adresse){ui->label_adresse_modif_verif->setText("Adresse invalid");}else{ui->label_adresse_verif->setText("");}
        if(salaire<0){ui->label_salaire_modif_verif->setText("Salaire invalid");}else{ui->label_salaire_modif_verif->clear();}

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
       // ui->comboBox_mails->setModel(Empl.afficherValeur("mail"));
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
    //QString cin=ui->lineEdit_rechercher->text();
    //ui->tableView->setModel(Empl.rechercher(cin));
    //ui->lineEdit_rechercher->clear();
    switch(Empl.get_index())
    {
      case 1:case 4 :case 8:
        ui->tableView->setModel(Empl.rechercher(ui->lineEdit_rechercher->text().toInt()));
        break;
    case 2: case 3: case 5: case 6:case 7:
        ui->tableView->setModel(Empl.rechercher(ui->lineEdit_rechercher->text()));
        break;
    }
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

//-------GENERER UN PDF----------------------------------------------------------------------------------------/

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
    painter.drawRect(2700,200,7300,2600);
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

}

//-------TRIER LA LISTE----------------------------------------------------------------------------------------/

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

//-------PSEUDO FILTRE----------------------------------------------------------------------------------------/


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

//-----------------MAILING--------------------------------------------------------------------------------/

QStringList Dialog_Employes::getRecipientsAddress(QString str)
{

    QStringList recipients;

    recipients = str.split(QRegExp(";"));

    return recipients;
}

void Dialog_Employes::on_tb_getAttach1_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach1->setText(fileName);

}

void Dialog_Employes::on_tb_getAttach2_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach2->setText(fileName);
}

void Dialog_Employes::on_tb_getAttach3_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach3->setText(fileName);
}

void Dialog_Employes::on_tb_getAttach4_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Open File"), "", tr("All Files (*.*)"));

    ui->le_emailAttach4->setText(fileName);
}

void Dialog_Employes::on_envoyer_mail_clicked()
{
    if(ui->le_emailUser->text() != NULL && ui->le_emailPass->text() !=NULL){
        if(ui->le_emailPort->text().toInt() != 0 && ui->le_emailSmtp->text()!= NULL){
            if(ui->le_sendersAdd->text() != NULL && ui->le_toAdd->text() != NULL){

                SmtpClient smtp(ui->le_emailSmtp->text(), ui->le_emailPort->text().toInt(), SmtpClient::SslConnection);

                smtp.setUser(ui->le_emailUser->text());
                smtp.setPassword(ui->le_emailPass->text());

                MimeMessage message;

                EmailAddress sender(ui->le_sendersAdd->text(), ui->le_sendersName->text());
                message.setSender(&sender);

                //create list of to
                QStringList to = getRecipientsAddress(ui->le_toAdd->text());
                QStringList cc = getRecipientsAddress(ui->le_ccAdd->text());
                QStringList bcc = getRecipientsAddress(ui->le_bccAdd->text());

                for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
                     message.addRecipient(new EmailAddress(*it),MimeMessage::To);
                }
                for (QStringList::iterator it = cc.begin();it != cc.end(); ++it) {
                     message.addRecipient(new EmailAddress(*it),MimeMessage::Cc);
                }
                for (QStringList::iterator it = bcc.begin();it != bcc.end(); ++it) {
                     message.addRecipient(new EmailAddress(*it),MimeMessage::Bcc);
                }

                //set message subject
                message.setSubject(ui->le_emailSubject->text());

                MimeText text;
                text.setText(ui->te_emailContent->document()->toPlainText());
                message.addPart(&text);

                MimeAttachment attachment1(new QFile(ui->le_emailAttach1->text()));
                MimeAttachment attachment2(new QFile(ui->le_emailAttach2->text()));
                MimeAttachment attachment3(new QFile(ui->le_emailAttach3->text()));
                MimeAttachment attachment4(new QFile(ui->le_emailAttach4->text()));

                //attachments
                if(ui->le_emailAttach1->text() != NULL){
                   message.addPart(&attachment1);
                }

                if(ui->le_emailAttach2->text() != NULL){
                    message.addPart(&attachment2);
                }

                if(ui->le_emailAttach3->text() != NULL){
                    message.addPart(&attachment3);
                }

                if(ui->le_emailAttach4->text() != NULL){
                    message.addPart(&attachment4);
                }


                 if (!smtp.connectToHost()) {
                     QMessageBox::critical(this,"Failed to connect","Cannot connect to host");
                     //return -1;
                 }

                 if (!smtp.login()) {
                     QMessageBox::critical(this,"Failed to connect","Failed to login");
                    // return -2;
                 }

                 smtp.sendMail(message);

                 QMessageBox::information(this,"Email Send","Operation completed succesfully!");

                 smtp.quit();

            }else QMessageBox::information(this,"Fill info", "please input senders addres and reciever addres");
        }else QMessageBox::information(this,"Fill info", "please input port and smtp");
    }else QMessageBox::information(this,"Fill info", "please input username and password");
}

void Dialog_Employes::on_comboBox_2_currentIndexChanged(int index)
{
    Empl.set_index(index);
}

void Dialog_Employes::update_label()
{
    data=A.read_from_arduino();
    qDebug()<<data;

    if(data=="\xE3")
    {
        QMessageBox::information(this,"LECTURE","LIVREUR AUTORISE!");
        A.write_to_arduino("CHRIS");
        //data= "-1";
    }
    else
    {
        QMessageBox::critical(this,"LECTURE","LIVREUR NON AUTRISER!");
        A.write_to_arduino("REFUS");
        //data= "-1";
    }
}

void Dialog_Employes::on_ajouter_carte_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->comboBox_id_employe->setModel(Empl.afficherValeur("cin_e"));
}

void Dialog_Employes::on_comboBox_id_employe_currentIndexChanged(int index)
{
    index=0;
    int cin_e=ui->comboBox_id_employe->currentText().toInt();
    QSqlQuery query;
    query.prepare("select nom, prenom from employe where cin_e=:cin_e");
    query.bindValue(":cin_e",cin_e);

    index++;

    if(query.exec())
    {
        while(query.next())
        {
            ui->lineEdit_nom_employe->setText(query.value(0).toString());
            ui->lineEdit_prenom_employe->setText(query.value(1).toString());
        }
    }
}

void Dialog_Employes::on_valider_carte_rfid_clicked()
{
    Employe E;
    E.set_cin(ui->comboBox_id_employe->currentText().toInt());
    E.set_card_num(ui->lineEdit_num_card->text());

    int test;
    test=E.ajouterCarte();
    if(test)
    {
        QMessageBox::information(this,"AJOUT DE LA CARTE RFID","Ajout effectuer avec success!");
    }
    else
    {
        QMessageBox::critical(this,"AJOUT DE LA CARTE RFID","Ajout non effectuer!");
    }
}

//GEstion des produits-----------------------------------------------------------------------------------------------------
void Dialog_Employes::on_valider_clicked()
{   ui->tab_produit->setModel(P.afficher());
    int code=ui->le_code->text().toInt();


        ui->le_stock->setValidator(new QIntValidator(0,999,this));
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

void Dialog_Employes::on_supprimer_clicked()
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

void Dialog_Employes::on_pushButton_clicked()
{
   // Produit P1;
    bool test=P.supprmier(P.getcode());
        if(test)
        {  ui->tab_produit->setModel(P.afficher());
            ui->comboBox->setModel(P.afficher_code());
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
//

void Dialog_Employes::on_update_clicked()
{   //Produit P1;

      int code=ui->comboBox_2->currentText().toInt();
        QString nom=ui->le_nom_2->text();
        int prix=ui->le_prix_2->text().toInt();
        int qualite=ui->la_qualite_2->text().toInt();
        int stock=ui->le_stock_2->text().toInt();
       Produit P1(code,nom,prix,qualite,stock);
        bool test=P1.update();
        if(test)
        {   ui->tab_produit->setModel(P.afficher());
    QMessageBox::information(nullptr,QObject::tr("OK"),
                           QObject::tr("update effectue.\n"
                                       "clic cancel to exit."),QMessageBox::Cancel);

        }
else
    {ui->tab_produit->setModel(P.afficher());
QMessageBox::critical(nullptr,QObject::tr("NOT OK"),
                           QObject::tr("update non effectue.\n"
                                       "clic cancel to exit."),QMessageBox::Cancel);}

}

void Dialog_Employes::on_trier_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectu.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tab_produit->setModel(P.tri_code());
}

void Dialog_Employes::on_tri_prix_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectu.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_produit->setModel(P.tri_prix());
}

void Dialog_Employes::on_tri_stock_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectu.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_produit->setModel(P.tri_stock());
}

void Dialog_Employes::on_rechercher_clicked()
{

        {
             int code=ui->chercher->text().toInt();
             ui->tab_recehreche->setModel(P.recherche(code));
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("recherche effectue.\n"
                                                   "clic cancel to exit."),QMessageBox::Cancel);
                    }

  }




            void Dialog_Employes::on_PDF_clicked()
            {
                    QPdfWriter pdf("C:/Users/Karoui/Desktop/projet/beauty_center/produit.pdf");

                    QPainter painter(&pdf);

                    int i = 4000;
                    painter.setPen(Qt::red);
                    painter.setFont(QFont("Arial", 30));
                    painter.drawText(3000,1500,"LISTE DES PRODUIT");
                    painter.setPen(Qt::black);
                    painter.setFont(QFont("Arial", 50));
                    // painter.drawText(1100,2000,afficheDC);
                    painter.drawRect(2700,200,7300,2600);
                    painter.drawRect(0,3000,9600,500);
                    painter.setFont(QFont("Arial", 9));
                    painter.drawText(300,3300,"CODE");
                    painter.drawText(2300,3300,"nom");
                    painter.drawText(4300,3300,"prix");
                    painter.drawText(6300,3300,"qualite");
                    painter.drawText(8000,3300,"stock");
                    QSqlQuery query;
                    query.prepare("select * from PRODUITS");
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
                        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Karoui/Desktop/projet/beauty_center/produit.pdf"));

                        painter.end();
                    }
                    if (reponse == QMessageBox::No)
                    {
                        painter.end();
                    }

            }


void Dialog_Employes::on_wa_clicked()
{
    QString link="https://barcode.tec-it.com/fr/?data=15021383%0A";
     QDesktopServices::openUrl(QUrl(link));
}



void Dialog_Employes::on_inserer_photo_clicked()
{
    QString filename = QFileDialog::getSaveFileName(this,tr("choose"),"",tr("Image(*.png *.jpeg *.jpg *.bmp *.gif)"));
    if (QString::compare(filename,QString()) !=0)
    {
        QImage image;
        bool valid = image.load(filename);
        if(valid)
        {
            image=image.scaledToWidth(ui->img_label->width(), Qt::SmoothTransformation);
                    ui->img_label->setPixmap(QPixmap::fromImage(image));
        }

     }
}

//GESTION DES PUBLICITES------------------------------------------------------------------------------------------------------------

void Dialog_Employes::on_pb_ajouter_clicked()
{
   int ID_P=ui->le_id->text().toInt();
   QString nom=ui->le_nom_3->text();
   QDate datep=ui->la_date->date();
   QString description=ui->la_desc->text();
   int prix=ui->le_prix_3->text().toInt();
   Publicites P(ID_P,nom,datep,description,prix);
   bool test=P.ajouter();
   QMessageBox msgbox;
   if(test)
       {msgbox.setText("Ajout avec succes.");
           ui->tab_publicites->setModel(P.afficher());
           ui->le_id->setText("");
           ui->le_nom_3->setText("");
           ui->la_date->setDate(datep);
           ui->la_desc->setText("");
           ui->le_prix_3->setText("");
       }
       else
           msgbox.setText("Echec d'ajout");
       msgbox.exec();

}



void Dialog_Employes::on_pb_supprimer_clicked()
{
            Publicites P1;
            P1.setID_P(ui->lineEdit_id->text().toInt());
            QSqlQuery query ;
            query.prepare("Select * from publicites WHERE ID_P=:ID_P ");
            query.bindValue(":ID_P",P1.getID_P()) ;
            query.exec();
            bool alreadyExist = false;
                alreadyExist = query.next();
                if(alreadyExist)
                {
            bool test=P1.supprimer(P1.getID_P());
            QMessageBox msgbox;
            if(test)
                {msgbox.setText("Suppression avec succes.");
                    ui->tab_publicites->setModel(P.afficher());
                    ui->lineEdit_id->setText("");
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


void Dialog_Employes::on_pb_modifier_clicked()
{

    QSqlQuery query;
    QString ID_P=ui->le_id_update->text() ;
    query.prepare("Select * from publicites WHERE ID_P=:ID_P");
    query.bindValue(":ID_P", ID_P) ;
    query.exec() ;
    query.next() ;
    ui->le_nom_update->setText(query.value(1).toString());
    ui->la_date_update->setDate(query.value(2).toDate());
    ui->la_desc_update->setText(query.value(4).toString());
    ui->le_prix_update->setText(query.value(3).toString());

}

void Dialog_Employes::on_pb_entrer_clicked()
{
    int ID_P=ui->le_id_update->text().toInt();
    QString nom=ui->le_nom_update->text();
    QDate datep=ui->la_date_update->date();
    QString date_p=datep.toString("yyyy,dd,MM");
    QString description=ui->la_desc_update->text();
    int prix=ui->le_prix_update->text().toInt();
    Publicites P(ID_P,nom,datep,description,prix);
    QSqlQuery query ;
            query.prepare("Select * from publicites WHERE ID_P=:ID_P ");
            query.bindValue(":ID_P",ID_P) ;
            query.exec();
            bool alreadyExist = false;
                alreadyExist = query.next();
                if(alreadyExist)
                {
            bool test=P.modifier(P.getID_P());
            QMessageBox msgbox;
            if(test)
                {
                msgbox.setText("Modification avec succes.");
                    ui->tab_publicites->setModel(P.afficher());
                    ui->le_id_update->setText("");
                    ui->le_nom_update->setText("");
                    ui->la_date_update->setDate(datep);
                    ui->la_desc_update->setText("");
                    ui->le_prix_update->setText("");
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


void Dialog_Employes::on_pb_trier_clicked()
{
            Publicites P;
            QString crit=ui->comboBoxTri_2->currentText();
            if(crit=="ID_P")
            {
                ui->tab_publicites->setModel(P.tri_id());
            }
            else if(crit=="prix")
            {
                ui->tab_publicites->setModel(P.tri_prix());
            }
            else
            {
                ui->tab_publicites->setModel(P.tri_nom());
            }
}

void Dialog_Employes::on_radio_fb_clicked()
{
    QString link="https://www.facebook.com/Shine-On-Smartbeautycenter-102819531688261";
    QDesktopServices::openUrl(link);
}

void Dialog_Employes::on_radio_insta_clicked()
{
    QString link="https://www.instagram.com/?hl=fr";
    QDesktopServices::openUrl(link);
}

void Dialog_Employes::on_radio_whatsapp_clicked()
{
    QString link="https://www.whatsapp.com/?lang=fr";
    QDesktopServices::openUrl(link);

}

void Dialog_Employes::on_pb_PDF_clicked()
{

        QPdfWriter pdf("C:/Users/ryhab/OneDrive/Bureau/build-Atelier_Connexion-Desktop_Qt_5_9_9_MinGW_32bit-Debug/test1.pdf");

        QPainter painter(&pdf);

        int i = 4000;
        painter.setPen(Qt::blue);
        painter.setFont(QFont("Arial", 30));
        painter.drawText(3000,1500,"LISTE DES PUBLICITES");
        painter.setPen(Qt::black);
        painter.setFont(QFont("Arial", 50));
        // painter.drawText(1100,2000,afficheDC);
        painter.drawRect(2700,200,7300,2600);

        painter.drawRect(0,3000,9600,500);
        painter.setFont(QFont("Arial", 9));
        painter.drawText(300,3300,"ID_P");
        painter.drawText(2300,3300,"NOM");
        painter.drawText(4300,3300,"DATEP");
        painter.drawText(6300,3300,"DESCRIPTION");
        painter.drawText(8000,3300,"PRIX");
        QSqlQuery query;
        query.prepare("select * from publicites");
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
            QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/ryhab/OneDrive/Bureau/build-Atelier_Connexion-Desktop_Qt_5_9_9_MinGW_32bit-Debug/test1.pdf"));

            painter.end();
        }
        if (reponse == QMessageBox::No)
        {
            painter.end();
        }
}


void Dialog_Employes::on_lineEdit_textChanged(const QString &arg1)
{
    ui->tab_publicites->setModel(Pu.rechercher(arg1));
}



void Dialog_Employes::on_pb_imprimer_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(0,"Open File",QString(),"PDF File(*.pdf)");

                    /*QPrinter printer;
                    QPrintDialog *dlg = new QPrintDialog(&printer,0);
                    if(dlg->exec() == QDialog::Accepted) {
                    QImage pdf(fileName);
                    QPainter painter(&printer);
                    painter.drawImage(QPoint(0,0),pdf);
                    painter.end();
                    }

                    delete dlg;*/
}

//GESTION COMMANDES----------------------------------------------------------------------------

void Dialog_Employes::on_pb_ajouterCommande_clicked()
{

    int id=ui->le_id_4->text().toInt();
    int prix=ui->le_prix->text().toInt();
    QDate date_p=ui->le_date_passage_3->date();
   QString date_passage=date_p.toString("yyyy/dd/MM");
   QDate date_l=ui->le_date_livraison_3->date();
    QString date_livraison= date_l.toString("yyyy/dd/MM");





    Commande C (id,prix,date_passage,date_livraison);

bool test=C.Ajouter ();
    QMessageBox msgbox;

       if(test)

           {msgbox.setText("Ajout avec succes.");
           ui->tab_Commande->setModel(C.Afficher());
                      ui->le_id_4->setText("");
                      ui->le_prix->setText("");
C.notification("Commande ajoutée");

           }

           else

               msgbox.setText("Echec d'ajout");

           msgbox.exec();

}






void Dialog_Employes::on_pb_ModifierCommande_clicked()
{
    int id=ui->le_id_Modifier_3->text().toInt();
    int prix=ui->le_prix_Modifier_3->text().toInt();
    QDate date_p=ui->le_datep_Modifier_3->date();
   QString date_passage=date_p.toString("yyyy/dd/MM");
   QDate date_l=ui->le_datel_Modifier_3->date();
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
                ui->le_id_Modifier_3->setText("");
                ui->le_prix_Modifier_3->setText("");
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

void Dialog_Employes::on_pb_SupprimerCommande_clicked()
{

        Commande C1;
        C1.setid(ui->le_id_Supprimer_3->text().toInt());
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
                ui->le_id_Supprimer_3->setText("");
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


void Dialog_Employes::on_genererPdf_Commande_clicked()
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


void Dialog_Employes::on_lineEdit_textChangedCommande(const QString &arg1)
{
    Commande C ;
    ui->tab_Commande->setModel(C.rechercher(arg1));
}





void Dialog_Employes::on_checkBox_verifDate_clicked()
{
    /*QSqlQuery query;
    query.prepare("SELECT date_livraison from Services where date_livraison = current_date ");
    query.exec() ;
    if(query.next())
    {

        QMediaPlayer* player = new QMediaPlayer;

      player->setMedia(QUrl("C:/Users/leila/Downloads/Smart beauty center/Window Sms.mp3"));
        player->setVolume(50);
        player->play();
    }*/


}


void Dialog_Employes::on_pb_agenda_3_clicked()
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

void Dialog_Employes::on_pb_trierCommande_clicked()
{
    Commande C ;
                QString crit=ui->comboBoxTri_2->currentText();
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
