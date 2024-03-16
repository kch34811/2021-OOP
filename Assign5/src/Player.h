#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsEllipseItem>
#include <QObject>
#include <QGraphicsItem>

class Player:public QObject, public QGraphicsEllipseItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    ~Player(){}
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};

#endif // PLAYER_H
