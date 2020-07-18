#include "enemigo_volador.h"
#include "mainwindow.h"

void enemigo_volador::eliminar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mw=MainWindow::getMainWinPtr();
    if(x<0){
        mw->escena->removeItem(this);
        delete this;
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

void enemigo_volador::movimiento()
{
    //Se crea una bala y es añadida a la escena
    x=x+vx;
    setPos(x, y);
    eliminar();
}
