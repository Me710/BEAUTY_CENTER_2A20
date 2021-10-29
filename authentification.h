#ifndef AUTHENTIFICATION_H
#define AUTHENTIFICATION_H

#include <QDialog>

namespace Ui {
class AUTHENTIFICATION;
}

class AUTHENTIFICATION : public QDialog
{
    Q_OBJECT

public:
    explicit AUTHENTIFICATION(QWidget *parent = nullptr);
    ~AUTHENTIFICATION();

private slots:
    void on_label_3_linkActivated(const QString &link);

private:
    Ui::AUTHENTIFICATION *ui;
};

#endif // AUTHENTIFICATION_H
