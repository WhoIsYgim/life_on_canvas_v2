#ifndef LINEITEM_H
#define LINEITEM_H

#include "IGraphicsItem.h"

#include <QGraphicsLineItem>


class LineItem : public IGraphicsItem
{
public:
    LineItem();

    void onPress(QPoint initPoint) override;
    void onMoved(QPoint newPoint) override;
    void onReleased(QPoint newPoint) override;

    void setPen(QPen pen_) override;
};

#endif // LINEITEM_H
