/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Login
{
public:
    QLineEdit *LEidentifiant;
    QLabel *label_Login_img1;
    QPushButton *PBconnexion;
    QLineEdit *LEmotdepasse;

    void setupUi(QDialog *Login)
    {
        if (Login->objectName().isEmpty())
            Login->setObjectName(QStringLiteral("Login"));
        Login->resize(600, 340);
        LEidentifiant = new QLineEdit(Login);
        LEidentifiant->setObjectName(QStringLiteral("LEidentifiant"));
        LEidentifiant->setGeometry(QRect(190, 130, 211, 31));
        QFont font;
        font.setPointSize(11);
        LEidentifiant->setFont(font);
        LEidentifiant->setAlignment(Qt::AlignCenter);
        label_Login_img1 = new QLabel(Login);
        label_Login_img1->setObjectName(QStringLiteral("label_Login_img1"));
        label_Login_img1->setGeometry(QRect(240, 10, 100, 111));
        label_Login_img1->setPixmap(QPixmap(QString::fromUtf8(":/img/loginImg1.png")));
        PBconnexion = new QPushButton(Login);
        PBconnexion->setObjectName(QStringLiteral("PBconnexion"));
        PBconnexion->setGeometry(QRect(220, 290, 141, 31));
        QFont font1;
        font1.setPointSize(10);
        PBconnexion->setFont(font1);
        LEmotdepasse = new QLineEdit(Login);
        LEmotdepasse->setObjectName(QStringLiteral("LEmotdepasse"));
        LEmotdepasse->setGeometry(QRect(190, 170, 211, 31));
        LEmotdepasse->setFont(font);
        LEmotdepasse->setInputMethodHints(Qt::ImhHiddenText|Qt::ImhNoAutoUppercase|Qt::ImhNoPredictiveText|Qt::ImhSensitiveData);
        LEmotdepasse->setEchoMode(QLineEdit::Password);
        LEmotdepasse->setAlignment(Qt::AlignCenter);
        QWidget::setTabOrder(PBconnexion, LEidentifiant);
        QWidget::setTabOrder(LEidentifiant, LEmotdepasse);

        retranslateUi(Login);

        QMetaObject::connectSlotsByName(Login);
    } // setupUi

    void retranslateUi(QDialog *Login)
    {
        Login->setWindowTitle(QApplication::translate("Login", "Dialog", 0));
#ifndef QT_NO_TOOLTIP
        LEidentifiant->setToolTip(QApplication::translate("Login", "<html><head/><body><p>Identifiant</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        LEidentifiant->setWhatsThis(QApplication::translate("Login", "<html><head/><body><p><br/></p></body></html>", 0));
#endif // QT_NO_WHATSTHIS
        LEidentifiant->setText(QString());
        LEidentifiant->setPlaceholderText(QApplication::translate("Login", "Identifiant/CIN", 0));
        label_Login_img1->setText(QString());
        PBconnexion->setText(QApplication::translate("Login", "Connexion", 0));
#ifndef QT_NO_TOOLTIP
        LEmotdepasse->setToolTip(QApplication::translate("Login", "<html><head/><body><p>Mot de passe</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        LEmotdepasse->setText(QString());
        LEmotdepasse->setPlaceholderText(QApplication::translate("Login", "Mot de passe", 0));
    } // retranslateUi

};

namespace Ui {
    class Login: public Ui_Login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
