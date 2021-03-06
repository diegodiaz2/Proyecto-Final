#include "esfera_gitatoria.h"
#include "mainwindow.h"
#include <math.h>


esfera_gitatoria::esfera_gitatoria()
{
    //Le damos una posicion inicial
    setPos(posx,posy);
    QTimer *t=new QTimer();
    QTimer *t2=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
    //Se hace un connect para eliminar la esfera
    connect(t2,SIGNAL(timeout()),this,SLOT(eliminar()));
    t2->start(20000);
}

QRectF esfera_gitatoria::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void esfera_gitatoria::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::GlobalColor::darkMagenta);
    painter->drawEllipse(boundingRect());
}

void esfera_gitatoria::borrar()
{
    //Revisa colisiones
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(enemigo_volador) or typeid (*(colliding_items[i])) == typeid(enemigo_caminante) or typeid (*(colliding_items[i])) == typeid(enemigo_saltarin) or typeid (*(colliding_items[i])) == typeid(enemigo_disparador)){
            //Se aumenta el puntaje
            mv->score();
            //Elimina al enemigo
            mv->escena->removeItem(colliding_items[i]);
            delete colliding_items[i];
        }
    }
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    if(mv->vidas<=0){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
}

void esfera_gitatoria::movimiento()
{
    //Se simula el movimiento de un sistema gravitacional
    ax=((50000/pow(sqrt(pow(900-posx,2)+pow(310-posy,2)),3))*(900-posx));
    ay=((50000/pow(sqrt(pow(900-posx,2)+pow(310-posy,2)),3))*(310-posy));
    velx=velx+ax;
    vely=vely+ay;
    posx=posx+velx;
    posy=posy+vely;
    //Se corrige la posicion del eje y
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
    borrar();
}

void esfera_gitatoria::eliminar()
{
    //Se elimina el objeto
    delete this;
    return;
}
