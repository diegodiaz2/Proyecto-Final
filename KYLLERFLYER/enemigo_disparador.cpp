#include "enemigo_disparador.h"
#include "mainwindow.h"

void enemigo_disparador::eliminar()
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

enemigo_disparador::enemigo_disparador()
{
    QTimer *t= new QTimer();
    QTimer *t2= new QTimer();
    y=posicion();
    x=1780;
    setPos(1780, y);
    //Le damos imagen al objeto
    setPixmap(QPixmap(":/enemigo_disparador.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
    connect(t2,SIGNAL(timeout()),this,SLOT(disparar()));
    t2->start(2000);
}

int enemigo_disparador::posicion()
{
    //Se le da una posicion inicial aleatorea
    int y;
    y=rand()%(400);
    return y;
}

void enemigo_disparador::velocidad(int puntaje)
{
    if(puntaje>=500 and puntaje < 700){
        vx=-5;
    }
    else if(puntaje>=700 and puntaje<1000){
        vx=-6;
    }
    else if(puntaje>=1000) vx=-7;
}

void enemigo_disparador::movimiento()
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
    //El objeto caminante realiza un mov rectilineo
    x=x+vx;
    setPos(x, y);
    eliminar();
}

void enemigo_disparador::disparar()
{
    //Se crea una bala y es añadida a la escena
    MainWindow *mw=MainWindow::getMainWinPtr();
    bala=new bala_horizontal(x-10, y+30,-8, 2);
    mw->escena->addItem(bala);
}
