#ifndef DIALOG_EMPLOYES_H
#define DIALOG_EMPLOYES_H

#include <QDialog>
#include "employe.h"

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


private:
    Ui::Dialog_Employes *ui;
    Employe Empl;
    QStringList getRecipientsAddress(QString str);
};

#endif // DIALOG_EMPLOYES_H
