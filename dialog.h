#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include"produit.h"
namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_ajouter_clicked();

    void on_bt_ajouter_clicked();

    void on_valider_clicked();

    void on_pushButton_clicked();

    void on_tab_produit_activated(const QModelIndex &index);

    void on_tabWidget_currentChanged(int index);

    void on_supprimer_clicked();

    void on_update_clicked();

    void on_combo_currentIndexChanged(const QString &arg1);

    void on_combo_activated(const QString &arg1);

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

private:
    Ui::Dialog *ui;
    Produit P;
};

#endif // DIALOG_H
