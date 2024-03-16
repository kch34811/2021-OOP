#ifndef F_H
#define F_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsItem>

class F: public QObject,public QGraphicsRectItem{
    Q_OBJECT
public:
    F(QGraphicsItem * parent=0);
    ~F(){}
public slots:
    void move();
private:
    QGraphicsTextItem * text;
};

#endif // F_H
