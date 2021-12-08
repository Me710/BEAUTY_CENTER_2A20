#ifndef equipement_H
#define equipement_H
#include <QString>
#include<QtSql/QSqlQuery>
#include"QtSql/QSqlDatabase"
#include<QtSql/QSqlQueryModel>

#include <QDebug>


class equipement
{
public:
    equipement();
    equipement(int,QString,QString,int,QString);
    int get_id();
    void Set_nom(QString val) ;
    QString get_nom();
    void Set_marque(QString val) ;
    QString get_marque();
    void Set_etat(QString val) ;
    QString get_etat();
    void Set_prix(int val) ;
    int get_prix();
    QSqlQuery rechercher_id(int id);
    bool ajouter();
    bool  modifier_equipement(int,QString,QString,int,QString);
    bool supprimer(int idd);
    QSqlQueryModel * afficher();
    QSqlQueryModel* trie();
    QSqlQueryModel* trier(const QString, const QString);
    QSqlQueryModel* trie2();
    QSqlQueryModel *chercher_mat(const QString &aux);
    QSqlQueryModel *chercher_mat1(const QString &aux);
    QSqlQueryModel *chercher_mat2(const QString &aux);
private:
    int id;
    QString nom;
    QString marque;
    QString etat;
    int prix;
};

#endif // equipement_H
