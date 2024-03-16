#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include "Player.h"
#include "Score.h"
#include "Timer.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Game(QWidget* parent=NULL);
    ~Game(){}

    //public method
    void displayMainMenu();
    void Gameover();

    //public attributes
    QGraphicsScene * scene;
    Player * player;
    Score * score;
    Timer * timer;

public slots:
    void start();
    void Timeover();
};

#endif // GAME_H
