#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>
#include <QTimer>

class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    personaje(int n);
    int velocidad();
    void sprites();
    int n,j;
    QTimer *t;
private:
    int vel=8;
    bool estado=0;
    void poder_vidas();
public slots:
    void movimiento();
    bool limites(int k);
};

#endif // PERSONAJE_H
