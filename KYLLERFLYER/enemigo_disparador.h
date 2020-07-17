#ifndef ENEMIGO_DISPARADOR_H
#define ENEMIGO_DISPARADOR_H

#include <QTimer>
#include <QGraphicsPixmapItem>
#include "bala_horizontal.h"

class enemigo_disparador: public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
private:
    void eliminar();
public:
    double x, y, vx=-4;
    enemigo_disparador();
    int posicion();
    bala_horizontal *bala;
public slots:
    void movimiento();
    void disparar();
};

#endif // ENEMIGO_DISPARADOR_H
