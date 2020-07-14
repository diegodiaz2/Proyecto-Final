#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialog.h"
#include "personaje.h"
#include "bala_horizontal.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    ~MainWindow();

private:
    Dialog *usuario;
    Ui::MainWindow *ui;
    QGraphicsScene *escena=new QGraphicsScene(this);
    QGraphicsView *view= new QGraphicsView (this);
    personaje *jugador;
    bala_horizontal *bala_tipo1;
    bool limites(int n);
};
#endif // MAINWINDOW_H
