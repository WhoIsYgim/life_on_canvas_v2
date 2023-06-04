#include "EllipseItem.h"



EllipseItem::EllipseItem()
{
    item = new QGraphicsEllipseItem();
}

void EllipseItem::onPress(QPoint initPoint) {
    setStartPoint(initPoint);
    setEndPoint(initPoint);

    QRect rect(startPoint, endPoint);
    static_cast<QGraphicsEllipseItem*>(item)->setRect(rect);
}

void EllipseItem::onMoved(QPoint newPoint) {
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


    static_cast<QGraphicsEllipseItem*>(item)->setRect(rect);
}

void EllipseItem::onReleased(QPoint newPoint) {
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


    static_cast<QGraphicsEllipseItem*>(item)->setRect(rect);
}

void EllipseItem::setPen(QPen pen_) {
    static_cast<QGraphicsEllipseItem*>(item)->setPen(pen_);
}
