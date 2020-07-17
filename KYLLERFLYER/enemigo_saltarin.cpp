#include "enemigo_saltarin.h"
#include "mainwindow.h"

void enemigo_saltarin::eliminar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mw=MainWindow::getMainWinPtr();
    if(x<0){
        mw->escena->removeItem(this);
        delete this;
    }
}

enemigo_saltarin::enemigo_saltarin()
{
    QTimer *t= new QTimer();
    x=1780;
    y=512;
    setPos(1780, 512);
    //Le damos imagen al objeto
    setPixmap(QPixmap(":/Saltarin0.png").scaled(30,50));
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}
void enemigo_saltarin::posicion()
{
    //Se cambian las imagenes dependiendo de la posicion del objeto
    if(y==512) {
        setPixmap(QPixmap(":/Saltarin0.png").scaled(30,50));
        estado=1;
    }
    else if(y!=512){
        setPixmap(QPixmap(":/Saltarin1.png").scaled(30,50));
        estado=0;
    }
}

void enemigo_saltarin::movimiento()
{
    //El objeto realiza un mov parabolico, donde cada vez que toque el suelo este volvera a saltar
    //Con la misma velocidad en x,y
    posicion();
    if(estado){
        vx=-5;
        vy=60;
    }
    double yd;
    vy=vy-(9.8)/2;
    x=x+vx;
    y=y+vy-(9.8)/2;
    if(y<512)y=512;
    yd=2*512-y;
    setPos(int(x),int(yd));
    eliminar();
}
