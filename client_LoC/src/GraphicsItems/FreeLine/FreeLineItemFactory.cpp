#include "FreeLineItemFactory.h"

IGraphicsItem *FreeLineItemFactory::createItem() {
    auto* item_= new FreeLineItem();
    item_->setPen(contextPen);
    return item_;
}

FreeLineItemFactory::FreeLineItemFactory(QPen pen) : IGraphicsItemFactory(pen) {

}
