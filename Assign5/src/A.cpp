#include "A.h"
#include "Player.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <QPainter>
#include <stdlib.h>
#include <QGraphicsTextItem>
#include <QPen>
#include "Game.h"

extern Game * game;

A::A(QGraphicsItem *parent): QObject(), QGraphicsRectItem(parent){
    //set random x position
    setPos(rand()%(800-40), 0);

    // drew the rect
    setRect(0,0,40,40);

    QPen brush;
    brush.setStyle(Qt::SolidLine);
    brush.setColor(Qt::blue);
    setPen(brush);

    text = new QGraphicsTextItem(QString("A"));
    QFont titleFont("comic sans", 15);
    text->setFont(titleFont);
    int txPos = this->x();
    int tyPos = this->y();
    text->setPos(txPos,tyPos);
    game->scene->addItem(text);

    // make/connect a timer to move()
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(20);
}

void A::move(){
    // get a list of all the items currently colliding with this
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Player, destroy this
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Player)){
            // increase the score
            game->score->increase();

            // remove them from the scene (still on the heap)
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete this;
            delete text;

            // return
            return;
        }
    }

    // move down
    setPos(x(),y()+10);
    text->setPos(text->x(), text->y()+10);

    // destroy when it goes out of the screen
    if (pos().y() > 800){
        scene()->removeItem(this);
        delete this;
        delete text;
    }
}
