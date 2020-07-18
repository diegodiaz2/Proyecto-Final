#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <QGraphicsPixmapItem>

class personaje: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    QGraphicsPixmapItem *avatar;
    personaje();
    int velocidad();
    void sprites();
private:
    int vel=8;
    bool estado=0;
};

#endif // PERSONAJE_H
