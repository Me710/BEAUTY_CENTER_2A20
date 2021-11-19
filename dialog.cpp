#include "dialog.h"
#include "ui_dialog.h"
#include"produit.h"
#include<QMessageBox>
#include<QComboBox>
#include<QtGui>
#include<QIntValidator>
#include<QFileDialog>
#include<qrcode.h>

#include<QDesktopServices>
#include<QUrl>




Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->le_stock->setValidator(new QIntValidator(0,999,this));
    ui->le_code->setValidator(new QIntValidator(100,999999999,this));
    ui->le_prix->setValidator(new QIntValidator(0,99999,this));
    ui->la_qualite->setValidator(new QIntValidator(0,999,this));
    ui->tab_produit->setModel(P.afficher());
    ui->tab_recehreche->setModel(P.afficher());
    ui->comboBox->setModel(P.afficher_code());
    ui->comboBox_2->setModel(P.afficher_code());
    }

Dialog::~Dialog()
{
    delete ui;
}


void Dialog::on_valider_clicked()
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

void Dialog::on_supprimer_clicked()
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

void Dialog::on_pushButton_clicked()
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

void Dialog::on_update_clicked()
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

void Dialog::on_trier_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectu.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
   ui->tab_produit->setModel(P.tri_code());
}

void Dialog::on_tri_prix_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectu.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_produit->setModel(P.tri_prix());
}

void Dialog::on_tri_stock_clicked()
{
    QMessageBox::information(nullptr, QObject::tr("Ok"),
             QObject::tr("tri effectu.\n"
                         "Click Cancel to exit."), QMessageBox::Cancel);
    ui->tab_produit->setModel(P.tri_stock());
}

void Dialog::on_rechercher_clicked()
{

        {
             int code=ui->chercher->text().toInt();
             ui->tab_recehreche->setModel(P.recherche(code));
             QMessageBox::information(nullptr,QObject::tr("OK"),
                                       QObject::tr("recherche effectue.\n"
                                                   "clic cancel to exit."),QMessageBox::Cancel);
                    }

  }




            void Dialog::on_PDF_clicked()
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


void Dialog::on_wa_clicked()
{
    QString link="https://barcode.tec-it.com/fr/?data=15021383%0A";
     QDesktopServices::openUrl(QUrl(link));
}



void Dialog::on_inserer_photo_clicked()
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

void Dialog::on_qrcode_clicked()
{
    int tabeq=ui->tab_produit->currentIndex().row();
           QVariant idd=ui->tab_produit->model()->data(ui->tab_produit->model()->index(tabeq,0));
           //QString id= idd.toString();
           int code;
           QSqlQuery qry;
           qry.prepare("select * from PRODUIT where code=:code");
           qry.bindValue(":code",code);
           qry.exec();
              QString  iden,nom_for,nom_encadreur,type_for,dure_for,ide;

           while(qry.next()){

              code=qry.value(1).toString();
               nom_for=qry.value(2).toString();
               nom_encadreur=qry.value(3).toString();
               type_for=qry.value(4).toString();
               dure_for=qry.value(5).toString();


           }
           ide=QString(code);
                  ide="CODE_FORMATION:"+ide+"NOM_FOR:"+iden+"NOM_ENCADREUR:"+nom_encadreur+"TYPE_FOR:"+type_for,"DURE_FOR:"+dure_for;
           QrCode qr = QrCode::encodeText(ide.toUtf8().constData(), QrCode::Ecc::HIGH);

           // Read the black & white pixels
           QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
           for (int y = 0; y < qr.getSize(); y++) {
               for (int x = 0; x < qr.getSize(); x++) {
                   int color = qr.getModule(x, y);  // 0 for white, 1 for black

                   // You need to modify this part
                   if(color==0)
                       im.setPixel(x, y,qRgb(254, 254, 254));
                   else
                       im.setPixel(x, y,qRgb(0, 0, 0));
               }
           }
           im=im.scaled(200,200);
           ui->qrcodecommande->setPixmap(QPixmap::fromImage(im));
}
