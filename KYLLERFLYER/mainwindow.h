#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
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
    ~MainWindow();

private:
    Dialog *usuario;
    Ui::MainWindow *ui;
    QGraphicsScene *escena=new QGraphicsScene(this);
    QGraphicsView *view= new QGraphicsView (this);
};
#endif // MAINWINDOW_H
