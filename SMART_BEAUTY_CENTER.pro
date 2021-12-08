QT       += core gui sql network serialport multimedia
QT       += core gui sql printsupport multimedia
QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    arduino.cpp \
    connection.cpp \
    dialog_employes.cpp \
    employe.cpp \
    equipement.cpp \
    gestion_client/client.cpp \
    gestion_commande/commande.cpp \
    gestion_produit/produit.cpp \
    gestion_produit/qrcode.cpp \
    gestion_pub/publicites.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    mail/emailaddress.cpp \
    mail/mimeattachment.cpp \
    mail/mimecontentformatter.cpp \
    mail/mimefile.cpp \
    mail/mimehtml.cpp \
    mail/mimeinlinefile.cpp \
    mail/mimemessage.cpp \
    mail/mimemultipart.cpp \
    mail/mimepart.cpp \
    mail/mimetext.cpp \
    mail/quotedprintable.cpp \
    mail/smtpclient.cpp

HEADERS += \
    arduino.h \
    connection.h \
    dialog_employes.h \
    employe.h \
    equipement.h \
    gestion_client/client.h \
    gestion_commande/commande.h \
    gestion_produit/produit.h \
    gestion_produit/qrcode.h \
    gestion_pub/publicites.h \
    login.h \
    mainwindow.h \
        mail/SmtpMime \
        mail/emailaddress.h \
        mail/mimeattachment.h \
    mail/mimecontentformatter.h \
    mail/mimefile.h \
    mail/mimehtml.h \
    mail/mimeinlinefile.h \
    mail/mimemessage.h \
    mail/mimemultipart.h \
    mail/mimepart.h \
    mail/mimetext.h \
    mail/quotedprintable.h \
    mail/smtpclient.h

FORMS += \
    dialog_employes.ui \
    mainwindow.ui \

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    gestion_pub/translations.qrc

DISTFILES += \
    gestion_pub/anglais.qm \
    gestion_pub/anglais.ts \
    gestion_pub/arabic.qm \
    gestion_pub/arabic.ts \
    gestion_pub/espagnol.qm \
    gestion_pub/espagnol.ts
