#include "enemigo_caminante.h"
#include <stdlib.h>
#include <time.h>

enemigo_caminante::enemigo_caminante()
{
    QTimer *t= new QTimer();
    QTimer *t2= new QTimer();
    x=1780;
    setPos(1780, 512);
    setPixmap(QPixmap(":/enemigo_caminante0.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
    connect(t2,SIGNAL(timeout()),this,SLOT(disparar()));
    t2->start(2000);

}


void enemigo_caminante::movimiento()
{
    if (estado) setPixmap(QPixmap(":/enemigo_caminante0.png").scaled(30, 50));
    else setPixmap(QPixmap(":/enemigo_caminante1.png").scaled(30, 50));
    estado=!estado;
    x=x+vx;
    setX(x);


}

void enemigo_caminante::disparar()
{
    bala=new bala_vertical(x, 500);
    setPixmap(QPixmap(":/enemigo_caminante.png").scaled(30,50));



}
