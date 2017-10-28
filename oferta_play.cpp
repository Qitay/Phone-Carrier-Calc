#include "oferta_play.h"

oferta_Play::oferta_Play()
{
    this->siec = "Play";

    this->mbCena=0;
    this->mmsCena=0;
    this->smsCena=0;
    this->minCena=0;
    this->minDomoweCena =0;
}

double oferta_Play::ObliczSume(danewejsciowe input)
{
    double zaMinuty = 0;
    double zaDomowe = 0;
    double zaSMS_MMS = 0;
    double zaInternet = 0;

    //Telefoniczne i Domowe
    if(this->iloscMinut < 0)
        zaMinuty = 0;
    else if((input.iloscMinut + input.iloscMinut_Domowe) - input.iloscMinut_Play > this->iloscMinut)
        zaMinuty = ((input.iloscMinut + input.iloscMinut_Domowe - input.iloscMinut_Play) - this->iloscMinut)* this->minCena;
    else
        zaMinuty = 0;

    //SMS i MMS
    if(this->iloscSMS < 0)
        zaSMS_MMS = 0;
    else if(input.iloscSms + input.iloscMms > this->iloscSMS)
        zaSMS_MMS = input.iloscSms * this->smsCena + input.iloscMms * this->mmsCena;
    else
        zaSMS_MMS = 0;

    //Internet
    if(this->iloscDanych <0)
    {
        if(input.iloscInternetu > 5 && input.iloscInternetu <= 0)
            zaInternet = 0;
        if(input.iloscInternetu > 5 && input.iloscInternetu <= 250)
            zaInternet = 10;
        if(input.iloscInternetu > 250 && input.iloscInternetu <= 500)
            zaInternet = 20;
        if(input.iloscInternetu > 500)
            zaInternet = 30;
    }
    else
    {
        zaInternet = 0;
    }

    qDebug() << zaMinuty;
    qDebug() << zaSMS_MMS;
    qDebug() << zaInternet;

    this->CenaSuma = this->Cena + zaMinuty + zaSMS_MMS + zaInternet + zaDomowe;
    return this->Cena + zaMinuty + zaSMS_MMS + zaInternet + zaDomowe;
}
