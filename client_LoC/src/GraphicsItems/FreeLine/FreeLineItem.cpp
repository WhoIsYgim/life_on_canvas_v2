#include "FreeLineItem.h"


FreeLineItem::FreeLineItem() {
    item = new QGraphicsItemGroup();
    currentLineItem = nullptr;
}

void FreeLineItem::onPress(QPoint initPoint) {

    setStartPoint(initPoint);
    setEndPoint(initPoint);

    currentLineItem = new QGraphicsLineItem(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
    setCurrentLinePen(linePen);

    static_cast<QGraphicsItemGroup*>(item)->addToGroup(currentLineItem);
}

void FreeLineItem::onMoved(QPoint newPoint) {
    startPoint = endPoint;
    endPoint = newPoint;

    currentLineItem = new QGraphicsLineItem(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
    setCurrentLinePen(linePen);

    static_cast<QGraphicsItemGroup*>(item)->addToGroup(currentLineItem);
}

void FreeLineItem::onReleased(QPoint newPoint) {
    startPoint = endPoint;
    endPoint = newPoint;

    currentLineItem = new QGraphicsLineItem(startPoint.x(), startPoint.y(), endPoint.x(), endPoint.y());
    setCurrentLinePen(linePen);

    static_cast<QGraphicsItemGroup*>(item)->addToGroup(currentLineItem);
}

void FreeLineItem::setPen(QPen pen_) {
    linePen = pen_;
}

void FreeLineItem::setCurrentLinePen(QPen pen) {
    currentLineItem->setPen(pen);
}
