#ifndef OFERTA_PLAY_H
#define OFERTA_PLAY_H
#include "oferta.h"
#include <QDebug>

class oferta_Play : public oferta
{
public:

    oferta_Play();

    virtual double ObliczSume(danewejsciowe input);
};

#endif // OFERTA_PLAY_H
