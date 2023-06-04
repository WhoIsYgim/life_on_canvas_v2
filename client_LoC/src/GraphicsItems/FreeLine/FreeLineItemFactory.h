#ifndef CLIENT_LOC_FREELINEITEMFACTORY_H
#define CLIENT_LOC_FREELINEITEMFACTORY_H

#include "IGraphicsItemFactory.h"
#include "FreeLineItem.h"

class FreeLineItemFactory: public IGraphicsItemFactory {
public:
    explicit FreeLineItemFactory(QPen pen);
    IGraphicsItem* createItem() override;
};


#endif //CLIENT_LOC_FREELINEITEMFACTORY_H
