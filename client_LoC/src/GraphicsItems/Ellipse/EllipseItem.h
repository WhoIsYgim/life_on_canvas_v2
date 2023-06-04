#ifndef ELLIPSEITEM_H
#define ELLIPSEITEM_H

#include "IGraphicsItem.h"
#include <QGraphicsEllipseItem>

class EllipseItem : public IGraphicsItem
{
public:
    EllipseItem();

    void onPress(QPoint initPoint) override;
    void onMoved(QPoint newPoint) override;
    void onReleased(QPoint newPoint) override;

    void setPen(QPen pen_) override;
};

#endif // ELLIPSEITEM_H
