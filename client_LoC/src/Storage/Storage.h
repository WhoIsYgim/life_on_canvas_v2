
#ifndef CLIENT_LOC_STORAGE_H
#define CLIENT_LOC_STORAGE_H

#include <unordered_map>

#include "GraphicsScene.h"
#include "IGraphicsItem.h"

class Storage {
public:
    explicit Storage(GraphicsScene* scene_);
    ~Storage();
    void addItem(IGraphicsItem* item);
    void updateItem(int itemId_);
    void deleteLast();

    std::unordered_map<int, IGraphicsItem*> storageContainer;

    int itemId = 0;
private:
    GraphicsScene* scene;
};


#endif //CLIENT_LOC_STORAGE_H
