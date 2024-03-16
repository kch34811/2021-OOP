#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QGraphicsTextItem>

class Timer:public QObject{
    Q_OBJECT
public:
    Timer();
    ~Timer(){}
    int get_second();
private:
    double second;
    QGraphicsTextItem * text;
public slots:
    void upload();
};

#endif // TIMER_H
