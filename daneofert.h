#ifndef DANEOFERT_H
#define DANEOFERT_H
#include <QXmlStreamReader>

#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QIODevice>
#include <QList>

#include "oferta.h"
#include "oferta_nju_mobile.h"
#include "oferta_play.h"

class daneofert
{
public:
    daneofert();

    void parseXML();

    QList< oferta* > lista;

    void parseOferta(QXmlStreamReader& xml, oferta &tmp, QString Nazwa);



};

#endif // DANEOFERT_H
