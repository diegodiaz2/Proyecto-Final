#ifndef BALA_HORIZONTAL_H
#define BALA_HORIZONTAL_H

#include <QGraphicsItem>
#include <QPainter>
#include <QTimer>

class bala_horizontal:public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    int typo;
    int r=4;
    int posx, posy;
    int velx;
    bala_horizontal(int x, int y,int vel, int tipo);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void borrar();
public slots:
    void movimiento();
};

#endif // BALA_HORIZONTAL_H
