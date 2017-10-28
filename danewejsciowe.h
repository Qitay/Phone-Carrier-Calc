#ifndef DANEWEJSCIOWE_H
#define DANEWEJSCIOWE_H

#include <QString>
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QMessageBox>
#include <QDebug>

class danewejsciowe
{
public:
    danewejsciowe();

    double iloscMinut_Tmobile;
    double iloscMinut_Orange;
    double iloscMinut_Play;
    double iloscMinut_Plus;
    double iloscMinut_Domowe;
    double iloscMinut_Zagraniczne;
    double iloscMinut;

    int iloscSms_Tmobile;
    int iloscSms_Orange;
    int iloscSms_Play;
    int iloscSms_Plus;
    int iloscSms_Zagraniczne;
    int iloscSms;
    int iloscMms;

    double iloscInternetu;

    QString TekstTaki;

    void odczytPliku(QString adres);
    void reset();
};

#endif // DANEWEJSCIOWE_H
