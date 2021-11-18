#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "connection.h"
#include "login.h"

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

    void on_pushButton_accueil_clicked();

    void on_pushButton_changer_mdp_clicked();

    void on_pb_se_connecter_admin_clicked();

    void on_retour_3_clicked();

    void on_retour_1_clicked();

    void on_retour_2_clicked();

    void on_pb_accueil_clicked();

    void on_envoyer_code_clicked();

    void on_pb_reinitialiser_clicked();

    void on_envoyer_un_code_clicked();

    void on_valider_ajout_login_clicked();

    void on_pb_changer_mdp_clicked();

private:
    Ui::MainWindow *ui;
    Login L;
    connection C;
    QStringList getRecipientsAddress(QString str);
};
#endif // MAINWINDOW_H
