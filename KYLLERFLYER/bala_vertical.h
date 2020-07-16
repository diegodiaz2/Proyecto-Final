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
    double vely=100;
    bala_vertical(int x, int y);
    void setR(int radio);
    void setPosx(int px);
    void setPosy(int py);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar(int x,int y);
public slots:
    void movimiento();
};

#endif // BALA_VERTICAL_H
