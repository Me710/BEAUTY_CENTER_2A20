#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"produit.h"
#include"dialog.h"
#include<QFile>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::on_pp_ajouter_clicked()
{
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}
*/
void MainWindow::on_pushButton_clicked()
{
    Dialog dialog;
    dialog.setModal(true);
    dialog.exec();
}
