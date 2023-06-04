#include "CanvasController.h"


CanvasController::CanvasController(View* view_, GraphicsScene* scene_, ToolBar* toolbar_):
    view(view_), toolbar(toolbar_)
{
   connect (view, SIGNAL(pressSignal(QPoint)), this, SLOT(onMousePressed(QPoint)));
   connect (view, SIGNAL(moveSignal(QPoint)), this, SLOT(onMouseMoved(QPoint)));
   connect (view, SIGNAL(releaseSignal(QPoint)), this, SLOT(onMouseReleased(QPoint)));

   connect(toolbar, SIGNAL(undoActionTriggered()), this, SLOT(onUndoTriggered()));

    currentFactory = toolbar->chosenToolItemFactory;
    storage = new Storage(scene_);
}

void CanvasController::onMousePressed(QPoint eventPoint){
    currentFactory = toolbar->chosenToolItemFactory;
    currentItem = currentFactory->createItem();
    currentItem->onPress(eventPoint);
    storage->addItem(currentItem);
}
void CanvasController::onMouseMoved(QPoint eventPoint){
    currentItem->onMoved(eventPoint);
}
void CanvasController::onMouseReleased(QPoint eventPoint){
    currentItem->onReleased(eventPoint);
}

void CanvasController::onUndoTriggered() {
    storage->deleteLast();
}

CanvasController::~CanvasController() {
    delete storage;
}



