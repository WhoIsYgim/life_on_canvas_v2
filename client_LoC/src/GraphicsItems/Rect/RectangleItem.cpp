#include "RectangleItem.h"

#include <QDebug>

RectangleItem::RectangleItem()
{
    item = new QGraphicsRectItem();
}


void RectangleItem::onPress(QPoint initPoint) {

    setStartPoint(initPoint);
    setEndPoint(initPoint);

    QRect rect(startPoint, endPoint);
    static_cast<QGraphicsRectItem*>(item)->setRect(rect);
}

void RectangleItem::onMoved(QPoint newPoint) {
    setEndPoint(newPoint);

     QRect rect;

    if (startPoint.x() < endPoint.x() ) {
        if (startPoint.y() < endPoint.y()) {
            rect.setRect(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());

        } else {
            rect.setRect(startPoint.x(), endPoint.y(), endPoint.x() - startPoint.x(), startPoint.y() - endPoint.y());

        }
    } else {
        if (startPoint.y() < endPoint.y()) {
            rect.setRect(endPoint.x(), startPoint.y(), startPoint.x() - endPoint.x(), endPoint.y() - startPoint.y());
        } else {
            rect.setRect(endPoint.x(), endPoint.y(), startPoint.x() - endPoint.x(), startPoint.y() - endPoint.y());
        }
    }


    static_cast<QGraphicsRectItem*>(item)->setRect(rect);

}

void RectangleItem::onReleased(QPoint newPoint) {

    setEndPoint(newPoint);

    QRect rect;

    if (startPoint.x() < endPoint.x() ) {
        if (startPoint.y() < endPoint.y()) {
            rect.setRect(startPoint.x(), startPoint.y(), endPoint.x() - startPoint.x(), endPoint.y() - startPoint.y());

        } else {
            rect.setRect(startPoint.x(), endPoint.y(), endPoint.x() - startPoint.x(), startPoint.y() - endPoint.y());

        }
    } else {
        if (startPoint.y() < endPoint.y()) {
            rect.setRect(endPoint.x(), startPoint.y(), startPoint.x() - endPoint.x(), endPoint.y() - startPoint.y());
        } else {
            rect.setRect(endPoint.x(), endPoint.y(), startPoint.x() - endPoint.x(), startPoint.y() - endPoint.y());
        }
    }
    static_cast<QGraphicsRectItem*>(item)->setRect(rect);
}

void RectangleItem::setPen(QPen pen_) {
    static_cast<QGraphicsRectItem*>(item)->setPen(pen_);
}
