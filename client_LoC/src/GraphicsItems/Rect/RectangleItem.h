#ifndef RECTANGLEITEM_H
#define RECTANGLEITEM_H

#include "IGraphicsItem.h"
#include <QGraphicsRectItem>

class RectangleItem : public IGraphicsItem
{
public:
    RectangleItem();

    void onPress(QPoint initPoint) override;
    void onMoved(QPoint newPoint) override;
    void onReleased(QPoint newPoint) override;

    void setPen(QPen pen_) override;
};

#endif // RECTANGLEITEM_H
