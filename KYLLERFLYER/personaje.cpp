#include "personaje.h"

personaje::personaje()
{
    avatar=new QGraphicsPixmapItem();
    avatar->setPos(900,512);
    avatar->setPixmap(QPixmap(":/Personaje0.png").scaled(30,50));
}

int personaje::velocidad()
{
    return vel;
}

void personaje::sprites()
{
    if(avatar->y()==512){
        if(estado)avatar->setPixmap(QPixmap(":/Personaje1.png").scaled(30,50));
        else avatar->setPixmap(QPixmap(":/Personaje2.png").scaled(30,50));
        estado=!estado;
    }
    else if(avatar->y()!=512){
        avatar->setPixmap(QPixmap(":/Personaje3.png").scaled(30,50));
    }
}
