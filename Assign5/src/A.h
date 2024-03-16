#ifndef A_H
#define A_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsTextItem>

class A: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    A(QGraphicsItem * parent=0);
    ~A() {}
public slots:
    void move();
private:
    QGraphicsTextItem * text;
};


#endif // A_H
