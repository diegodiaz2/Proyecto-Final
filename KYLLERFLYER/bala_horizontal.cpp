#include "bala_horizontal.h"

bala_horizontal::bala_horizontal( int x, int y)
{
    posx = x;
    posy = y;
    //Le damos una posicion inicial
    setPos(posx,posy);
    QTimer *t=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

void bala_horizontal::setR(int radio)
{
    r = radio;
}

void bala_horizontal::setPosx(int px)
{
    posx=px;
}

void bala_horizontal::setPosy(int py)
{
    posy = py;
}

QRectF bala_horizontal::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void bala_horizontal::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::green);
    painter->drawEllipse(boundingRect());
}

void bala_horizontal::borrar(int x, int y)
{
    if(posx>=x and posx<=x+23)delete this;
}

void bala_horizontal::movimiento()
{
    //La bala realiza un Movimiento Rectilineo Uniforme, por lo que siempre tendra la misma velocidad
    //Y lo mismo siempre avanzara la misma cantidad de pixeles en un determinado tiempo
    posx=posx+vel;
    setPos(posx,posy);
}