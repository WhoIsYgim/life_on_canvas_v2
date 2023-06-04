#ifndef CLIENT_LOC_ELLIPSEITEMFACTORY_H
#define CLIENT_LOC_ELLIPSEITEMFACTORY_H

#include "IGraphicsItemFactory.h"
#include "EllipseItem.h"

class EllipseItemFactory: public IGraphicsItemFactory {
public:
    explicit EllipseItemFactory(QPen pen);
    IGraphicsItem* createItem() override;
};


#endif //CLIENT_LOC_ELLIPSEITEMFACTORY_H
