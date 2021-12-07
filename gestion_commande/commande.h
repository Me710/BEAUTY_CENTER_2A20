#ifndef COMMANDE_H
#define COMMANDE_H
#include<QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QDate>
class Commande
{
public:
    Commande();
    Commande(int,int,QString,QString);
    int getid();
    int getprix();
   QString getdate_passage();
    QString getdate_livraison();
    void setid(int);
    void setprix(int);
    void setdate_passage(QString);
    void setdate_livraison(QString);
    bool Ajouter();
    bool Supprimer(int);
    QSqlQueryModel* Afficher();
    bool Modifier();
    QSqlQueryModel *tri_id();
    QSqlQueryModel *tri_prix();
    QSqlQueryModel *tri_date();
    QSqlQueryModel *rechercher(QString);
    void notification(QString);
    void Write_on_file();
    void Signal ();

private:
    int id ;
    int prix;
    QString date_passage ;
    QString date_livraison ;


};




#endif // COMMANDE_H
