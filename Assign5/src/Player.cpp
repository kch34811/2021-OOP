#include "Player.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "F.h"
#include "A.h"
#include <stdlib.h>

Player::Player(QGraphicsItem *parent): QGraphicsEllipseItem(parent){

}

void Player::keyPressEvent(QKeyEvent *event){
    // move the player left and right
    if (event->key() == Qt::Key_Left){
        if (pos().x() > 0)
        setPos(x()-10,y());
    }
    else if (event->key() == Qt::Key_Right){
        if (pos().x() + 30 < 800)
        setPos(x()+10,y());
    }
}

void Player::spawn(){
    // create an grade in random
    int random_number = rand()%2 +1;
    if(random_number == 1){
        A* a = new A();
        scene()->addItem(a);
    }
    else if(random_number == 2){
        F* f = new F();
        scene()->addItem(f);
    }
}
