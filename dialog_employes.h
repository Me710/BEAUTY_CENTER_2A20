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

private:
    Ui::Dialog_Employes *ui;
    Employe Empl;
};

#endif // DIALOG_EMPLOYES_H
