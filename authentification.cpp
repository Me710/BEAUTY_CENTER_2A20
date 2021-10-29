#include "authentification.h"
#include "ui_authentification.h"

AUTHENTIFICATION::AUTHENTIFICATION(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AUTHENTIFICATION)
{
    ui->setupUi(this);
}

AUTHENTIFICATION::~AUTHENTIFICATION()
{
    delete ui;
}

void AUTHENTIFICATION::on_label_3_linkActivated(const QString &link)
{

}
