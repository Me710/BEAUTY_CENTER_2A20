#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"produit.h"
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
    void on_pushButton_clicked();

    void on_label_linkActivated(const QString &link);

    void on_pushButton_4_clicked();

    void on_pp_ajouter_clicked();

    void on_pp_affiche_clicked();

    void on_VALIDER_clicked();

private:
    Ui::MainWindow *ui;
    Produit P;
};
#endif // MAINWINDOW_H
