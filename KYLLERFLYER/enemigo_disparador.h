#ifndef ENEMIGO_DISPARADOR_H
#define ENEMIGO_DISPARADOR_H

#include "enemigo_volador.h"
#include <QTimer>
#include <QGraphicsPixmapItem>
#include "bala_horizontal.h"

class enemigo_disparador: public enemigo_volador
{
    Q_OBJECT
public:
    double x, y, vx=-4;
    enemigo_disparador();
    bala_horizontal *bala;
    void velocidad(int puntaje);
public slots:
    void disparar();
};

#endif // ENEMIGO_DISPARADOR_H
