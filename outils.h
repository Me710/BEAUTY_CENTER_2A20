#ifndef OUTILS_H
#define OUTILS_H

#include <QDialog>
#include "employe.h"

namespace Ui {
class Outils;
}

class Outils : public QDialog
{
    Q_OBJECT

public:
    explicit Outils(QWidget *parent = nullptr);
    ~Outils();

private slots:
    void on_pushButton_reinitialiser_mdp_clicked();

    void on_pushButton_inscription_clicked();

    void on_pushButton_valider_inscription_clicked();

private:
    Ui::Outils *ui;
    Employe Empl;
};

#endif // OUTILS_H
