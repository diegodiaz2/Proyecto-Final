#ifndef BALA_VERTICAL_H
#define BALA_VERTICAL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bala_vertical:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int r=4;
    double posx, posy,y0;
    double vely=75;
    double yd;
    bala_vertical(int x, int y);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar();
public slots:
    void movimiento();
};

#endif // BALA_VERTICAL_H
