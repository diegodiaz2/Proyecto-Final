#include "poder_circular.h"
#include "mainwindow.h"

poder_circular::poder_circular()
{
    x=200+rand()%(1600-200);
    setPos(x,y);
    setPixmap(QPixmap(":/Coin.png").scaled(40,40));
    t=new QTimer();
    t2=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
    connect(t2,SIGNAL(timeout()),this,SLOT(eliminar_bala()));
    //t2->stop();
}

void poder_circular::eliminar()
{
    if(yd>552){
        delete this;
        return;
    }
}

void poder_circular::movimiento()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(personaje)){
            mv->escena->removeItem(this);
            bala=new esfera_gitatoria();
            mv->escena->addItem(bala);
            //t2->start(4000);
        }
    }
    y=y+vy;
    yd=-y;
    setPos(int(x),int(yd));
    eliminar();
}

void poder_circular::eliminar_bala()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    mv->escena->removeItem(bala);
    mv->vidas=1000;
    mv->vida();
    delete bala;
    delete this;
    return;
}
