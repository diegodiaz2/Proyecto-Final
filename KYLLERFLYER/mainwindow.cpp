#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //Mostramos la ventana donde el usuario inicia sesion o se registra, esta no se podra quitar.

    usuario = new Dialog(this);
    usuario->setModal(true);
    usuario->show();
    ui->setupUi(this);

    //Creamos la escena

    escena->setSceneRect(0, 0, 1817, 623);

    //Damos un fondo a la escena

    escena->setBackgroundBrush(QBrush(QImage(":/fondo_juego.jpg")));
    view->setScene(escena);
    view->resize(1000, 646);
    jugador= new personaje();
    escena->addItem(jugador->avatar);
}

void MainWindow::keyPressEvent(QKeyEvent *event){
    if(event->key()==Qt::Key::Key_W){
        if(limites(4)){
            jugador->avatar->setY(jugador->avatar->y()-jugador->velocidad());
            jugador->sprites();
        }
    }
    if(event->key()==Qt::Key::Key_S){
        if(limites(3)){
            jugador->avatar->setY(jugador->avatar->y()+jugador->velocidad());
            jugador->sprites();
        }
    }
    if(event->key()==Qt::Key::Key_A){
        if(limites(2)){
            jugador->avatar->setX(jugador->avatar->x()-jugador->velocidad());
            jugador->sprites();
        }
    }
    if(event->key()==Qt::Key::Key_D){
        if(limites(1)){
            jugador->avatar->setX(jugador->avatar->x()+jugador->velocidad());
            jugador->sprites();
        }
    }
    if(event->key()==Qt::Key::Key_Space){
        bala_tipo1=new bala_horizontal(jugador->avatar->x()+30,jugador->avatar->y()+25);
        escena->addItem(bala_tipo1);
    }
    view->centerOn(jugador->avatar->x(),jugador->avatar->y());
    ui->label->setNum(jugador->avatar->x());
    ui->label_2->setNum(jugador->avatar->y());
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::limites(int n)
{
    if(n==1){
        if(jugador->avatar->x()>=0 and jugador->avatar->x()+8<=1786) return true;
        else return 0;
    }
    if(n==2){
        if(jugador->avatar->x()<=1786 and jugador->avatar->x()-8>=0)return true;
        else return false;
    }
    if(n==3){
        if(jugador->avatar->y()>=0 and jugador->avatar->y()+8<=512) return true;
        else return 0;
    }
    if(n==4){
        if(jugador->avatar->y()-8>=0 and jugador->avatar->y()<=512) return true;
        else return 0;
    }
    else return false;
}

