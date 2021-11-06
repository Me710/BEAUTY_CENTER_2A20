#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "employe.h"
#include <QMainWindow>

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

private:
    Ui::MainWindow *ui;
    Employe Empl;
};
#endif // MAINWINDOW_H
