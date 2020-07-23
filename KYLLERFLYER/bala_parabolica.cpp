#include "bala_parabolica.h"
#include "mainwindow.h"
#include "enemigo_caminante.h"
#include "enemigo_saltarin.h"
#include "enemigo_disparador.h"
#include "enemigo_volador.h"

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

void bala_parabolica::borrar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mv=MainWindow::getMainWinPtr();
    if(posx<0 or posx>1786){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
    else if(yd>700){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
    if(mv->vidas<=0){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
}

void bala_parabolica::movimiento()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(enemigo_volador) or typeid (*(colliding_items[i])) == typeid(enemigo_caminante) or typeid (*(colliding_items[i])) == typeid(enemigo_saltarin) or typeid (*(colliding_items[i])) == typeid(enemigo_disparador)){
            mv->score();
            mv->escena->removeItem(colliding_items[i]);
            mv->escena->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //La bala realiza un Movimiento Parabolico, por lo que siempre tendra la misma velocidad en x
    //Pero en y no, aparte agregamos un yd, que es el que nos permite colocar las coordenadas bien
    //Debido a que en Qt el eje y esta invertido
    posx=posx+velx;
    posy=posy+vely-(9.8)/2;
    vely=vely-(9.8)/2;
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
    borrar();
}
