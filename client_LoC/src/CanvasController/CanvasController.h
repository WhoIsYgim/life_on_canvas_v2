#ifndef CANVASCONTROLLER_H
#define CANVASCONTROLLER_H

#include <QObject>

#include "GraphicsScene.h"
#include "View.h"
#include "ToolBar.h"
#include "IGraphicsItem.h"
#include "IGraphicsItemFactory.h"
#include "Storage.h"


class CanvasController : public QObject
{
    Q_OBJECT
public:
    CanvasController(View* view_, GraphicsScene* scene_ , ToolBar* toolbar_);
    ~CanvasController();

private:
    View* view;
    ToolBar* toolbar;

    IGraphicsItem* currentItem;
    IGraphicsItemFactory* currentFactory;

    Storage* storage;

public slots:
    void onMousePressed(QPoint eventPoint);
    void onMouseMoved(QPoint eventPoint);
    void onMouseReleased(QPoint eventPoint);

    void onUndoTriggered();
};

#endif // CANVASCONTROLLER_H
