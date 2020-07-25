#include "personaje.h"
#include "mainwindow.h"
#include "poder_vida.h"

personaje::personaje(int n)
{
    j=n;
    //Se le da un sprite distinto a los personajes
    if(n==1){
        setPos(900,512);
        setPixmap(QPixmap(":/Personaje0.png").scaled(30,50));
        t=new QTimer();
    }
    else{
        setPos(900,512);
        setPixmap(QPixmap(":/Personaje0 (2).png").scaled(30,50));
        t=new QTimer();
    }
    //Se realiza un connect con la funcion movimiento
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

int personaje::velocidad()
{
    return vel;
}

void personaje::sprites()
{
    if(j==1){
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
    }
    else{
        //Cuando el personaje se encuentre en el suelo se le colocan sprites de caminar
        if(y()==512){
            if(estado)setPixmap(QPixmap(":/Personaje1 (2).png").scaled(30,50));
            else setPixmap(QPixmap(":/Personaje2 (2).png").scaled(30,50));
            estado=!estado;
        }
        //Cuando no este en el suelo estara volando, por lo que tendra el jetpack prendido
        else if(y()!=512){
            setPixmap(QPixmap(":/Personaje3 (2).png").scaled(30,50));
        }
    }
    poder_vidas();
}

void personaje::movimiento()
{
    sprites();
    MainWindow *mv=MainWindow::getMainWinPtr();
    if(n==1){//Hacia arriba
        if(limites(4))setPos(x(),y()-vel);
    }
    else if(n==2){//Hacia abajo
        if(limites(3))setPos(x(),y()+vel);
    }
    else if(n==3){//Hacia izquierda
        if(limites(2))setPos(x()-vel+2,y());
    }
    else if(n==4){//Hacia derecha
        if(limites(1))setPos(x()+vel-2,y());
    }
    if(j==1){
        //El view se centra en el personaje principal
        mv->view->centerOn(x(),y());
    }
}

bool personaje::limites(int k)
{
    //Manejamos los limites del escenario
    if(k==1){
        if(x()>=0 and x()+8<=1786) return true;
        else return 0;
    }
    if(k==2){
        if(x()<=1786 and x()-8>=0)return true;
        else return false;
    }
    if(k==3){
        if(y()>=0 and y()+8<=512) return true;
        else return 0;
    }
    if(k==4){
        if(y()-8>=0 and y()<=512) return true;
        else return 0;
    }
    else return false;
}

void personaje::poder_vidas()
{
    //Se revisan las colisiones
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(poder_vida)){
            //Se remueve el poder vida
            mv->escena->removeItem(colliding_items[i]);
            delete colliding_items[i];
            //Se regenera la vida
            mv->vidas=110;
            mv->vida(1);
        }
    }
}
