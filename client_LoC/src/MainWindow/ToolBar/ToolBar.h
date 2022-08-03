#ifndef TOOLBAR_H
#define TOOLBAR_H

#include <QWidget>
#include <QToolBar>
#include <QToolButton>
#include <QGraphicsItem>

#include "IGraphicsItemFactory.h"
#include "LineItemFactory.h"
#include "FreeLineItemFactory.h"
#include "RectangleItemFactory.h"
#include "EllipseItemFactory.h"

class ToolBar : public QToolBar
{
    Q_OBJECT
public:
    ToolBar();
    ~ToolBar();
    IGraphicsItemFactory* chosenToolItemFactory;

private:
    QAction* regularPenAction;
    QAction* lineAction;
    QAction* rectangleAction;
    QAction* ellipseAction;
    QAction* setWidthAction;
    QAction* setColorAction;
    QAction* setStyleAction;
    QAction* undoAction;

    QStringList stylesList;

    QPen* currentPen;
public slots:
    void onActionPenTriggered();
    void onActionLineTriggered();
    void onActionRectTriggered();
    void onActionEllipseTriggered();
    void onActionWidthTriggered();
    void onActionColorTriggered();
    void onActionStyleTriggered();
    void onActionUndoTriggered();

signals:
    void undoActionTriggered();
};

#endif // TOOLBAR_H
