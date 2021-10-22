#include "employe.h"
#include <iostream>
#include <QString>

using namespace std;

Employe::Employe()
{

}
Employe::~Employe()
{

}
void Employe::set_cin(int cin)
{
    this->cin=cin;
}
void Employe::set_prenom(QString prenom)
{
    this->prenom=prenom;
}
void Employe::set_nom(QString n)
{
    nom=n;
}
int Employe::get_cin()
{
    return cin;
}
QString Employe::get_prenom()
{
    return prenom;
}
QString Employe::get_nom()
{
    return nom;
}
