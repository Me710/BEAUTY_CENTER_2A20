#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "commande.h"
#include <QMainWindow>
#include <QMediaPlayer>

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

    void on_pushButton_2_clicked() ;

    void on_lineEdit_textChanged(const QString &arg1);

    void on_checkBox_verifDate_clicked();

    void on_pb_agenda_clicked();

    void on_pb_trie_clicked();

private:
    Ui::MainWindow *ui;
    Commande C;
};

#endif // MAINWINDOW_H
