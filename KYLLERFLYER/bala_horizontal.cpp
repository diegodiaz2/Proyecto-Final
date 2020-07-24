#include "bala_horizontal.h"
#include "mainwindow.h"
#include "enemigo_caminante.h"
#include "enemigo_saltarin.h"
#include "enemigo_disparador.h"
#include "enemigo_volador.h"
#include "personaje.h"
#include <QDebug>

bala_horizontal::bala_horizontal( int x, int y,int vel, int tipo)
{
    posx = x;
    posy = y;
    velx=vel;
    typo=tipo;
    //Le damos una posicion inicial
    setPos(posx,posy);
    QTimer *t=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
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

void bala_horizontal::borrar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mv=MainWindow::getMainWinPtr();
    if(posx<0 or posx>1786){
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

void bala_horizontal::movimiento()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    if(typo==1){
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
    }
    if(typo==2){
        QList<QGraphicsItem *> colliding_items=collidingItems();
        for(int i=0, n=colliding_items.size(); i<n; i++){
            if (typeid (*(colliding_items[i])) == typeid(personaje)){
                mv->vida();
                mv->escena->removeItem(this);
                delete this;
                return;
            }
        }
    }
    //La bala realiza un Movimiento Rectilineo Uniforme, por lo que siempre tendra la misma velocidad
    //Y por lo mismo siempre avanzara la misma cantidad de pixeles en un determinado tiempo
    posx=posx+velx;
    setPos(posx,posy);
    borrar();
}
