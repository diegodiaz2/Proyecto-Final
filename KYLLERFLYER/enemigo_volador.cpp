#include "enemigo_volador.h"
#include <stdlib.h>
#include <time.h>

enemigo_volador::enemigo_volador()
{
    QTimer *t= new QTimer();
    y=posicion();
    x=1780;
    setPos(1780, y);
    setPixmap(QPixmap(":/enemigo_volador.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

int enemigo_volador::posicion()
{
    srand(time(NULL));
    int y=rand()%400;
    return y;
}

void enemigo_volador::movimiento()
{
    x=x+vx;
    setPos(x, y);

}
