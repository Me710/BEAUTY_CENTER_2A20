#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog_employes.h"

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


void MainWindow::on_pushButton_clicked()
{
    Dialog_Employes E;
    E.exec();


}
