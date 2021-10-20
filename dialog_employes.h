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

private:
    Ui::Dialog_Employes *ui;
};

#endif // DIALOG_EMPLOYES_H
