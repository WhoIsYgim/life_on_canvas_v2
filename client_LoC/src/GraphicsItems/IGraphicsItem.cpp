#include "IGraphicsItem.h"

IGraphicsItem::IGraphicsItem(QGraphicsItem* itemType): item(itemType)
{

}

void IGraphicsItem::setStartPoint (QPoint newStartPoint) {
    startPoint = newStartPoint;
}

void IGraphicsItem::setEndPoint (QPoint newEndPoint) {
    endPoint = newEndPoint;
}

IGraphicsItem::~IGraphicsItem() {
    delete item;
}

QGraphicsItem *IGraphicsItem::getItem() {
    return item;
}

