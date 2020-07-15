#include "bala_parabolica.h"

bala_parabolica::bala_parabolica( int x, int y)
{
    posx = x;
    posy = y;
    y0=y;
    //Le damos una posicion inicial
    setPos(posx,posy);
    QTimer *t=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

void bala_parabolica::setR(int radio)
{
    r = radio;
}

void bala_parabolica::setPosx(int px)
{
    posx=px;
}

void bala_parabolica::setPosy(int py)
{
    posy = py;
}

QRectF bala_parabolica::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void bala_parabolica::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::red);
    painter->drawEllipse(boundingRect());
}

void bala_parabolica::borrar(int x, int y)
{
    if(posx>=x and posx<=x+23)delete this;
}

void bala_parabolica::movimiento()
{
    //La bala realiza un Movimiento Parabolico, por lo que siempre tendra la misma velocidad en x
    //Pero en y no, aparte agregamos un yd, que es el que nos permite colocar las coordenadas bien
    //Debido a que en Qt el eje y esta invertido
    double yd;
    vely=vely-(9.8)/2;
    posx=posx+velx;
    posy=posy+vely-(9.8)/2;
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
}
