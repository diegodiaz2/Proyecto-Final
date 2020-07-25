#include "poder_vida.h"

poder_vida::poder_vida()
{
    //Se le da una posicion al azar
    int x,y;
    x=rand()%(1600);
    y=rand()%(500);
    setPos(x,y);
    //Se le da una imagen
    setPixmap(QPixmap(":/heart.png").scaled(40,40));
}
