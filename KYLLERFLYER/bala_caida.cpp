#include "bala_caida.h"
#include "mainwindow.h"
#include "enemigo_caminante.h"
#include "enemigo_saltarin.h"
#include "enemigo_disparador.h"
#include "enemigo_volador.h"

bala_caida::bala_caida( int x, int y)
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

QRectF bala_caida::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void bala_caida::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void bala_caida::borrar()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    //Se verifican las colisiones
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(enemigo_volador) or typeid (*(colliding_items[i])) == typeid(enemigo_caminante) or typeid (*(colliding_items[i])) == typeid(enemigo_saltarin) or typeid (*(colliding_items[i])) == typeid(enemigo_disparador)){
            //Se aumenta el puntaje
            mv->score();
            //Se elimina la bala y el objeto
            mv->escena->removeItem(colliding_items[i]);
            mv->escena->removeItem(this);
            delete colliding_items[i];
            delete this;
            return;
        }
    }
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
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
    //Cuando el usuario muere el objeto se elimina
    if(mv->vidas<=0){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
}

void bala_caida::movimiento()
{
    //La bala realiza un mov de caida libre, por lo que no tiene velocidad en x
    //Pero en y si, aparte agregamos un yd, que es el que nos permite colocar las coordenadas bien
    //Debido a que en Qt el eje y esta invertido
    posy=posy+vely-(9.8)/2;
    vely=vely-(9.8)/2;
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
    borrar();
}
