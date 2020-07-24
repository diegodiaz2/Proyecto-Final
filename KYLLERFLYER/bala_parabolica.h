#ifndef BALA_PARABOLICA_H
#define BALA_PARABOLICA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bala_parabolica:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int r=4;
    double posx, posy,y0;
    double velx=20;
    double vely=20;
    double yd;
    bala_parabolica(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar();
public slots:
    void movimiento();
};

#endif // BALA_PARABOLICA_H
