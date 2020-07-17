#ifndef ENEMIGO_SALTARIN_H
#define ENEMIGO_SALTARIN_H

#include <QTimer>
#include <QGraphicsPixmapItem>

class enemigo_saltarin: public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
private:
    void eliminar();
public:
    double x, y, vx=-3,vy=50;
    bool estado;
    enemigo_saltarin();
    void posicion();
public slots:
    void movimiento();
};

#endif // ENEMIGO_SALTARIN_H
