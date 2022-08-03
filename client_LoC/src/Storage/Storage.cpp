#include "Storage.h"


void Storage::addItem(IGraphicsItem *item) {
    storageContainer.insert(std::make_pair(itemId, item));
    ++itemId; //лютейший костыль
    scene->addItem(item->getItem());
}

void Storage::updateItem(int itemId_) {

}

void Storage::deleteLast() {
    if (storageContainer.empty()) {
        return;
    }
    QGraphicsItem* itemToDelete= storageContainer.find(--itemId)->second->getItem();
    scene->removeItem(itemToDelete);
    storageContainer.erase(itemId);
    delete itemToDelete;
}

Storage::Storage(GraphicsScene *scene_): scene(scene_){

}

Storage::~Storage() {
    --itemId;
    while (itemId >= 0) {
        QGraphicsItem* itemToDelete= storageContainer.find(itemId)->second->getItem();
        scene->removeItem(itemToDelete);
        storageContainer.erase(itemId);
        delete itemToDelete;
        --itemId;
    }
    delete scene;
}