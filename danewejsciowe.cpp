#include "danewejsciowe.h"

danewejsciowe::danewejsciowe()
{
    this->iloscMinut = 0;
    this->iloscMinut_Tmobile = 0;
    this->iloscMinut_Orange = 0;
    this->iloscMinut_Play = 0;
    this->iloscMinut_Plus = 0;
    this->iloscMinut_Domowe = 0;
    this->iloscMinut_Zagraniczne = 0;

    this->iloscSms = 0;
    this->iloscSms_Tmobile = 0;
    this->iloscSms_Orange = 0;
    this->iloscSms_Play = 0;
    this->iloscSms_Plus = 0;
    this->iloscMms = 0;
    this->iloscSms_Zagraniczne = 0;

    this->iloscInternetu = 0;
}

void danewejsciowe::reset()
{
    this->iloscMinut = 0;
    this->iloscMinut_Tmobile = 0;
    this->iloscMinut_Orange = 0;
    this->iloscMinut_Play = 0;
    this->iloscMinut_Plus = 0;
    this->iloscMinut_Domowe = 0;
    this->iloscMinut_Zagraniczne = 0;

    this->iloscSms = 0;
    this->iloscSms_Tmobile = 0;
    this->iloscSms_Orange = 0;
    this->iloscSms_Play = 0;
    this->iloscSms_Plus = 0;
    this->iloscMms = 0;
    this->iloscSms_Zagraniczne = 0;

    this->iloscInternetu = 0;
}

void danewejsciowe::odczytPliku(QString adres)
{
    QFile Plik (adres);

    //wyjatek
    if (!Plik.open(QIODevice::ReadOnly))
    {
        QMessageBox msgBox;
          msgBox.addButton(QMessageBox::Ok);
          msgBox.setText("Wystąpił błąd podczas odczytywania billingu.");
          msgBox.exec();
        return;
    }
    else
    {

        TekstTaki = Plik.readAll();
        // podziel na slowa
        QStringList list = TekstTaki.split("\t");

//        for (int i = 0; i < list.size(); i++)
//        {
//            qDebug() << list.at(i);
//        }

        for (int i = 0; i < list.size(); i++)
        {
            //SMS i MMS
            if(list.at(i) == "SMS")
            {
                iloscSms++;
                QString kierunkowy = list.at(i+2);
                if(kierunkowy.remove(2,kierunkowy.size()).toInt() != 48)
                {
                    iloscSms_Zagraniczne++;
                    qDebug()<<iloscSms_Zagraniczne;
                }
            }
            else if(list.at(i) == "SMS T-Mobile")
            {
               iloscSms_Tmobile++;
            }
            else if(list.at(i) == "SMS Play")
            {
               iloscSms_Play++;
            }
            else if(list.at(i) == "SMS Orange")
            {
                iloscSms_Orange++;
            }
            else if(list.at(i) == "SMS Plus Gsm")
            {
                iloscSms_Plus++;
            }
            else if((list.at(i) == "MMS"))
            {
                iloscSms--;
                iloscMms++;
            }
            //Internet
            else if(list.at(i) == "internet")
            {
                if(list.at(i+1) == "internet")
                {
                    QString tmp = list.at(i+2);
                    tmp.remove("kB ");
                    iloscInternetu += tmp.toDouble()/1024;
                }
            }
            //Telefoniczne
            else if(list.at(i) == "telefoniczne")
            {
                QString sek=list.at(i+3);
                QString min=list.at(i+3);
                QString godz=list.at(i+3);

                sek.remove(0,6);
                min.remove(5,3);
                min.remove(0,3);
                godz.remove(2,6);

                double sekundy = sek.toDouble();
                double minuty = min.toDouble();
                double godziny = godz.toDouble();

                iloscMinut += (sekundy/60);
                iloscMinut += minuty;
                iloscMinut += (godziny*60);

                QString kierunkowy = list.at(i+2);
                if(kierunkowy.remove(2,kierunkowy.size()).toInt() != 48)
                {
                    iloscMinut_Zagraniczne += (sekundy/60);
                    iloscMinut_Zagraniczne += minuty;
                    iloscMinut_Zagraniczne += (godziny*60);
                    qDebug()<<iloscMinut_Zagraniczne;
                }
                if(list.at(i+1) == "Polska")
                {
                    iloscMinut_Domowe += (sekundy/60);
                    iloscMinut_Domowe += minuty;
                    iloscMinut_Domowe += (godziny*60);
                    iloscMinut -= iloscMinut_Domowe;
                    qDebug()<<iloscMinut_Domowe;
                }
            }
            else if(list.at(i) == "T-Mobile")
            {
               QString sek=list.at(i+2);
               QString min=list.at(i+2);
               QString godz=list.at(i+2);


               sek.remove(0,6);
               min.remove(5,3);
               min.remove(0,3);
               godz.remove(2,6);

               double sekundy = sek.toDouble();
               double minuty = min.toDouble();
               double godziny = godz.toDouble();

               iloscMinut_Tmobile += (sekundy/60);
               iloscMinut_Tmobile += minuty;
               iloscMinut_Tmobile += (godziny*60);
            }
            else if(list.at(i) == "Play")
            {
                QString sek=list.at(i+2);
                QString min=list.at(i+2);
                QString godz=list.at(i+2);

                sek.remove(0,6);
                min.remove(5,3);
                min.remove(0,3);
                godz.remove(2,6);

                double sekundy = sek.toDouble();
                double minuty = min.toDouble();
                double godziny = godz.toDouble();

                iloscMinut_Play += (sekundy/60);
                iloscMinut_Play += minuty;
                iloscMinut_Play += (godziny*60);
            }
            else if(list.at(i) == "Orange")
            {
                QString sek=list.at(i+2);
                QString min=list.at(i+2);
                QString godz=list.at(i+2);

                sek.remove(0,6);
                min.remove(5,3);
                min.remove(0,3);
                godz.remove(2,6);

                double sekundy = sek.toDouble();
                double minuty = min.toDouble();
                double godziny = godz.toDouble();

                iloscMinut_Orange += (sekundy/60);
                iloscMinut_Orange += minuty;
                iloscMinut_Orange += (godziny*60);
            }
            else if(list.at(i) == "Plus Gsm")
            {
                QString sek=list.at(i+2);
                QString min=list.at(i+2);
                QString godz=list.at(i+2);

                sek.remove(0,6);
                min.remove(5,3);
                min.remove(0,3);
                godz.remove(2,6);

                double sekundy = sek.toDouble();
                double minuty = min.toDouble();
                double godziny = godz.toDouble();

                iloscMinut_Plus += (sekundy/60);
                iloscMinut_Plus += minuty;
                iloscMinut_Plus += (godziny*60);
            }
        }


        Plik.close();
    }
}



