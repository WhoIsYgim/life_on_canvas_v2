#include "LineItemFactory.h"

IGraphicsItem *LineItemFactory::createItem() {
    auto* item_ = new LineItem();
    item_->setPen(contextPen);
    return item_;
}

LineItemFactory::LineItemFactory(QPen pen) : IGraphicsItemFactory(pen) {

}
