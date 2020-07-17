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


void enemigo_caminante::movimiento()
{
    //El objeto caminante realiza un mov rectilineo, aparte de ello, dabo que en el suelo hay friccion
    //Esta velocidad inicial ira disminuyendo
    vx=vx*exp(-(0.05/50));
    //Se realiza un cambio de imagenes para simular el movimiento
    if (estado) setPixmap(QPixmap(":/enemigo_caminante.png").scaled(30, 50));
    else setPixmap(QPixmap(":/enemigo_caminante0.png").scaled(30, 50));
    estado=!estado;
    x=x+vx;
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
