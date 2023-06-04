#ifndef CLIENT_LOC_RECTANGLEITEMFACTORY_H
#define CLIENT_LOC_RECTANGLEITEMFACTORY_H

#include "IGraphicsItemFactory.h"
#include "RectangleItem.h"

class RectangleItemFactory: public IGraphicsItemFactory {
public:
    explicit RectangleItemFactory(QPen pen);
    IGraphicsItem* createItem() override;

};


#endif //CLIENT_LOC_RECTANGLEITEMFACTORY_H
