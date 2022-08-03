#include "IGraphicsItemFactory.h"

#include <utility>

IGraphicsItemFactory::~IGraphicsItemFactory() {

}

void IGraphicsItemFactory::setPen(QPen pen) {
    contextPen = std::move(pen);
}

IGraphicsItemFactory::IGraphicsItemFactory(QPen pen): contextPen(pen) {

}
