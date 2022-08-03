#ifndef CLIENT_LOC_FREELINEITEM_H
#define CLIENT_LOC_FREELINEITEM_H

#include "IGraphicsItem.h"


#include <QGraphicsLineItem>

class FreeLineItem: public IGraphicsItem {
public:
    FreeLineItem();

    void onPress(QPoint initPoint) override;
    void onMoved(QPoint newPoint) override;
    void onReleased(QPoint newPoint) override;

    void setPen(QPen pen_) override;

private:
    void setCurrentLinePen (QPen pen);
    QGraphicsLineItem* currentLineItem;
    QPen linePen;
};



#endif //CLIENT_LOC_FREELINEITEM_H
