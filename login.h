#ifndef LOGIN_H
#define LOGIN_H

#include <QString>
#include <QSqlQueryModel>

class Login
{
public:
    Login();
    Login(QString,QString);
    ~Login(){}
    void set_password(QString password){this->password=password;}
    QString get_password(){return password;}
    void set_username(QString username){this->username=username;}
    QString get_username(){return username;}
    void set_code(QString code){this->code=code;}
    QString get_code(){return code;}

    bool ajouterLogin();
    bool modifierLogin();
    QSqlQueryModel* afficherUsername();


private:
    QString username;
    QString password;
    QString code;
};


#endif // LOGIN_H
