#ifndef DIALOG_EMPLOYES_H
#define DIALOG_EMPLOYES_H

#include <QDialog>
#include "employe.h"
#include "arduino.h"
#include "gestion_produit/produit.h"
#include "gestion_produit/qrcode.h"

namespace Ui {
class Dialog_Employes;
}

class Dialog_Employes : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Employes(QWidget *parent = nullptr);
    ~Dialog_Employes();

private slots:

    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_deconnection_clicked();

    void on_pushButton_valider_modification_clicked();

    void on_pushButton_valider_suppression_clicked();

    void on_pushButton_valider_ajout_clicked();

    void on_pushButton_verifier_supprimer_clicked();

    void on_pushButton_mailing_clicked();

    void on_pushButton_rechercher_empl_clicked();

    void on_comboBox_cin_modif_currentIndexChanged(int index);

    void on_pushButton_pdf_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_pushButton_filtre_clicked();

    void on_tb_getAttach1_clicked();

    void on_tb_getAttach2_clicked();

    void on_tb_getAttach3_clicked();

    void on_tb_getAttach4_clicked();

    void on_envoyer_mail_clicked();


    void on_comboBox_2_currentIndexChanged(int index);

    void update_label();

    void on_ajouter_carte_clicked();

    void on_comboBox_id_employe_currentIndexChanged(int index);

    void on_valider_carte_rfid_clicked();


    //Pour la gestion des produits
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

    //void on_comboBox_currentIndexChanged(int index);

    //void on_comboBox_2_currentIndexChanged(int index);

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


private:
    Ui::Dialog_Employes *ui;
    Employe Empl;
    QStringList getRecipientsAddress(QString str);
    Arduino A;
    QByteArray data;
    Produit P;
};

#endif // DIALOG_EMPLOYES_H
