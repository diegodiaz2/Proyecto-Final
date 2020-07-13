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
    view->resize(1000, 623);
    //Cambiamos el tamaño de la ventana
    this->resize(1000, 623);

}

MainWindow::~MainWindow()
{
    delete ui;
}

