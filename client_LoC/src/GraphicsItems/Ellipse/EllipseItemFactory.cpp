#include "EllipseItemFactory.h"

IGraphicsItem *EllipseItemFactory::createItem() {
    auto *item_ = new EllipseItem();
    item_->setPen(contextPen);
    return item_;

}

EllipseItemFactory::EllipseItemFactory(QPen pen) : IGraphicsItemFactory(pen) {

}
