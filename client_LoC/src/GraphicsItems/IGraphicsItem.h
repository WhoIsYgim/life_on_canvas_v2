#ifndef GRAPHICSITEM_H
#define GRAPHICSITEM_H

#include <QGraphicsItem>
#include <QPoint>
#include <QPen>


class IGraphicsItem
{
public:
    IGraphicsItem(QGraphicsItem* itemType = nullptr);
    virtual ~IGraphicsItem();
    virtual void onPress(QPoint initPoint) = 0;
    virtual void onMoved(QPoint newPoint) = 0;
    virtual void onReleased(QPoint newPoint) = 0;

    void setStartPoint (QPoint newStartPoint);
    void setEndPoint (QPoint newEndPoint);

    QGraphicsItem* getItem();

private:

protected:
    virtual void setPen(QPen pen_) = 0;

    QGraphicsItem* item;
    QPoint startPoint;
    QPoint endPoint;
};

#endif // GRAPHICSITEM_H
