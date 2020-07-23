#include "enemigo_caminante.h"
#include <math.h>
#include "mainwindow.h"

void enemigo_caminante::eliminar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mw=MainWindow::getMainWinPtr();
    if(x<0){
        mw->escena->removeItem(this);
        delete this;
        return;
    }
    if(mw->vidas<=0){
        mw->escena->removeItem(this);
        delete this;
        return;
    }
}

enemigo_caminante::enemigo_caminante()
{
    t= new QTimer();
    QTimer *t2= new QTimer();
    x=1780;
    setPos(1780, 512);
    //Le damos imagen al objeto
    setPixmap(QPixmap(":/enemigo_caminante.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
    connect(t2,SIGNAL(timeout()),this,SLOT(disparar()));
    t2->start(2000);
}

void enemigo_caminante::velocidad(int puntaje)
{
    if(puntaje>=500 and puntaje<700){
        vx=-5;
    }
    else if(puntaje>=700 and puntaje < 1500){
        vx=-7;
    }
    else if(puntaje>=1500){
        vx=-10;
    }
}


void enemigo_caminante::movimiento()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(personaje)){
            mv->vida();
            mv->escena->removeItem(this);
            delete this;
            return;
        }
    }
    //Se realiza un cambio de imagenes para simular el movimiento
    if (estado) setPixmap(QPixmap(":/enemigo_caminante.png").scaled(30, 50));
    else setPixmap(QPixmap(":/enemigo_caminante0.png").scaled(30, 50));
    estado=!estado;
    //El objeto caminante realiza un mov rectilineo, aparte de ello, dabo que en el suelo hay friccion
    //Esta velocidad inicial ira disminuyendo
    x=x+vx;
    vx=vx*exp(-(0.05/50));
    setX(x);
    eliminar();
}

void enemigo_caminante::disparar()
{
    //Se crea una bala y es añadida a la escena
    MainWindow *mw=MainWindow::getMainWinPtr();
    bala=new bala_vertical(x+18, 500);
    mw->escena->addItem(bala);
}
