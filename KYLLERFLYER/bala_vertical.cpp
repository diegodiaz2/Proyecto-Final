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

void bala_vertical::setR(int radio)
{
    r = radio;
}

void bala_vertical::setPosx(int px)
{
    posx=px;
}

void bala_vertical::setPosy(int py)
{
    posy = py;
}

QRectF bala_vertical::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void bala_vertical::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    //Le damos un color verde
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void bala_vertical::borrar()
{
    //Cuando el objeto se encuentre fuera del escenario sera eliminado
    MainWindow *mv=MainWindow::getMainWinPtr();
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
}

void bala_vertical::movimiento()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    QList<QGraphicsItem *> colliding_items=collidingItems();
    for(int i=0, n=colliding_items.size(); i<n; i++){
        if (typeid (*(colliding_items[i])) == typeid(personaje)){
            mv->vida();
            mv->escena->removeItem(this);
            delete this;
            return;
        }
    }
    //La bala realiza un mov de caida libre, por lo que no tiene velocidad en x
    //Pero en y si, aparte agregamos un yd, que es el que nos permite colocar las coordenadas bien
    //Debido a que en Qt el eje y esta invertido
    vely=vely-(9.8)/2;
    posy=posy+vely-(9.8)/2;
    yd=2*y0-posy;
    setPos(int(posx),int(yd));
    borrar();
}
