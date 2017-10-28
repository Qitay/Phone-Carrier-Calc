#include "daneofert.h"

daneofert::daneofert()
{
}

void daneofert::parseXML() {

    QFile* plik = new QFile("//OFFERS/Oferty.xml");

    if (!plik->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox msgBox;
          msgBox.addButton(QMessageBox::Ok);
          msgBox.setText("Wystąpił błąd podczas odczytywania danych ofert. Program przestanie działać :(");
          msgBox.exec();
        return;
    }
    else
    {

    QXmlStreamReader xml(plik);


    while(!xml.atEnd() && !xml.hasError())
    {
        //Czytamy następny
        QXmlStreamReader::TokenType token = xml.readNext();
        //Jeśli to start to lecimy dalej
        if(token == QXmlStreamReader::StartDocument) {
            continue;
        }

        //Wczytujemy oferte
        if(token == QXmlStreamReader::StartElement) {

            if(xml.name() == "oferty")
            {
                continue;
            }

            if(xml.name() == "NJU")
            {
                oferta_Nju_Mobile *tmp =  new oferta_Nju_Mobile;
                parseOferta(xml,*tmp,"NJU");
                //*tmp = OfertaParseNJU(xml);
                this->lista.append(tmp);
            }

            else if(xml.name() == "PLAY")
            {
                oferta_Play *tmp = new oferta_Play;
                parseOferta(xml,*tmp,"PLAY");
                //*tmp = OfertaParsePLAY(xml);
                this->lista.append(tmp);
            }
        }
    }

    //Error handling trzeba zrobic
    if(xml.hasError()) {
        QMessageBox msgBox;
          msgBox.addButton(QMessageBox::Ok);
          msgBox.setText("Wystąpił błąd podczas odczytywania danych ofert.");
          msgBox.exec();

        return;
    }
    //Resetujemy wczytywanie
    xml.clear();
    }

}


void daneofert::parseOferta(QXmlStreamReader& xml, oferta &tmp, QString Nazwa)
{
    if(xml.tokenType() != QXmlStreamReader::StartElement && xml.name() == "NJU")
    {
        return;
    }
    xml.readNext();


    while(!(xml.tokenType() == QXmlStreamReader::EndElement && xml.name() == Nazwa))
    {
        if(xml.tokenType() == QXmlStreamReader::StartElement)
        {
            if(xml.name() == "nazwa")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.nazwa = xml.text().toString();
                //qDebug() << tmp.nazwa;
            }
            if(xml.name() == "okres")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.okres = xml.text().toInt();
                //qDebug() << tmp.okres;
            }
            if(xml.name() == "iloscSMS")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.iloscSMS = xml.text().toInt();
                //qDebug() << tmp.iloscSMS;
            }
            if(xml.name() == "iloscMinut")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.iloscMinut = xml.text().toInt();
                //qDebug() << tmp.iloscMinut;
            }
            if(xml.name() == "iloscDanych")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.iloscDanych = xml.text().toInt();
                //qDebug() << tmp.iloscDanych;
            }
            if(xml.name() == "Cena")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.Cena = xml.text().toDouble();
                //qDebug() << tmp.Cena;
            }
            if(xml.name() == "smsCena")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.smsCena = xml.text().toDouble();
                //qDebug() << tmp.smsCena;
            }
            if(xml.name() == "mmsCena")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.mmsCena = xml.text().toDouble();
                //qDebug() << tmp.mmsCena;
            }
            if(xml.name() == "minCena")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.minCena = xml.text().toDouble();
                //qDebug() << tmp.minCena;
            }
            if(xml.name() == "minDomoweCena")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.minDomoweCena = xml.text().toDouble();
                //qDebug() << tmp.minDomoweCena;
            }
            if(xml.name() == "mbCena")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.mbCena = xml.text().toDouble();
                //qDebug() << tmp.mbCena;

            }
            if(xml.name() == "opis")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.opis = xml.text().toInt();
                //qDebug() << tmp.opis;
            }
            if(xml.name() == "website")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.website = xml.text().toString();
                //qDebug() << tmp.website;
            }
            if(xml.name() == "GranicaSMS")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.GranicaSMS = xml.text().toInt();
                //qDebug() << tmp.GranicaSMS;
            }
            if(xml.name() == "GranicaMIN")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.GranicaMIN = xml.text().toInt();
                //qDebug() << tmp.GranicaMIN;
            }
            if(xml.name() == "GranicaMINDomowe")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.GranicaMINDomowe = xml.text().toInt();
                //qDebug() << tmp.GranicaMINDomowe;
            }
            if(xml.name() == "GranicaMB")
            {
                if(xml.tokenType() != QXmlStreamReader::StartElement){return;}
                xml.readNext();
                tmp.GranicaMB = xml.text().toInt();
                //qDebug() << tmp.GranicaMB;;
            }
        }
        xml.readNext();
    }
}




