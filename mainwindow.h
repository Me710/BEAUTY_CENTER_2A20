#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_Modifier_clicked();

    void on_pb_Supprimer_clicked();

private:
    Ui::MainWindow *ui;
    Commande C;
};

#endif // MAINWINDOW_H
