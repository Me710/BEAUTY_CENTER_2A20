/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *PBajouter;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QWidget *page_ajout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *LEnom;
    QLineEdit *LEprenom;
    QLineEdit *LEcin;
    QLineEdit *LEmail;
    QLineEdit *LEtel;
    QLineEdit *LEmontantd;
    QPushButton *pushButton_3;
    QPushButton *retour_1;
    QRadioButton *RBfemme;
    QRadioButton *RBhomme;
    QLabel *bg1;
    QPushButton *PBinsererPhoto;
    QLabel *label_photo;
    QWidget *page_modif1;
    QLabel *label_9;
    QPushButton *PBmodifier_2;
    QComboBox *CBmcin;
    QLabel *bg2;
    QWidget *page_modif2;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLineEdit *LEnomModif;
    QLineEdit *LEprenomModif;
    QLineEdit *LEcinModif;
    QLineEdit *LEmailModif;
    QLineEdit *LEmontantModif;
    QLineEdit *LEtelModif;
    QPushButton *PBconfirmModif;
    QLabel *label_16;
    QRadioButton *RBmfemme;
    QRadioButton *RBmhomme;
    QWidget *page_supp;
    QPushButton *PBsupprimer_2;
    QLabel *label_8;
    QComboBox *CBcin;
    QLabel *bg3;
    QWidget *page_affich;
    QTableView *tabClient;
    QPushButton *PBexport;
    QLineEdit *LEchercherCIN;
    QPushButton *PBtrouver;
    QCheckBox *CBmontant;
    QCheckBox *CBtel;
    QCheckBox *CBcin2;
    QLineEdit *LEchercherTel;
    QLineEdit *LEchercherMontant;
    QPushButton *PBclear;
    QPushButton *PBimprimer;
    QWidget *page_stat;
    QFrame *frame_stat;
    QPushButton *PBstatMontant;
    QPushButton *PBstatSexe;
    QLabel *label_17;
    QPushButton *PBafficher;
    QPushButton *PBmodifier;
    QPushButton *PBsupprimer;
    QLabel *bg4;
    QPushButton *PBstat;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1139, 792);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        PBajouter = new QPushButton(centralwidget);
        PBajouter->setObjectName(QStringLiteral("PBajouter"));
        PBajouter->setGeometry(QRect(10, 30, 230, 50));
        QFont font;
        font.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font.setPointSize(12);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        PBajouter->setFont(font);
        PBajouter->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setGeometry(QRect(250, 10, 871, 721));
        stackedWidget->setStyleSheet(QStringLiteral(""));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        stackedWidget->addWidget(page);
        page_ajout = new QWidget();
        page_ajout->setObjectName(QStringLiteral("page_ajout"));
        label = new QLabel(page_ajout);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 30, 240, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label->setFont(font1);
        label_2 = new QLabel(page_ajout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 80, 240, 30));
        label_2->setFont(font1);
        label_3 = new QLabel(page_ajout);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(40, 130, 240, 30));
        label_3->setFont(font1);
        label_4 = new QLabel(page_ajout);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(40, 180, 240, 30));
        label_4->setFont(font1);
        label_5 = new QLabel(page_ajout);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(40, 230, 240, 30));
        label_5->setFont(font1);
        label_6 = new QLabel(page_ajout);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(40, 270, 240, 41));
        label_6->setFont(font1);
        label_7 = new QLabel(page_ajout);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(40, 330, 240, 30));
        label_7->setFont(font1);
        LEnom = new QLineEdit(page_ajout);
        LEnom->setObjectName(QStringLiteral("LEnom"));
        LEnom->setGeometry(QRect(290, 20, 200, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Segoe UI"));
        font2.setPointSize(14);
        font2.setBold(false);
        font2.setWeight(50);
        LEnom->setFont(font2);
        LEprenom = new QLineEdit(page_ajout);
        LEprenom->setObjectName(QStringLiteral("LEprenom"));
        LEprenom->setGeometry(QRect(290, 70, 200, 40));
        LEprenom->setFont(font2);
        LEcin = new QLineEdit(page_ajout);
        LEcin->setObjectName(QStringLiteral("LEcin"));
        LEcin->setGeometry(QRect(290, 120, 200, 40));
        LEcin->setFont(font2);
        LEmail = new QLineEdit(page_ajout);
        LEmail->setObjectName(QStringLiteral("LEmail"));
        LEmail->setGeometry(QRect(290, 170, 200, 40));
        LEmail->setFont(font2);
        LEtel = new QLineEdit(page_ajout);
        LEtel->setObjectName(QStringLiteral("LEtel"));
        LEtel->setGeometry(QRect(290, 220, 200, 40));
        LEtel->setFont(font2);
        LEmontantd = new QLineEdit(page_ajout);
        LEmontantd->setObjectName(QStringLiteral("LEmontantd"));
        LEmontantd->setGeometry(QRect(290, 270, 200, 40));
        LEmontantd->setFont(font2);
        pushButton_3 = new QPushButton(page_ajout);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(230, 670, 191, 41));
        pushButton_3->setFont(font);
        pushButton_3->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        retour_1 = new QPushButton(page_ajout);
        retour_1->setObjectName(QStringLiteral("retour_1"));
        retour_1->setGeometry(QRect(20, 670, 191, 41));
        retour_1->setFont(font);
        retour_1->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        RBfemme = new QRadioButton(page_ajout);
        RBfemme->setObjectName(QStringLiteral("RBfemme"));
        RBfemme->setGeometry(QRect(280, 330, 150, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font3.setPointSize(14);
        font3.setBold(true);
        font3.setItalic(true);
        font3.setWeight(75);
        RBfemme->setFont(font3);
        RBhomme = new QRadioButton(page_ajout);
        RBhomme->setObjectName(QStringLiteral("RBhomme"));
        RBhomme->setGeometry(QRect(390, 330, 150, 40));
        RBhomme->setFont(font3);
        bg1 = new QLabel(page_ajout);
        bg1->setObjectName(QStringLiteral("bg1"));
        bg1->setGeometry(QRect(490, 620, 171, 101));
        bg1->setPixmap(QPixmap(QString::fromUtf8(":/img/hk2.png")));
        bg1->setScaledContents(true);
        PBinsererPhoto = new QPushButton(page_ajout);
        PBinsererPhoto->setObjectName(QStringLiteral("PBinsererPhoto"));
        PBinsererPhoto->setGeometry(QRect(490, 447, 131, 41));
        QFont font4;
        font4.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font4.setBold(true);
        font4.setWeight(75);
        PBinsererPhoto->setFont(font4);
        PBinsererPhoto->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        label_photo = new QLabel(page_ajout);
        label_photo->setObjectName(QStringLiteral("label_photo"));
        label_photo->setGeometry(QRect(300, 390, 160, 160));
        label_photo->setFrameShape(QFrame::WinPanel);
        label_photo->setFrameShadow(QFrame::Sunken);
        label_photo->setTextFormat(Qt::PlainText);
        label_photo->setScaledContents(true);
        stackedWidget->addWidget(page_ajout);
        page_modif1 = new QWidget();
        page_modif1->setObjectName(QStringLiteral("page_modif1"));
        label_9 = new QLabel(page_modif1);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(140, 90, 461, 31));
        label_9->setFont(font3);
        PBmodifier_2 = new QPushButton(page_modif1);
        PBmodifier_2->setObjectName(QStringLiteral("PBmodifier_2"));
        PBmodifier_2->setGeometry(QRect(400, 200, 171, 41));
        PBmodifier_2->setFont(font);
        PBmodifier_2->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        CBmcin = new QComboBox(page_modif1);
        CBmcin->setObjectName(QStringLiteral("CBmcin"));
        CBmcin->setGeometry(QRect(140, 200, 231, 41));
        CBmcin->setFont(font2);
        bg2 = new QLabel(page_modif1);
        bg2->setObjectName(QStringLiteral("bg2"));
        bg2->setGeometry(QRect(260, 290, 161, 181));
        bg2->setPixmap(QPixmap(QString::fromUtf8(":/img/hk3.png")));
        bg2->setScaledContents(true);
        stackedWidget->addWidget(page_modif1);
        page_modif2 = new QWidget();
        page_modif2->setObjectName(QStringLiteral("page_modif2"));
        label_10 = new QLabel(page_modif2);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(40, 30, 240, 30));
        label_10->setFont(font1);
        label_11 = new QLabel(page_modif2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(40, 80, 240, 30));
        label_11->setFont(font1);
        label_12 = new QLabel(page_modif2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(40, 130, 240, 30));
        label_12->setFont(font1);
        label_13 = new QLabel(page_modif2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(40, 180, 240, 30));
        label_13->setFont(font1);
        label_14 = new QLabel(page_modif2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(40, 230, 240, 30));
        label_14->setFont(font1);
        label_15 = new QLabel(page_modif2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(40, 270, 240, 41));
        label_15->setFont(font1);
        LEnomModif = new QLineEdit(page_modif2);
        LEnomModif->setObjectName(QStringLiteral("LEnomModif"));
        LEnomModif->setGeometry(QRect(290, 20, 200, 40));
        LEnomModif->setFont(font2);
        LEprenomModif = new QLineEdit(page_modif2);
        LEprenomModif->setObjectName(QStringLiteral("LEprenomModif"));
        LEprenomModif->setGeometry(QRect(290, 70, 200, 40));
        LEprenomModif->setFont(font2);
        LEcinModif = new QLineEdit(page_modif2);
        LEcinModif->setObjectName(QStringLiteral("LEcinModif"));
        LEcinModif->setGeometry(QRect(290, 120, 200, 40));
        LEcinModif->setFont(font2);
        LEmailModif = new QLineEdit(page_modif2);
        LEmailModif->setObjectName(QStringLiteral("LEmailModif"));
        LEmailModif->setGeometry(QRect(290, 170, 200, 40));
        LEmailModif->setFont(font2);
        LEmontantModif = new QLineEdit(page_modif2);
        LEmontantModif->setObjectName(QStringLiteral("LEmontantModif"));
        LEmontantModif->setGeometry(QRect(290, 270, 200, 40));
        LEmontantModif->setMinimumSize(QSize(200, 0));
        LEmontantModif->setFont(font2);
        LEtelModif = new QLineEdit(page_modif2);
        LEtelModif->setObjectName(QStringLiteral("LEtelModif"));
        LEtelModif->setGeometry(QRect(290, 220, 200, 40));
        LEtelModif->setFont(font2);
        PBconfirmModif = new QPushButton(page_modif2);
        PBconfirmModif->setObjectName(QStringLiteral("PBconfirmModif"));
        PBconfirmModif->setGeometry(QRect(10, 530, 201, 51));
        QFont font5;
        font5.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font5.setPointSize(10);
        font5.setBold(false);
        font5.setItalic(false);
        font5.setWeight(10);
        PBconfirmModif->setFont(font5);
        PBconfirmModif->setStyleSheet(QLatin1String("QPushButton {\n"
"	font: 81 10pt \"Playfair Display ExtraBold\";\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        label_16 = new QLabel(page_modif2);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(40, 330, 240, 30));
        label_16->setFont(font1);
        RBmfemme = new QRadioButton(page_modif2);
        RBmfemme->setObjectName(QStringLiteral("RBmfemme"));
        RBmfemme->setGeometry(QRect(280, 340, 120, 20));
        RBmfemme->setFont(font3);
        RBmhomme = new QRadioButton(page_modif2);
        RBmhomme->setObjectName(QStringLiteral("RBmhomme"));
        RBmhomme->setGeometry(QRect(390, 340, 120, 20));
        RBmhomme->setFont(font3);
        stackedWidget->addWidget(page_modif2);
        page_supp = new QWidget();
        page_supp->setObjectName(QStringLiteral("page_supp"));
        PBsupprimer_2 = new QPushButton(page_supp);
        PBsupprimer_2->setObjectName(QStringLiteral("PBsupprimer_2"));
        PBsupprimer_2->setGeometry(QRect(400, 200, 171, 41));
        QFont font6;
        font6.setFamily(QStringLiteral("Comic Sans MS"));
        font6.setPointSize(14);
        font6.setBold(false);
        font6.setWeight(50);
        PBsupprimer_2->setFont(font6);
        PBsupprimer_2->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        label_8 = new QLabel(page_supp);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(140, 90, 481, 41));
        label_8->setFont(font3);
        CBcin = new QComboBox(page_supp);
        CBcin->setObjectName(QStringLiteral("CBcin"));
        CBcin->setGeometry(QRect(140, 200, 231, 41));
        CBcin->setFont(font2);
        bg3 = new QLabel(page_supp);
        bg3->setObjectName(QStringLiteral("bg3"));
        bg3->setGeometry(QRect(270, 290, 161, 181));
        bg3->setPixmap(QPixmap(QString::fromUtf8(":/img/hk5.png")));
        bg3->setScaledContents(true);
        stackedWidget->addWidget(page_supp);
        page_affich = new QWidget();
        page_affich->setObjectName(QStringLiteral("page_affich"));
        tabClient = new QTableView(page_affich);
        tabClient->setObjectName(QStringLiteral("tabClient"));
        tabClient->setGeometry(QRect(20, 100, 621, 421));
        QFont font7;
        font7.setPointSize(12);
        tabClient->setFont(font7);
        tabClient->setStyleSheet(QStringLiteral(""));
        PBexport = new QPushButton(page_affich);
        PBexport->setObjectName(QStringLiteral("PBexport"));
        PBexport->setGeometry(QRect(382, 550, 101, 28));
        LEchercherCIN = new QLineEdit(page_affich);
        LEchercherCIN->setObjectName(QStringLiteral("LEchercherCIN"));
        LEchercherCIN->setGeometry(QRect(20, 60, 131, 22));
        PBtrouver = new QPushButton(page_affich);
        PBtrouver->setObjectName(QStringLiteral("PBtrouver"));
        PBtrouver->setGeometry(QRect(520, 30, 100, 20));
        CBmontant = new QCheckBox(page_affich);
        CBmontant->setObjectName(QStringLiteral("CBmontant"));
        CBmontant->setGeometry(QRect(350, 30, 131, 20));
        CBtel = new QCheckBox(page_affich);
        CBtel->setObjectName(QStringLiteral("CBtel"));
        CBtel->setGeometry(QRect(180, 30, 131, 20));
        CBcin2 = new QCheckBox(page_affich);
        CBcin2->setObjectName(QStringLiteral("CBcin2"));
        CBcin2->setGeometry(QRect(20, 30, 83, 20));
        LEchercherTel = new QLineEdit(page_affich);
        LEchercherTel->setObjectName(QStringLiteral("LEchercherTel"));
        LEchercherTel->setGeometry(QRect(180, 60, 141, 22));
        LEchercherMontant = new QLineEdit(page_affich);
        LEchercherMontant->setObjectName(QStringLiteral("LEchercherMontant"));
        LEchercherMontant->setGeometry(QRect(350, 60, 141, 22));
        PBclear = new QPushButton(page_affich);
        PBclear->setObjectName(QStringLiteral("PBclear"));
        PBclear->setGeometry(QRect(520, 60, 100, 20));
        PBimprimer = new QPushButton(page_affich);
        PBimprimer->setObjectName(QStringLiteral("PBimprimer"));
        PBimprimer->setGeometry(QRect(500, 550, 93, 28));
        stackedWidget->addWidget(page_affich);
        page_stat = new QWidget();
        page_stat->setObjectName(QStringLiteral("page_stat"));
        frame_stat = new QFrame(page_stat);
        frame_stat->setObjectName(QStringLiteral("frame_stat"));
        frame_stat->setGeometry(QRect(10, 10, 841, 631));
        frame_stat->setFrameShape(QFrame::StyledPanel);
        frame_stat->setFrameShadow(QFrame::Raised);
        PBstatMontant = new QPushButton(page_stat);
        PBstatMontant->setObjectName(QStringLiteral("PBstatMontant"));
        PBstatMontant->setGeometry(QRect(200, 670, 93, 28));
        PBstatSexe = new QPushButton(page_stat);
        PBstatSexe->setObjectName(QStringLiteral("PBstatSexe"));
        PBstatSexe->setGeometry(QRect(340, 670, 93, 28));
        label_17 = new QLabel(page_stat);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(70, 670, 121, 21));
        stackedWidget->addWidget(page_stat);
        PBafficher = new QPushButton(centralwidget);
        PBafficher->setObjectName(QStringLiteral("PBafficher"));
        PBafficher->setGeometry(QRect(10, 330, 230, 50));
        QFont font8;
        font8.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font8.setPointSize(12);
        font8.setBold(true);
        font8.setItalic(false);
        font8.setWeight(75);
        font8.setKerning(true);
        PBafficher->setFont(font8);
        PBafficher->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        PBmodifier = new QPushButton(centralwidget);
        PBmodifier->setObjectName(QStringLiteral("PBmodifier"));
        PBmodifier->setGeometry(QRect(10, 130, 230, 50));
        PBmodifier->setFont(font);
        PBmodifier->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        PBsupprimer = new QPushButton(centralwidget);
        PBsupprimer->setObjectName(QStringLiteral("PBsupprimer"));
        PBsupprimer->setGeometry(QRect(10, 230, 230, 50));
        PBsupprimer->setFont(font);
        PBsupprimer->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        bg4 = new QLabel(centralwidget);
        bg4->setObjectName(QStringLiteral("bg4"));
        bg4->setGeometry(QRect(40, 560, 151, 151));
        bg4->setPixmap(QPixmap(QString::fromUtf8(":/img/hk4.png")));
        bg4->setScaledContents(true);
        PBstat = new QPushButton(centralwidget);
        PBstat->setObjectName(QStringLiteral("PBstat"));
        PBstat->setGeometry(QRect(10, 430, 230, 50));
        QFont font9;
        font9.setFamily(QStringLiteral("Playfair Display ExtraBold"));
        font9.setPointSize(12);
        font9.setBold(true);
        font9.setWeight(75);
        PBstat->setFont(font9);
        PBstat->setStyleSheet(QLatin1String("QPushButton {\n"
"            color: white;\n"
"            border-image: url(:/img/bouton.png) 3 10 3 10;\n"
"\n"
"            border-top: 3px transparent;\n"
"            border-bottom: 3px transparent;\n"
"            border-right: 10px transparent;\n"
"            border-left: 10px transparent;\n"
"        }"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1139, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Gestion des clients", 0));
        PBajouter->setText(QApplication::translate("MainWindow", "Ajouter Client", 0));
        label->setText(QApplication::translate("MainWindow", "Nom", 0));
        label_2->setText(QApplication::translate("MainWindow", "Prenom", 0));
        label_3->setText(QApplication::translate("MainWindow", "CIN", 0));
        label_4->setText(QApplication::translate("MainWindow", "Mail", 0));
        label_5->setText(QApplication::translate("MainWindow", "Tel", 0));
        label_6->setText(QApplication::translate("MainWindow", "Montant Depenser", 0));
        label_7->setText(QApplication::translate("MainWindow", "Sexe", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Valider", 0));
        retour_1->setText(QApplication::translate("MainWindow", "<-Retour", 0));
        RBfemme->setText(QApplication::translate("MainWindow", "Femme", 0));
        RBhomme->setText(QApplication::translate("MainWindow", "Homme", 0));
        bg1->setText(QString());
        PBinsererPhoto->setText(QApplication::translate("MainWindow", "Parcourir", 0));
        label_photo->setText(QString());
        label_9->setText(QApplication::translate("MainWindow", "Veuillez choisir le CIN du client \303\240 modifier", 0));
        PBmodifier_2->setText(QApplication::translate("MainWindow", "modifier", 0));
        bg2->setText(QString());
        label_10->setText(QApplication::translate("MainWindow", "Nom", 0));
        label_11->setText(QApplication::translate("MainWindow", "Prenom", 0));
        label_12->setText(QApplication::translate("MainWindow", "CIN", 0));
        label_13->setText(QApplication::translate("MainWindow", "Mail", 0));
        label_14->setText(QApplication::translate("MainWindow", "Tel", 0));
        label_15->setText(QApplication::translate("MainWindow", "Montant Depenser", 0));
        PBconfirmModif->setText(QApplication::translate("MainWindow", "confirmer", 0));
        label_16->setText(QApplication::translate("MainWindow", "Sexe", 0));
        RBmfemme->setText(QApplication::translate("MainWindow", "Femme", 0));
        RBmhomme->setText(QApplication::translate("MainWindow", "Homme", 0));
        PBsupprimer_2->setText(QApplication::translate("MainWindow", "supprimer", 0));
        label_8->setText(QApplication::translate("MainWindow", "Veuillez choisir le CIN du client \303\240 supprimer", 0));
        bg3->setText(QString());
        PBexport->setText(QApplication::translate("MainWindow", "Exporter PDF", 0));
        PBtrouver->setText(QApplication::translate("MainWindow", "trouver", 0));
        CBmontant->setText(QApplication::translate("MainWindow", "Montant Depenser", 0));
        CBtel->setText(QApplication::translate("MainWindow", "NUMERO MOBILE", 0));
        CBcin2->setText(QApplication::translate("MainWindow", "CIN", 0));
        PBclear->setText(QApplication::translate("MainWindow", "clear", 0));
        PBimprimer->setText(QApplication::translate("MainWindow", "Imprimer", 0));
        PBstatMontant->setText(QApplication::translate("MainWindow", "Montant", 0));
        PBstatSexe->setText(QApplication::translate("MainWindow", "Sexe", 0));
        label_17->setText(QApplication::translate("MainWindow", "Make stats using:", 0));
        PBafficher->setText(QApplication::translate("MainWindow", "Afficher les Clients", 0));
        PBmodifier->setText(QApplication::translate("MainWindow", "Modifier Client", 0));
        PBsupprimer->setText(QApplication::translate("MainWindow", "Supprimer Client", 0));
        bg4->setText(QString());
        PBstat->setText(QApplication::translate("MainWindow", "Statistiques", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
