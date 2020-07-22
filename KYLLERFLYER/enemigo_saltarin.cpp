#include "enemigo_saltarin.h"
#include "mainwindow.h"

void enemigo_saltarin::eliminar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mw=MainWindow::getMainWinPtr();
    if(x<0){
        mw->escena->removeItem(this);
        delete this;
        return;
    }
}

enemigo_saltarin::enemigo_saltarin()
{
    QTimer *t= new QTimer();
    x=1780;
    y=512;
    setPos(1780, 512);
    //Le damos imagen al objeto
    setPixmap(QPixmap(":/Saltarin0.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}
void enemigo_saltarin::posicion()
{
    //Se cambian las imagenes dependiendo de la posicion del objeto
    if(y==512) {
        setPixmap(QPixmap(":/Saltarin0.png").scaled(30,50));
        estado=1;
    }
    else if(y!=512){
        setPixmap(QPixmap(":/Saltarin1.png").scaled(30,50));
        estado=0;
    }
}

void enemigo_saltarin::velocidad(int puntaje)
{
    if(puntaje>500){
        vx=-5;
    }
    else if(puntaje>700){
        vx=-7;
    }
    else if(puntaje>1500){
        vx=-10;
    }
}

void enemigo_saltarin::movimiento()
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
    //El objeto realiza un mov parabolico, donde cada vez que toque el suelo este volvera a saltar
    //Con la misma velocidad en x,y
    posicion();
    if(estado){
        vy=60;
    }
    double yd;
    x=x+vx;
    y=y+vy-(9.8)/2;
    vy=vy-(9.8)/2;
    if(y<512)y=512;
    yd=2*512-y;
    setPos(int(x),int(yd));
    eliminar();
}
