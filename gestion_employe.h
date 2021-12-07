#ifndef GESTION_EMPLOYE_H
#define GESTION_EMPLOYE_H

#include <QWidget>

namespace Ui {
class Gestion_employe;
}

class Gestion_employe : public QWidget
{
    Q_OBJECT

public:
    explicit Gestion_employe(QWidget *parent = nullptr);
    ~Gestion_employe();

private:
    Ui::Gestion_employe *ui;
};

#endif // GESTION_EMPLOYE_H
