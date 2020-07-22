#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "windows.h"

MainWindow * MainWindow::pMainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   
    ui->setupUi(this);

    //Mostramos la ventana donde el usuario inicia sesion o se registra, esta no se podra quitar.

    usuario = new Dialog(this);
    usuario->setModal(true);
    usuario->show();


    score();
    vida();

    //Creamos la escena

    escena->setSceneRect(0, 0, 1817, 623);

    //Damos un fondo a la escena

    escena->setBackgroundBrush(QBrush(QImage(":/fondo_juego.jpg")));
    view->setScene(escena);
    view->resize(1000, 625);
    //Deshabilitamos la barra
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //Creamos un jugador
    jugador= new personaje(1);
    //Lo añadimos a la escena
    escena->addItem(jugador);
    pMainWindow=this;
    timer=new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(crear_enemigos()));
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    if(juego){
        if(tipo==1){
            timer->start(5000);
        }
        else if(tipo==2){
            jugador2=new personaje(2);
            escena->addItem(jugador2);
            timer->start(5000);
        }
        else{
            tipo=1;

        }
        juego=0;
    }

    //Desplazamos al jugador por el escenario
    if(tipo==1){
        if(event->key()==Qt::Key::Key_W){
            jugador->n=1;
        }
        if(event->key()==Qt::Key::Key_S){
            jugador->n=2;
        }
        if(event->key()==Qt::Key::Key_A){
            jugador->n=3;
        }
        if(event->key()==Qt::Key::Key_D){
            jugador->n=4;
        }
        //Cuando presione C crea una bala horizontal
        if(event->key()==Qt::Key::Key_C){
            bala_tipo1=new bala_horizontal(jugador->x()+30,jugador->y()+25,9,1);
            escena->addItem(bala_tipo1);
        }
        //Cuando presione V crea una bala que realiza un mov parabolico
        if(event->key()==Qt::Key::Key_V){
            bala_tipo2=new bala_parabolica(jugador->x()+30,jugador->y()+25);
            escena->addItem(bala_tipo2);
        }
        //Cuando presione X crea una bala que realiza un mov de caida libre
        if(event->key()==Qt::Key::Key_X){
            bala_tipo3=new bala_caida(jugador->x()+30,jugador->y()+25);
            escena->addItem(bala_tipo3);
        }
    }
    else if(tipo==2){
        if(event->key()==Qt::Key::Key_W){
            jugador->n=1;
        }
        if(event->key()==Qt::Key::Key_S){
            jugador->n=2;
        }
        if(event->key()==Qt::Key::Key_A){
            jugador->n=3;
        }
        if(event->key()==Qt::Key::Key_D){
            jugador->n=4;
        }
        //Cuando presione C crea una bala horizontal
        if(event->key()==Qt::Key::Key_C){
            bala_tipo1=new bala_horizontal(jugador->x()+30,jugador->y()+25,9,1);
            escena->addItem(bala_tipo1);
        }
        //Cuando presione V crea una bala que realiza un mov parabolico
        if(event->key()==Qt::Key::Key_V){
            bala_tipo2=new bala_parabolica(jugador->x()+30,jugador->y()+25);
            escena->addItem(bala_tipo2);
        }
        //Cuando presione X crea una bala que realiza un mov de caida libre
        if(event->key()==Qt::Key::Key_X){
            bala_tipo3=new bala_caida(jugador->x()+30,jugador->y()+25);
            escena->addItem(bala_tipo3);
        }
        //Teclas jugador 2
        if(event->key()==Qt::Key::Key_I){
            jugador2->n=1;
        }
        if(event->key()==Qt::Key::Key_K){
            jugador2->n=2;
        }
        if(event->key()==Qt::Key::Key_J){
            jugador2->n=3;
        }
        if(event->key()==Qt::Key::Key_L){
            jugador2->n=4;
        }
        //Cuando presione C crea una bala horizontal
        if(event->key()==Qt::Key::Key_1){
            bala_tipo1=new bala_horizontal(jugador2->x()+30,jugador2->y()+25,9,1);
            escena->addItem(bala_tipo1);
        }
        //Cuando presione V crea una bala que realiza un mov parabolico
        if(event->key()==Qt::Key::Key_2){
            bala_tipo2=new bala_parabolica(jugador2->x()+30,jugador2->y()+25);
            escena->addItem(bala_tipo2);
        }
        //Cuando presione X crea una bala que realiza un mov de caida libre
        if(event->key()==Qt::Key::Key_3){
            bala_tipo3=new bala_caida(jugador2->x()+30,jugador2->y()+25);
            escena->addItem(bala_tipo3);
        }
    }
    //El view se centra en la posicion del jugador
    view->centerOn(jugador->x(),jugador->y());
    //ui->label->setNum(jugador->avatar->x());
    //ui->label_2->setNum(jugador->avatar->y());
}

MainWindow *MainWindow::getMainWinPtr()
{
    return pMainWindow;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::vida()
{
    vidas-=10;
    if(vidas>=0) ui->label_4->setNum(vidas);
    if(vidas==20){
        poder_vida *health= new poder_vida();
        escena->addItem(health);
    }
    if(vidas<=0){
        QMessageBox::about(this,"Game Over","Estas sin vidas");
        close();
    }
}

void MainWindow::score()
{
    puntaje+=10;
    ui->label_2->setNum(puntaje);
    if(puntaje==100){
        timer->stop();
        timer->start(4000);
    }
    else if(puntaje==500){
        timer->stop();
        timer->start(3000);
    }
    else if(puntaje==1000){
        timer->stop();
        timer->start(2000);
    }
    else if(puntaje==1500){
        timer->stop();
        timer->start(1500);
    }
}

void MainWindow::crear_enemigos()
{
    int seleccion=rand()%4;
    if(seleccion==0){
        volador=new enemigo_volador();
        volador->velocidad(puntaje);
        escena->addItem(volador);
        saltarin=new enemigo_saltarin();
        saltarin->velocidad(puntaje);
        escena->addItem(saltarin);
    }
    else if(seleccion==1){
        caminante=new enemigo_caminante();
        caminante->velocidad(puntaje);
        escena->addItem(caminante);
        disparador=new enemigo_disparador();
        disparador->velocidad(puntaje);
        escena->addItem(disparador);
    }
    else if(seleccion==2){
        saltarin=new enemigo_saltarin();
        saltarin->velocidad(puntaje);
        escena->addItem(saltarin);
    }
    else{
        disparador=new enemigo_disparador();
        disparador->velocidad(puntaje);
        escena->addItem(disparador);
    }
}

