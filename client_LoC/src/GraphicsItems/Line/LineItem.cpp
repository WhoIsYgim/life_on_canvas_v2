#include "LineItem.h"


LineItem::LineItem()
{
    item = new QGraphicsLineItem();
}


void LineItem::onPress(QPoint initPoint) {



    setStartPoint(initPoint);
    setEndPoint(initPoint);

    static_cast<QGraphicsLineItem*>(item)->setLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());

}

void LineItem::onMoved(QPoint newPoint) {

    setEndPoint (newPoint);

    static_cast<QGraphicsLineItem*>(item)->setLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());


}

void LineItem::onReleased(QPoint newPoint) {


    setEndPoint (newPoint);
    static_cast<QGraphicsLineItem*>(item)->setLine(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());

}

void LineItem::setPen(QPen pen_){
    static_cast<QGraphicsLineItem*>(item)->setPen(pen_);
}
