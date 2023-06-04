#ifndef CLIENT_LOC_IGRAPHICSITEMFACTORY_H
#define CLIENT_LOC_IGRAPHICSITEMFACTORY_H

#include "IGraphicsItem.h"

class IGraphicsItemFactory {
public:
    IGraphicsItemFactory(QPen pen);
    virtual ~IGraphicsItemFactory();
    virtual IGraphicsItem* createItem() = 0;

    void setPen(QPen pen);
protected:
    QPen contextPen;
};


#endif //CLIENT_LOC_IGRAPHICSITEMFACTORY_H
