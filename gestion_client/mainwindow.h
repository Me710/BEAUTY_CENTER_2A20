#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtMultimedia/qsound.h>
#include <QMainWindow>
#include "client.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    QSound *sound= new QSound("C:/Users/Bellalouna Iheb/Desktop/Projet_QT_2021_2022/Smart_Beauty_Center/image/click.wav");

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_PBajouter_clicked();

    void on_PBmodifier_clicked();

    void on_PBsupprimer_clicked();

    void on_PBafficher_clicked();

    void on_retour_1_clicked();

    void on_pushButton_3_clicked();

    void on_PBsupprimer_2_clicked();

    void on_PBmodifier_2_clicked();

    void on_PBconfirmModif_clicked();

    void on_PBexport_clicked();

    void on_PBinsererPhoto_clicked();

    void on_PBtrouver_clicked();

    void on_PBclear_clicked();

    void on_PBprint_clicked();

    void on_pushButton_clicked();

    void on_PBstatBar_clicked();

    void on_PBstatMontant_clicked();

    void on_PBstatSexe_clicked();

private:
    Ui::MainWindow *ui;
    Client cl;
};
#endif // MAINWINDOW_H
