#include "Timer.h"
#include <QGraphicsTextItem>
#include <QTimer>
#include <QFont>
#include "Game.h"
#include <QTimer>

extern Game * game;

Timer::Timer()
{
    second = 30.00;
    text = new QGraphicsTextItem(QString("Time: ")+ QString::number(second));
    QFont Font("times",16);
    text->setFont(Font);
    text->setPos(0,30);
    game->scene->addItem(text);

}

int Timer::get_second()
{
    return second;
}

void Timer::upload()
{
    second = second - 0.01;
    text->setPlainText("Time: "+ QString::number(second));
}
