#include "dialog_employes.h"
#include "ui_dialog_employes.h"

Dialog_Employes::Dialog_Employes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Employes)
{
    ui->setupUi(this);
}

Dialog_Employes::~Dialog_Employes()
{
    delete ui;
}
