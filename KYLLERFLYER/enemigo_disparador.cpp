#include "enemigo_disparador.h"
#include "mainwindow.h"

enemigo_disparador::enemigo_disparador()
{
    QTimer *t2= new QTimer();
    //Le damos imagen al objeto
    setPixmap(QPixmap(":/enemigo_disparador.png").scaled(30,50));
    //Se hace un connect con la funcion disparar
    connect(t2,SIGNAL(timeout()),this,SLOT(disparar()));
    t2->start(2000);
}

void enemigo_disparador::velocidad(int puntaje)
{
    //Dependiendo del puntaje, se aumenta la velocidad
    if(puntaje>=500 and puntaje < 700){
        enemigo_volador::vx=-5;
    }
    else if(puntaje>=700 and puntaje<1000){
        enemigo_volador::vx=-6;
    }
    else if(puntaje>=1000) enemigo_volador::vx=-7;
}

void enemigo_disparador::disparar()
{
    //Se crea una bala y es añadida a la escena
    MainWindow *mv=MainWindow::getMainWinPtr();
    bala=new bala_horizontal(enemigo_volador::x-10, enemigo_volador::y+30,-8, 2);
    mv->escena->addItem(bala);
}
