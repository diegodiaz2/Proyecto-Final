#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "dialog.h"
#include "personaje.h"
#include "bala_horizontal.h"
#include "bala_parabolica.h"
#include "bala_caida.h"
#include "enemigo_volador.h"
#include "enemigo_caminante.h"
#include "enemigo_saltarin.h"
#include "enemigo_disparador.h"
#include "poder_vida.h"
#include "poder_circular.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    static MainWindow * getMainWinPtr();
    ~MainWindow();
    QGraphicsScene *escena=new QGraphicsScene(this);
    int puntaje=-10;
    int vidas=110;
    int tipo;
    void vida(int n);
    void score();
    QGraphicsView *view= new QGraphicsView (this);
    string n_usuario;
    QTimer *timer;
    bool juego=1;
private:
    static MainWindow * pMainWindow;
    Dialog *usuario;
    Ui::MainWindow *ui;
    personaje *jugador;
    personaje *jugador2;
    bala_horizontal *bala_tipo1;
    bala_parabolica *bala_tipo2;
    bala_caida *bala_tipo3;
    enemigo_volador *volador;
    enemigo_caminante *caminante;
    enemigo_saltarin *saltarin;
    enemigo_disparador *disparador;
    poder_circular *poder_circulo;
public slots:
    void crear_enemigos();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};
#endif // MAINWINDOW_H
