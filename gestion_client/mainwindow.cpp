#include <QIntValidator>
#include <QMessageBox>
#include "QString"
#include <QSqlQuery>
#include <QDebug>
#include <QFileDialog>
#include <QLabel>
#include <QPdfWriter>
#include <QPainter>
#include <QDesktopServices>
#include <QUrl>
#include <QPainter>
#include <QPrinter>
#include <QPrintDialog>
/*#include <QChartView>
#include <QPieSlice>
#include <QPieSeries>
#include <QBarSeries>
#include <QBarSet>
#include <QLegend>
#include <QBarCategoryAxis>
#include <QHorizontalBarSeries>
#include <QLineSeries>
#include <QCategoryAxis>*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "client.h"


//using namespace QtCharts;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->ui->stackedWidget->setCurrentIndex(0);
    ui->LEcin->setValidator(new QIntValidator(0, 999999999, this));
    ui->LEcinModif->setValidator(new QIntValidator(0, 999999999, this));
    ui->LEtel->setValidator(new QIntValidator(0, 99999999, this));
    ui->LEtelModif->setValidator(new QIntValidator(0, 99999999, this));
    ui->LEmontantd->setValidator(new QIntValidator(0, 99999999, this));
    ui->LEmontantModif->setValidator(new QIntValidator(0, 99999999, this));
    ui->LEmail->setValidator(new QRegExpValidator(QRegExp("[a-z0-9_]{1,99}\\S@[a-z]{1,99}\\S\\.[a-z]{1,99}\\S+")));
    ui->tabClient->setModel(cl.afficher());
    ui->CBcin->setModel(cl.afficher_cin());
    ui->CBmcin->setModel(cl.afficher_cin());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PBajouter_clicked()
{
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_PBmodifier_clicked()
{
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_PBsupprimer_clicked()
{
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_PBafficher_clicked()
{
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_pushButton_clicked()
{
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_retour_1_clicked()
{
    sound->play();
    this->ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_3_clicked()
{
    sound->play();
    QString nom=ui->LEnom->text();
    QString prenom=ui->LEprenom->text();
    int cin=ui->LEcin->text().toInt();
    QString mail=ui->LEmail->text();
    int tel=ui->LEtel->text().toUInt();
    int montantDepenser=ui->LEmontantd->text().toInt();
    QString sexe;
    if(ui->RBfemme->isChecked()){
        sexe="Femme";
    }
    else {
        sexe="Homme";
    }

    if(ui->LEnom->text().isEmpty()||ui->LEprenom->text().isEmpty()||ui->LEcin->text().isEmpty()||ui->LEmail->text().isEmpty()||ui->LEtel->text().isEmpty()||ui->LEmontantd->text().isEmpty())
            {
                QMessageBox::information(this,"Case vide","Merci de remplir toutes les cases");
                return;
            }

    Client c(nom, prenom, cin, mail, tel, sexe, montantDepenser);
    bool test=c.ajouter();
    if(test){
        QMessageBox::information(this,"Ajout","Ajout avec succes");
        ui->tabClient->setModel(cl.afficher());
        ui->CBcin->setModel(cl.afficher_cin());
        ui->CBmcin->setModel(cl.afficher_cin());
    }
    else
        QMessageBox::information(this,"Ajout","Echec d'ajout");
}

void MainWindow::on_PBsupprimer_2_clicked()
{
    sound->play();
    Client clRech;
    clRech.set_cin(ui->CBcin->currentText().toInt());
    bool test=clRech.supprimer(clRech.get_cin());


    if(test)
    {
        ui->CBcin->setModel(clRech.afficher_cin());
        QMessageBox::information(this,"Supp","Suppression avec succes");

        ui->tabClient->setModel(clRech.afficher());
        ui->CBcin->setModel(clRech.afficher_cin());
        ui->CBmcin->setModel(clRech.afficher_cin());
    }
    else
    {
        QMessageBox::information(this,"Supp","Echec de suppression");
    }
}

void MainWindow::on_PBmodifier_2_clicked()
{
    sound->play();
    QSqlQuery query;
    Client clRech2;
    //clRech2.set_cin(ui->CBmcin->currentText().toInt());
        QString cinSearched=ui->CBmcin->currentText();
    query.prepare(" select * from CLIENTS where CIN_C='"+cinSearched+"' ");
    if(query.exec())
    {
        while(query.next())
        {
            ui->LEnomModif->setText(query.value(0).toString());
            ui->LEprenomModif->setText(query.value(1).toString());
            ui->LEcinModif->setText(query.value(2).toString());
            ui->LEmailModif->setText(query.value(3).toString());
            ui->LEtelModif->setText(query.value(4).toString());
            QString testSexe = query.value(5).toString();
            if (testSexe=="homme"){
                ui->RBmhomme->setChecked(true);
            }
            else
            {
                ui->RBmfemme->setChecked(true);
            }
            ui->LEmontantModif->setText(query.value(6).toString());
        }
    }
    this->ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_PBconfirmModif_clicked()
{
    sound->play();
    QString nom=ui->LEnomModif->text();
    QString prenom=ui->LEprenomModif->text();
    int cin=ui->LEcinModif->text().toInt();
    QString mail=ui->LEmailModif->text();
    int tel=ui->LEtelModif->text().toUInt();
    int montantDepenser=ui->LEmontantModif->text().toInt();
    QString sexe;
    if(ui->RBmfemme->isChecked()){
        sexe="Femme";
    }
    else {
        sexe="Homme";
    }

    Client cl(nom, prenom, cin, mail, tel, sexe, montantDepenser);
    bool test=cl.modifier();

     if(test)
     {
         QMessageBox::information(this,"modif","Modification avec succès");
         ui->tabClient->setModel(cl.afficher());
         ui->CBcin->setModel(cl.afficher_cin());
         ui->CBmcin->setModel(cl.afficher_cin());
     }
     else
     {
         QMessageBox::information(this,"modif","Echec de modification");
     }
}


void MainWindow::on_PBexport_clicked()
{
    QPdfWriter pdf("C:/Users/Bellalouna Iheb/Desktop/Projet_QT_2021_2022/Smart_Beauty_Center/LIST.pdf");

    QPainter painter(&pdf);

    int i = 2500;

    painter.setPen(Qt::gray);
    painter.setFont(QFont("Segoe UI", 7));
    painter.drawText(600,300,"Adresse : 31 rue de Sfax El Menzeh 5");
    painter.drawText(600,500,"Tel : 71.100.100 / 90.900.900");
    painter.drawText(600,700,"Email: smartbeauty@gmail.com");

    painter.setPen(Qt::magenta);
    painter.setFont(QFont("Segoe UI", 50));
    painter.drawText(3500,1200,"Clients");

    painter.setPen(Qt::darkGray);
    painter.setBrush(Qt::BDiagPattern);
    painter.drawRect(0,1700,9200,500);
    painter.setFont(QFont("Segoe UI", 10));
    painter.drawText(200,2000,"CIN");
    painter.drawText(2500,2000,"NOM");
    painter.drawText(4600,2000,"PRENOM");
    painter.drawText(6000,2000,"TELEPHONE");
    painter.drawText(7900,2000,"ADRESSE MAIL");

    painter.setPen(Qt::black);
    QSqlQuery query;
    query.prepare("select * from CLIENTS");
    query.exec();
    while (query.next())
    {
        painter.drawText(200,i,query.value(2).toString());
        painter.drawText(2500,i,query.value(0).toString());
        painter.drawText(4600,i,query.value(1).toString());
        painter.drawText(6000,i,query.value(4).toString());
        painter.drawText(7900,i,query.value(3).toString());
        i = i +400;
    }

    int reponse = QMessageBox::question(this, "Génerer PDF", "<PDF Enregistré>...Vous Voulez Affichez Le PDF ?", QMessageBox::Yes |  QMessageBox::No);
    if (reponse == QMessageBox::Yes)
    {
        QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/Bellalouna Iheb/Desktop/Projet_QT_2021_2022/Smart_Beauty_Center/LIST.pdf"));

        painter.end();
    }
    if (reponse == QMessageBox::No)
    {
        painter.end();
    }

}

void MainWindow::on_PBinsererPhoto_clicked()
{
    QFileDialog dialog(this);
    dialog.setNameFilter(tr("Images (*.png *.xpm *.jpg)"));
    dialog.setViewMode(QFileDialog::Detail);
    QString fileName = QFileDialog::getOpenFileName(this,
    tr("Open Images"), "/home/rpi/Desktop/Picture/Sample Pictures", tr("Image Files (*.png *.jpg *.bmp)"));
    if (!fileName.isEmpty())
    {
        QImage image(fileName);
        ui->label_photo->setPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::on_PBtrouver_clicked()
{
    sound->play();
       if (ui->CBcin2->isChecked())
       {
           int cin=ui->LEchercherCIN->text().toInt();
           QSqlQueryModel *verif=cl.rechercher_cin(cin);
           if (verif!=nullptr)
           {
               ui->tabClient->setModel(verif);
           }
        }


       if (ui->CBtel->isChecked())
       {
           int tel=ui->LEchercherTel->text().toInt();
           QSqlQueryModel *verif=cl.rechercher_tel(tel);
           if (verif!=nullptr)
           {
               ui->tabClient->setModel(verif);
           }
        }

       if (ui->CBmontant->isChecked())
       {
           int montant=ui->LEchercherMontant->text().toInt();
           QSqlQueryModel *verif=cl.rechercher_montant(montant);
           if (verif!=nullptr)
           {
               ui->tabClient->setModel(verif);
           }
       }

       if ((ui->CBcin2->isChecked())&&(ui->CBtel->isChecked()))
       {
           int cin=ui->LEchercherCIN->text().toInt();
           int tel=ui->LEchercherTel->text().toInt();

           QSqlQueryModel *verif=cl.rechercher_cinTEL(cin, tel);
           if (verif!=nullptr)
           {
            ui->tabClient->setModel(verif);
           }

       }

       if ((ui->CBtel->isChecked())&&(ui->CBmontant->isChecked()))
          {
            int tel=ui->LEchercherTel->text().toInt();
            int montant=ui->LEchercherMontant->text().toInt();
            QSqlQueryModel *verif=cl.rechercher_telMONTANT(tel, montant);
            if (verif!=nullptr)
            {
                ui->tabClient->setModel(verif);
            }

       }

       if ((ui->CBcin2->isChecked())&&(ui->CBmontant->isChecked()))
       {
           int cin=ui->LEchercherCIN->text().toInt();
           int montant=ui->LEchercherMontant->text().toInt();
           QSqlQueryModel *verif=cl.rechercher_cinMONTANT(cin, montant);
                       if (verif!=nullptr)
                       {
                           ui->tabClient->setModel(verif);
                       }

    if ((ui->CBcin2->isChecked())&&(ui->CBtel->isChecked())&&(ui->CBmontant->isChecked()))
    {

        int cin=ui->LEchercherCIN->text().toInt();
        int tel=ui->LEchercherTel->text().toInt();
        int montant=ui->LEchercherMontant->text().toInt();
        QSqlQueryModel *verif=cl.rechercher_global(cin, tel, montant);
        if (verif!=nullptr)
        {
            ui->tabClient->setModel(verif);
        }
    } // else QMessageBox::warning(this,"erreur","Aucun critére n'est coché");
    }
}

void MainWindow::on_PBclear_clicked()
{
    sound->play();
    ui->LEchercherCIN->clear();
    ui->LEchercherTel->clear();
    ui->LEchercherMontant->clear();
    ui->CBcin2->setChecked(false);
    ui->CBtel->setChecked(false);
    ui->CBmontant->setChecked(false);
    ui->tabClient->setModel(cl.afficher());
}

void MainWindow::on_PBprint_clicked()
{


    QString fileName = QFileDialog::getOpenFileName(0,"Open File",QString(),"PDF File(*.pdf)");

            QPrinter printer;
            QPrintDialog *dlg = new QPrintDialog(&printer,0);
            if(dlg->exec() == QDialog::Accepted) {
                    QImage pdf(fileName);
                    QPainter painter(&printer);
                    painter.drawImage(QPoint(0,0),pdf);
                    painter.end();
            }

            delete dlg;

}

/*
void MainWindow::on_PBstatBar_clicked()
{
            QBarSet *set0 = new QBarSet("Client1");
            QBarSet *set1 = new QBarSet("Client2");
            QBarSet *set2 = new QBarSet("Client3");
            QBarSet *set3 = new QBarSet("Client4");
            QBarSet *set4 = new QBarSet("Client5");

            *set0 << 283 << 341 << 313 << 338 << 346 << 335;
            *set1 << 250 << 315 << 282 << 307 << 303 << 330;
            *set2 << 294 << 246 << 257 << 319 << 300 << 325;
            *set3 << 248 << 244 << 265 << 281 << 278 << 313;
            *set4 << 323 << 287 << 299 << 315 << 306 << 313;

            QBarSeries *series = new QBarSeries();

            series->append(set0);
            series->append(set1);
            series->append(set2);
            series->append(set3);
            series->append(set4);

            QChart *chart = new QChart();

            chart->addSeries(series);

            chart->setTitle("Montant depenser par tout nos clients");

            chart->setAnimationOptions(QChart::AllAnimations);

            QStringList categories;
            categories << "2013" << "2014" << "2015" << "2016" << "2017" << "2018";

            QBarCategoryAxis *axis = new QBarCategoryAxis();
            axis->append(categories);
            chart->createDefaultAxes();

            chart->setAxisX(axis, series);

            // 2. Stacked Bar chart
            // chart->setAxisY(axis, series);

            // Define where the legend is displayed
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignBottom);

            // Used to display the chart
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            // Used to change the palette
            QPalette pal = qApp->palette();

            // Change the color around the chart widget and text
            pal.setColor(QPalette::Window, QRgb(0xffffff));
            pal.setColor(QPalette::WindowText, QRgb(0x404044));

            // Apply palette changes to the application
            qApp->setPalette(pal);

            chartView->setParent(ui->frame_stat);
            chartView->resize(721,600);
            chartView->show();
}

void MainWindow::on_PBstatMontant_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENTS where MONTANT_DEPENSER between 10 and 199 ");
    float tranche_montant1=model->rowCount();
    model->setQuery("select * from CLIENTS where MONTANT_DEPENSER  between 200 and 499 ");
    float tranche_montant2=model->rowCount();
    model->setQuery("select * from CLIENTS where MONTANT_DEPENSER between 500 and 1000 ");
    float tranche_montant3=model->rowCount();
    float total=tranche_montant1+tranche_montant2+tranche_montant3;
    QString a=QString("Entre 10 et 199 ans . "+QString::number((tranche_montant1*100)/total,'f',2)+"%" );
    QString b=QString("Entre 200 et 499 ans .  "+QString::number((tranche_montant2*100)/total,'f',2)+"%" );
    QString c=QString("Entre 499 et 1000 ans ."+QString::number((tranche_montant3*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_montant1);
    series->append(b,tranche_montant2);
    series->append(c,tranche_montant3);
    if (tranche_montant1!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_montant2!=0)
    {
        QPieSlice *slice1 = series->slices().at(1);
        slice1->setLabelVisible();
    }
    if(tranche_montant3!=0)
    {
        QPieSlice *slice2 = series->slices().at(2);
        slice2->setExploded();
        slice2->setLabelVisible();
    }
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Montant depenser selon nombres clients: NB: "+ QString::number(total));
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    for(auto slice : series->slices())
        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));

    chartView->resize(721,600);
    chartView->setParent(ui->frame_stat);
    chartView->show();

}

void MainWindow::on_PBstatSexe_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from CLIENTS where SEXE='Femme' ");
    float tranche_femme=model->rowCount();
    model->setQuery("select * from CLIENTS where SEXE='Homme' ");
    float tranche_homme=model->rowCount();
    float total=tranche_femme+tranche_homme;
    QString a=QString("Femme . "+QString::number((tranche_femme*100)/total,'f',2)+"%" );
    QString b=QString("Homme . "+QString::number((tranche_homme*100)/total,'f',2)+"%" );
    QPieSeries *series = new QPieSeries();
    series->append(a,tranche_femme);
    series->append(b,tranche_homme);
    if (tranche_femme!=0)
    {QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible();
        slice->setPen(QPen());}
    if ( tranche_homme!=0)
    {
        QPieSlice *slice1 = series->slices().at(1);
        slice1->setLabelVisible();
    }

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Sexe des clients qui fréquente le centre selon nombre: NB: "+ QString::number(total));
    chart->legend()->hide();
    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    series->setLabelsVisible();
    series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

    for(auto slice : series->slices())
        slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));

    chartView->resize(721,600);
    chartView->setParent(ui->frame_stat);
    chartView->show();
}
*/
