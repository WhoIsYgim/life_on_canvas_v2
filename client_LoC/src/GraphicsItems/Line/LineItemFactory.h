#ifndef CLIENT_LOC_LINEITEMFACTORY_H
#define CLIENT_LOC_LINEITEMFACTORY_H

#include "IGraphicsItemFactory.h"
#include "LineItem.h"

class LineItemFactory: public IGraphicsItemFactory{
public:
    explicit LineItemFactory(QPen pen);
    IGraphicsItem* createItem() override;
};


#endif //CLIENT_LOC_LINEITEMFACTORY_H
