#include "Game.h"
#include <QTimer>
#include <QFont>
#include <QGraphicsTextItem>
#include "Button.h"
#include <QMessageBox>
#include <QBrush>

Game::Game(QWidget *parent){
    // set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,800);

    // set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,800);
    setScene(scene);
}

void Game::displayMainMenu()
{
    //create the play button
    Button* playButton = new Button(QString("Start"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = this->height()/2 - playButton->boundingRect().height()/2;
    playButton->setPos(bxPos, byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);
}

void Game::Gameover()
{
    scene->clear();
    delete timer;
    QMessageBox msgBox;
    msgBox.setWindowTitle("End");
    msgBox.setText("Game Over");
    msgBox.setInformativeText("Score: " + QString::number(score->getScore()));
    msgBox.setStandardButtons(QMessageBox::Ok);
    if(msgBox.exec() == QMessageBox::Ok)
            this->close();
}

void Game::start()
{
    scene->clear();
    // create the player
    player = new Player();
    player->setRect(0,0,30,30);
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::green);
    player->setBrush(brush);
    player->setPos(800/2-player->rect().width()/2, 800-player->rect().height()); // TODO generalize to always be in the middle bottom of screen
    // make the player focusable and set it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score
    score = new Score();
    scene->addItem(score);

    timer = new Timer();
    QTimer * T_timer = new QTimer();
    QObject::connect(T_timer,SIGNAL(timeout()),timer,SLOT(upload()));
    T_timer->start(10);

    QTimer * G_timer = new QTimer();
    QObject::connect(G_timer,SIGNAL(timeout()),player,SLOT(spawn()));
    G_timer->start(500);

    show();

    QTimer::singleShot(30000, this, SLOT(Timeover()));

}

void Game::Timeover(){
    scene->clear();
    delete timer;
    QMessageBox msgBox;
    msgBox.setWindowTitle("End");
    msgBox.setText("Score: " + QString::number(score->getScore()));
    msgBox.setStandardButtons(QMessageBox::Ok);
    if(msgBox.exec() == QMessageBox::Ok)
            this->close();
}
