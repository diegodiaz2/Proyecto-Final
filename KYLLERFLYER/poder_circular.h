#ifndef PODER_CIRCULAR_H
#define PODER_CIRCULAR_H

#include <QGraphicsPixmapItem>
#include <QTimer>
#include "esfera_gitatoria.h"

class poder_circular: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    poder_circular();
private:
    double x,y=0,yd;
    double vy=-5;
    QTimer *t;
    void eliminar();
    esfera_gitatoria *bala;
private slots:
    void movimiento();
};

#endif // PODER_CIRCULAR_H
