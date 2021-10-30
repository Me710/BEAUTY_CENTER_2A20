#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "client.h"

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
    void on_PBajouter_clicked();

    void on_PBmodifier_clicked();

    void on_PBsupprimer_clicked();

    void on_PBafficher_clicked();

    void on_retour_1_clicked();

    void on_pushButton_3_clicked();

    void on_PBsupprimer_2_clicked();

private:
    Ui::MainWindow *ui;
    Client cl;
};
#endif // MAINWINDOW_H
