#include "bala_vertical.h"
#include "mainwindow.h"

bala_vertical::bala_vertical( int x, int y)
{
    posx = x;
    posy = y;
    y0=y;
    //Le damos una posicion inicial
    setPos(posx,posy);
    QTimer *t=new QTimer();
    //Conectamos la funcion movimiento al timer
    connect(t,SIGNAL(timeout()),this,SLOT(movimiento()));
    t->start(50);
}

QRectF bala_vertical::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void bala_vertical::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
}

void bala_vertical::borrar()
{
    //Se verifican las colisiones
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(personaje)){
            mv->vida(1);
            mv->escena->removeItem(this);
            delete this;
            return;
        }
    }
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    if(posx<0 or posx>1786){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
    else if(yd>570){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
    if(mv->vidas<=0){
        mv->escena->removeItem(this);
        delete this;
        return;
    }
}

void bala_vertical::movimiento()
{
    //La bala realiza un mov de caida libre, por lo que no tiene velocidad en x
    //Pero en y si, aparte agregamos un yd, que es el que nos permite colocar las coordenadas bien
    //Debido a que en Qt el eje y esta invertido
    posy=posy+vely-(9.8)/2;
    vely=vely-(9.8)/2;
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
    borrar();
}
