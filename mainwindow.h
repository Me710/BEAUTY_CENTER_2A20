#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>
#include "connection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_seConnecter_clicked();

    void on_pushButton_outils_clicked();

    void on_pushButton_reinitialiser_mdp_clicked();

    void on_pushButton_inscription_clicked();

    void on_pushButton_valider_inscription_clicked();

    void on_pushButton_accueil_clicked();

    void on_pushButton_changer_mdp_clicked();

    void on_pb_se_connecter_admin_clicked();

    void on_retour_3_clicked();

    void on_retour_1_clicked();

    void on_retour_2_clicked();

private:
    Ui::MainWindow *ui;
    Employe Empl;
    connection C;
};
#endif // MAINWINDOW_H
