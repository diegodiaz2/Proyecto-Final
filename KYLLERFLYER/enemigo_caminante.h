#ifndef ENEMIGO_CAMINANTE_H
#define ENEMIGO_CAMINANTE_H

#include <QTimer>
#include <QGraphicsPixmapItem>
#include <bala_vertical.h>

class enemigo_caminante: public QObject, public  QGraphicsPixmapItem
{

    Q_OBJECT

private:
    bala_vertical *bala;
    QTimer *t;
    void eliminar();
public:
    bool estado=0;
    double x, vx=-3;
    enemigo_caminante();

public slots:

     void movimiento();
     void disparar();


};

#endif // ENEMIGO_VOLADOR_H

