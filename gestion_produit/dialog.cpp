#include "dialog.h"
#include "ui_dialog.h"
#include"produit.h"
#include<QMessageBox>
#include<QComboBox>
#include<QtGui>
#include<QIntValidator>
#include<QFileDialog>

#include<QDesktopServices>
#include<QUrl>




Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}


