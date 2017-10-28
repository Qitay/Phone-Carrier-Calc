#ifndef OFERTA_NJU_MOBILE_H
#define OFERTA_NJU_MOBILE_H
#include "oferta.h"
#include <QDebug>

class oferta_Nju_Mobile : public oferta
{
public:

    oferta_Nju_Mobile();

    virtual double ObliczSume(danewejsciowe input);

};

#endif // OFERTA_NJU_MOBILE_H
