#ifndef ESFERA_GITATORIA_H
#define ESFERA_GITATORIA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class esfera_gitatoria:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int r=10;
    double posx=1100, posy=310,y0=310;
    double vely=15,velx=0;
    double ax,ay;
    double yd;
    esfera_gitatoria();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar();
public slots:
    void movimiento();
    void eliminar();
};

#endif // ESFERA_GITATORIA_H
