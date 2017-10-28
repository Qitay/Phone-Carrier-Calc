#include "oferta_nju_mobile.h"

oferta_Nju_Mobile::oferta_Nju_Mobile()
{
    this->siec = "Nju Mobile";

    this->mbCena=0;
    this->mmsCena=0;
    this->smsCena=0;
    this->minCena=0;
    this->minDomoweCena =0;
    this->GranicaSMS=0;
    this->GranicaMIN=0;
    this->GranicaMINDomowe=0;
    this->GranicaMB=0;
}

double oferta_Nju_Mobile::ObliczSume(danewejsciowe input)
{

    double zaMinuty = 0;
    double zaSMS_MMS = 0;
    double zaInternet = 0;
    double zaDomowe = 0;

    //minuty za Domowe i Komorkowe
    if(this->GranicaMINDomowe > 0)
    {
        if((input.iloscMinut - input.iloscMinut_Domowe) * this->minCena < this->GranicaMIN && this->GranicaMIN > 0)
             zaMinuty = input.iloscMinut * this->minCena;
        else
        {
            zaMinuty = this->GranicaMIN;
        }

        if(input.iloscMinut_Domowe * this->minCena < this->GranicaMINDomowe && this->GranicaMINDomowe > 0)
             zaDomowe = input.iloscMinut_Domowe * this->minDomoweCena;
        else zaDomowe = this->GranicaMINDomowe;
    }
    else
    {
        if(input.iloscMinut * this->minCena +input.iloscMinut_Domowe * this->minDomoweCena < this->GranicaMIN )
        {
             zaMinuty = input.iloscMinut * this->minCena +input.iloscMinut_Domowe * this->minDomoweCena;
        }
        else
        {
            zaMinuty = this->GranicaMIN;
            zaDomowe =0;
        }
    }


    //SMS/MMS
    if(input.iloscSms * this->smsCena + input.iloscMms * this->mmsCena < this->GranicaSMS )
         zaSMS_MMS = input.iloscSms * this->smsCena + input.iloscMms * this->mmsCena;
    else zaSMS_MMS = this->GranicaSMS;

    //Internet
    if(input.iloscInternetu * this->mbCena < this->GranicaMB )
         zaInternet = input.iloscInternetu * this->mbCena;
    else zaInternet = this->GranicaMB;

    if ((zaMinuty + zaSMS_MMS + zaInternet + zaDomowe) < this->Cena)
    {
        this->CenaSuma = this->Cena;
        return this->Cena;
    }

    qDebug() << zaMinuty;
    qDebug() << zaDomowe;
    qDebug() << zaSMS_MMS;
    qDebug() << zaInternet;

    this->CenaSuma = zaMinuty + zaSMS_MMS + zaInternet + zaDomowe;
    return zaMinuty + zaSMS_MMS + zaInternet + zaDomowe;
}
