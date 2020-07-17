#ifndef BALA_CAIDA_H
#define BALA_CAIDA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bala_caida:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int r=4;
    double posx, posy,y0;
    double vely=0;
    double yd;
    bala_caida(int x, int y);
    void setR(int radio);
    void setPosx(int px);
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar();
public slots:
    void movimiento();
};

#endif // BALA_CAIDA_H
