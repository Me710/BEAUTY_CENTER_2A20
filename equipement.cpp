#include "equipement.h"
#include <QString>
#include<QtSql/QSqlQueryModel>
#include<QtSql/QSqlQuery>


using namespace std;

equipement::equipement()
{
   id=0;
   nom=" ";
   marque=" ";
   prix=0;
   etat=" ";

}

equipement::equipement(int id,QString nom,QString marque,int prix,QString etat)
{

   this->id=id;
   this->nom=nom.toUpper();
   this->marque=marque.toUpper();
   this->prix=prix;
   this->etat=etat.toUpper();

}
int equipement::get_id(){return id;}
void equipement::Set_nom(QString val) { nom = val; }
QString equipement::get_nom(){return nom;}
void equipement::Set_marque(QString val) { nom = val; }
QString equipement:: get_marque(){return marque;}
void equipement::Set_etat(QString val) { nom = val; }
QString equipement::get_etat(){return etat;}
void equipement::Set_prix(int val) { nom = val; }
int equipement::get_prix(){return prix;}



bool equipement::ajouter()
{
    QSqlQuery query;  //variable d'accees lel BD
    query.prepare("INSERT INTO equipement (id,nom,marque,prix,etat)"
                          "VALUES (:id, :nom, :marque, :prix, :etat)");  //thez mel classe li fel QT lel BD

    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    query.bindValue(":prix",prix);
    query.bindValue(":etat",etat);

    return query.exec();
}
QSqlQueryModel *equipement::afficher()
{
 QSqlQueryModel *model=new QSqlQueryModel();

 model->setQuery("select *from equipement");
 model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
 model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
 model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
 model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));
 return model;
}
bool equipement::supprimer(int idd)
{
    QSqlQuery query;
    query.prepare("Delete from equipement where ID = :id ");
    query.bindValue(":id",idd);
    return query.exec();

}
bool equipement :: modifier_equipement(   int id ,QString nom,QString marque,int prix,QString etat)
{

    QSqlQuery qry;
        qry.prepare("UPDATE equipement set NOM=(?),marque=(?),prix=(?),etat=(?) where ID=(?) ");


        qry.addBindValue(nom);
        qry.addBindValue(marque);
        qry.addBindValue(prix);
        qry.addBindValue(etat);
         qry.addBindValue(id);
   return  qry.exec();
}

QSqlQueryModel* equipement::trie()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from equipement ORDER BY prix asc");

        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));


    return model;
}

QSqlQueryModel* equipement::trie2()
{
    QSqlQueryModel* model = new QSqlQueryModel();

        model->setQuery("select *from equipement ORDER BY prix desc");

        model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
        model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
        model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
        model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
        model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));

    return model;
}

QSqlQueryModel * equipement::chercher_mat(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from equipement where ((id ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));
    return model;
}


QSqlQueryModel * equipement::chercher_mat1(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from equipement where ((etat ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));

    return model;
}

QSqlQueryModel * equipement::chercher_mat2(const QString &aux)
{
    QSqlQueryModel * model = new QSqlQueryModel();

    model->setQuery("select * from equipement where ((marque ) LIKE '%"+aux+"%')");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("marque"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("etat"));
    return model;
}

