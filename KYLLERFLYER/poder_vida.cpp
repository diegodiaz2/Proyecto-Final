#include "poder_vida.h"

poder_vida::poder_vida()
{
    int x,y;
    x=rand()%(1600);
    y=rand()%(500);
    setPos(x,y);
    setPixmap(QPixmap(":/heart.png").scaled(40,40));
}
