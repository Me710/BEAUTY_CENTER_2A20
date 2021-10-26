#ifndef DIALOG_EMPLOYES_H
#define DIALOG_EMPLOYES_H

#include <QDialog>

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
    void on_pushButton_valider_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_afficher_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_clicked();

private:
    Ui::Dialog_Employes *ui;
};

#endif // DIALOG_EMPLOYES_H
