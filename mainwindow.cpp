#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_employes.h"
#include <QMessageBox>
#include <QDebug>
#include "outils.h"

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

//Authentification
void MainWindow::on_pushButton_seConnecter_clicked()
{
    Dialog_Employes E;
    QSqlQuery query;
    /*QString username = ui->lineEdit_login->text();
    QString password = ui->lineEdit_motdepasse->text();*/

    query.prepare("select *from login where username=? and password=?");
    /*query.addBindValue(":username",username);
    query.addBindValue(":password",password);*/

    query.addBindValue(ui->lineEdit_login->text());
    query.addBindValue(ui->lineEdit_motdepasse->text());

    if(query.exec())
        {
            int count=0;
            while(query.next())
            {
                count++;
            }
            if(count==1)
            {
                ui->label_statuts->setText("Statuts: Mot de passe/Login correctes");
                hide();
                E.exec();
            }
            if(count<1)
            {
                QMessageBox::warning(this,"Authentification échoué","Mot de passe/Login incorrectes");
                ui->label_statuts->setText("Statuts: Mot de passe/Login incorrectes");
            }

        }
        else
        {
             QMessageBox::warning(this,"Probleme d'envoie de la requete!","Une erreur s'est produit lors du traitement de la requete!");
        }
}

void MainWindow::on_pushButton_outils_clicked()
{
    Outils O;
    O.exec();
}
