#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_employes.h"
#include <QMessageBox>
#include <QDebug>
#include "employe.h"
#include "connection.h"
#include "mail/SmtpMime"
#include <QDebug>
#include <random>
#include <ctime>

constexpr int MAX = 1000000;

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
        ui->comboBox_login->setModel(L.afficherUsername());
        ui->comboBox_login_rein->setModel(L.afficherUsername());
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


QStringList MainWindow::getRecipientsAddress(QString str)
{

    QStringList recipients;

    recipients = str.split(QRegExp(";"));

    return recipients;
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
                E.setModal(true);
                E.exec();
                QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("conncetion sucessful.""Click Cancel to exit."),QMessageBox::Cancel);
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
}

void MainWindow::on_pushButton_accueil_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::on_pushButton_changer_mdp_clicked(){ui->stackedWidget_2->setCurrentIndex(1);}

void MainWindow::on_pb_se_connecter_admin_clicked()
{
    QString username=ui->login_admin->text();
    QString password=ui->mot_de_passe_admin->text();

    if(username=="admin" && password=="admin")
    {
        ui->stackedWidget_2->setCurrentIndex(4);
        ui->login_admin->clear();
        ui->mot_de_passe_admin->clear();
    }
    else
    {
        QMessageBox::critical(this,"MOT DE PASSE/LOGIN INCORRECTES","VERIFIER LE MOT DE PASSE/ LOGIN");
    }

}

void MainWindow::on_retour_3_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_retour_1_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_retour_2_clicked(){ui->stackedWidget_2->setCurrentIndex(4);}

void MainWindow::on_pb_accueil_clicked(){ui->stackedWidget->setCurrentIndex(0);}

void MainWindow::on_envoyer_code_clicked()
{
    QString username=ui->comboBox_login_rein->currentText();
    SmtpClient smtp("smtp.gmail.com",465, SmtpClient::SslConnection);
    smtp.setUser("nebotchristian7@gmail.com");
    smtp.setPassword("nebotfonkou");

    std::srand(std::time(nullptr));

    long rand_code;
    rand_code = rand() % MAX;
    L.set_code(QString::number(rand_code));

    MimeMessage message;

    EmailAddress sender("nebotchristian7@gmail.com","SHINE ON BEAUTY CENTER");
    message.setSender(&sender);

    QStringList to = getRecipientsAddress("nebotchristian6@gmail.com");

    for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
         message.addRecipient(new EmailAddress(*it),MimeMessage::To);
    }

    //set message subject
    message.setSubject("CODE DE REINITIALISATION MOT DE PASSE");

    MimeText text;
    QString messagetext = "Le Code de reinitialisation du login avec USERNAME: " ;
    messagetext=messagetext+username+" est: "+L.get_code();
    text.setText(messagetext);
    message.addPart(&text);

     if (!smtp.connectToHost()) {
         QMessageBox::critical(this,"Failed to connect","Cannot connect to host");
     }

     if (!smtp.login()) {
         QMessageBox::critical(this,"Failed to connect","Failed to login");
     }

     if(smtp.sendMail(message))
     {
          ui->message_code->setText("Un code de validation à été envoyer par mail à l'administrateur du system\nVeuillez remplir ce code dans l'espace pour reinitialiser le mot de passe!");
     }
     else
     {
          ui->message_code->setText("Erreurs\nVeuillez contacter le developpeur de l'application");
     }

     smtp.quit();


}

void MainWindow::on_pb_reinitialiser_clicked()
{
    QString code=ui->code_rein->text();
    QString username=ui->comboBox_login_rein->currentText();
    QString motdepasse=username+QString::number(rand() % 3000);
    QString message="Le nouveau mot de passe du compte est: "+motdepasse;

    L.set_username(username);
    L.set_password(motdepasse);

    if(code==L.get_code())
    {
        ui->code_rein->clear();
        ui->message_code->clear();
        if(L.modifierLogin())
        {
            QMessageBox::information(this,"REINITIALISATION REUSSIE",message);
        }

    }
    else
    {
        ui->message_code->setText("Code Erronné, Verifier le code à nouveau ou cliquer sur 'ENVOYER CODE' pour recevoir un nouveau code!");
        ui->code_rein->clear();
    }
}

void MainWindow::on_envoyer_un_code_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_mdp->text();
    QString password2=ui->lineEdit_mdp2->text();

    if(password==password2)
    {
        ui->label_verification_infos->clear();
        SmtpClient smtp("smtp.gmail.com",465, SmtpClient::SslConnection);
        smtp.setUser("nebotchristian7@gmail.com");
        smtp.setPassword("nebotfonkou");

        std::srand(std::time(nullptr));

        L.set_code(QString::number(rand() % MAX));

        MimeMessage message;

        EmailAddress sender("nebotchristian7@gmail.com","SHINE ON BEAUTY CENTER");
        message.setSender(&sender);

        QStringList to = getRecipientsAddress("nebotchristian6@gmail.com");

        for (QStringList::iterator it = to.begin();it != to.end(); ++it) {
             message.addRecipient(new EmailAddress(*it),MimeMessage::To);
        }

        //set message subject
        message.setSubject("CODE DE VALIDATION D'AJOUT DE LOGIN");

        MimeText text;
        QString messagetext = "Le Code de validation du login avec USERNAME: " ;
        messagetext=messagetext+username+" est: "+L.get_code();
        text.setText(messagetext);
        message.addPart(&text);

         if(!smtp.connectToHost()) {
             QMessageBox::critical(this,"Failed to connect","Cannot connect to host");
         }

         if(!smtp.login()) {
             QMessageBox::critical(this,"Failed to connect","Failed to login");
         }

         if(smtp.sendMail(message))
         {
              ui->code_notif->setText("Veuillez renseigner le champs code avec le code envoyer par mail!");
         }
         else
         {
              ui->code_notif->setText("Erreurs\nVeuillez contacter le developpeur de l'application");
         }

         smtp.quit();

    }
    else
    {
        ui->label_verification_infos->setText("Mot de passe de confirmation different");
    }


}

void MainWindow::on_valider_ajout_login_clicked()
{
    QString username=ui->lineEdit_username->text();
    QString password=ui->lineEdit_mdp->text();
    QString code=ui->code_valid->text();


        L.set_username(username);
        L.set_password(password);

        if(code==L.get_code())
        {
            ui->code_valid->clear();
            ui->label_verification_infos->clear();
            ui->code_notif->clear();

            if(L.ajouterLogin())
            {
                QMessageBox::information(this,"OK","Login Créé avec succes\n");
                ui->comboBox_login->setModel(L.afficherUsername());
                ui->comboBox_login_rein->setModel(L.afficherUsername());
                ui->lineEdit_username->clear();
                ui->lineEdit_mdp->clear();
                ui->lineEdit_mdp2->clear();
            }
            else
            {
                QMessageBox::critical(this,"NOT OK","Echec de création du Login");
            }

        }
        else
        {
            ui->code_verif->setText("Code Erronné, Verifier le code à nouveau ou cliquer sur 'ENVOYER CODE' pour recevoir un nouveau code!");
            ui->code_valid->clear();

        }

}

void MainWindow::on_pb_changer_mdp_clicked()
{
    QString username=ui->comboBox_login->currentText();
    QString oldpassword=ui->anc_mdp->text();
    //QString password=ui->*/
}
