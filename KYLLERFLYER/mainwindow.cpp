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
}

MainWindow::~MainWindow()
{
    delete ui;
}

