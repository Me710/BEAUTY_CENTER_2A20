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

    void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

    void on_rechercher_clicked();

    void on_trier_clicked();

    void on_tri_prix_clicked();

    void on_tri_stock_clicked();

    void on_PDF_clicked();

    void on_fichier_linkActivated(const QString &link);

    void on_chercher_cursorPositionChanged(int arg1, int arg2);

    void on_chercher_textChanged();

    void on_Qr_code_clicked();

    void on_code_barre_clicked();

    void on_wa_clicked();

    void on_img_label_linkActivated();

    void on_inserer_photo_clicked();

    void on_qrcode_clicked();

private:
    Ui::Dialog *ui;
    Produit P;
};

#endif // DIALOG_H
