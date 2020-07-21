#ifndef ENEMIGO_VOLADOR_H
#define ENEMIGO_VOLADOR_H

#include <QTimer>
#include <QGraphicsPixmapItem>


class enemigo_volador: public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
private:
    void eliminar();
public:
    double x, y, vx=-3;
    enemigo_volador();
    int posicion();
    void velocidad(int puntaje);
public slots:
     void movimiento();
};

#endif // ENEMIGO_VOLADOR_H
