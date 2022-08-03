#include "RectangleItemFactory.h"

IGraphicsItem *RectangleItemFactory::createItem() {
    auto* item_ = new RectangleItem();
    item_->setPen(contextPen);
    return item_;
}

RectangleItemFactory::RectangleItemFactory(QPen pen) : IGraphicsItemFactory(pen) {

}
