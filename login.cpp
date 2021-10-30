#include "login.h"
#include "ui_login.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include <QMessageBox>
#include <QSqlQuery>
#include <QDebug>

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
}

Login::~Login()
{
    delete ui;
}

void Login::on_PBconnexion_clicked()
{
    QString username =ui->LEidentifiant->text();
    QString Password =ui->LEmotdepasse->text();
       if (username=="admin" && Password=="admin")
            {
                close();
                mainwindow = new MainWindow(this);
                close();
                mainwindow->show();
            }

       else if (username!="admin" || Password!="admin")
            {
                QMessageBox::information(this,"Login","Identifiant OU Mot de passe incorrect");
            }


}
