#include "enemigo_volador.h"
#include "mainwindow.h"

void enemigo_volador::eliminar()
{
    //Revisa colisiones
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(personaje)){
            mv->vida(1);
            mv->escena->removeItem(this);
            delete this;
            return;
        }
    }
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    if(x<0){
        mv->vida(2);
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

enemigo_volador::enemigo_volador()
{
    QTimer *t= new QTimer();
    y=posicion();
    x=1780;
    setPos(1780, y);
    //Le damos imagen al objeto
    setPixmap(QPixmap(":/enemigo_volador.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

int enemigo_volador::posicion()
{
    //Se le da una posicion inicial aleatorea
    int y;
    y=rand()%(400);
    return y;
}

void enemigo_volador::velocidad(int puntaje)
{
    if(puntaje>=250 and puntaje<700){
        vx=-7;
    }
    else if(puntaje>=700 and puntaje < 1250){
        vx=-10;
    }
    else if(puntaje>=1250){
        vx=-12;
    }
}

void enemigo_volador::movimiento()
{
    //Se crea una bala y es añadida a la escena
    x=x+vx;
    setPos(x, y);
    eliminar();
}
