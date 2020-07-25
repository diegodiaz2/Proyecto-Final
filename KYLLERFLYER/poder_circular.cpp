#include "poder_circular.h"
#include "mainwindow.h"

poder_circular::poder_circular()
{
    //Se le da una posicion al poder
    x=200+rand()%(1600-200);
    setPos(x,y);
    //Se le da una imagen
    setPixmap(QPixmap(":/Coin.png").scaled(40,40));
    t=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

void poder_circular::eliminar()
{
    //Se elimina cuando salga edl escenario
    if(yd>552){
        delete this;
        return;
    }
}

void poder_circular::movimiento()
{
    //Se revisan las colisiones
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(personaje)){
            //Se agrega la esfera giratoria
            mv->escena->removeItem(this);
            bala=new esfera_gitatoria();
            mv->escena->addItem(bala);
        }       
    }
    //Se le da un movimiento
    y=y+vy;
    yd=-y;
    setPos(int(x),int(yd));
    eliminar();
}
