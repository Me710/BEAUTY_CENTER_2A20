#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_employes.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    Dialog_Employes E;
    QString login = ui->lineEdit_login->text();
        QString motdepasse = ui->lineEdit_motdepasse->text();

        if(login == "admin" && motdepasse == "admin")
        {
            QMessageBox::information(this,"Authentification reussie", "Login et mot de passe correctes");
            hide();
            E.exec();

        }
        else
        {
            QMessageBox::warning(this,"Authentification échoué","Mot de passe/Login incorrectes");
        }
}
