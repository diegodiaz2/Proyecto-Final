#include "personaje.h"
#include "mainwindow.h"
#include "poder_vida.h"

personaje::personaje()
{
    setPos(900,512);
    setPixmap(QPixmap(":/Personaje0.png").scaled(30,50));
}

int personaje::velocidad()
{
    return vel;
}

void personaje::sprites()
{
    //Cuando el personaje se encuentre en el suelo se le colocan sprites de caminar
    if(y()==512){
        if(estado)setPixmap(QPixmap(":/Personaje1.png").scaled(30,50));
        else setPixmap(QPixmap(":/Personaje2.png").scaled(30,50));
        estado=!estado;
    }
    //Cuando no este en el suelo estara volando, por lo que tendra el jetpack prendido
    else if(y()!=512){
        setPixmap(QPixmap(":/Personaje3.png").scaled(30,50));
    }
    poder_vidas();
}

void personaje::poder_vidas()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(poder_vida)){
            mv->escena->removeItem(colliding_items[i]);
            delete colliding_items[i];
            mv->vidas=110;
            mv->vida();
        }
    }
}
