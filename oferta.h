#ifndef OFERTA_H
#define OFERTA_H

#include <cstdlib>
#include <QApplication>
#include <QString>
#include "danewejsciowe.h"

class oferta
{
public:
    oferta(){}

    double CenaSuma;
    double Cena;
    double smsCena;
    double mmsCena;
    double minCena;
    double minDomoweCena;
    double mbCena;

    int iloscMinut;
    int iloscSMS;
    int iloscMMS;
    int iloscDanych;

    int okres;

    int GranicaSMS;
    int GranicaMIN;
    int GranicaMINDomowe;
    int GranicaMB;

    QString nazwa;
    QString siec;
    QString opis;
    QString website;

    virtual double ObliczSume(danewejsciowe x) = 0;

};

#endif // OFERTA_H
