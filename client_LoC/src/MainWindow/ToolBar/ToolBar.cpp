#include "ToolBar.h"

#include <QAction>
#include <QColorDialog>
#include <QInputDialog>

#include <QGraphicsLineItem>



ToolBar::ToolBar()
{
    setOrientation(Qt::Vertical);
    setAllowedAreas(Qt::RightToolBarArea);
    setMovable(false);
    setFloatable(false);

    regularPenAction = new QAction("pen");
    lineAction = new QAction("line");
    rectangleAction = new QAction("rect");
    ellipseAction = new QAction("ellipse");
    setColorAction = new QAction("color");
    setWidthAction = new QAction("width");
    setStyleAction = new QAction("style");
    undoAction = new QAction("undo");


    this->addAction(regularPenAction);
    this->addAction(lineAction);
    this->addAction(rectangleAction);
    this->addAction(ellipseAction);
    this->addAction(setWidthAction);
    this->addAction(setColorAction);
    this->addAction(setStyleAction);
    this->addAction(undoAction);


    stylesList << tr("SoldLine") << tr("DashLine")
           << tr("DotLine") << tr("DashDotLine")
           << tr("DashDotDotLine");


    connect( regularPenAction, SIGNAL(triggered()), this, SLOT( onActionPenTriggered() ) );
    connect( lineAction, SIGNAL(triggered()), this, SLOT( onActionLineTriggered() ) );
    connect( rectangleAction, SIGNAL(triggered()), this, SLOT( onActionRectTriggered() ) );
    connect( ellipseAction, SIGNAL(triggered()), this, SLOT( onActionEllipseTriggered() ) );
    connect( setWidthAction, SIGNAL(triggered()), this, SLOT( onActionWidthTriggered() ) );
    connect( setColorAction, SIGNAL(triggered()), this, SLOT( onActionColorTriggered() ) );
    connect( setStyleAction, SIGNAL(triggered()), this, SLOT( onActionStyleTriggered() ) );
    connect(undoAction, SIGNAL(triggered()), this, SLOT(onActionUndoTriggered()));

    currentPen = new QPen();
    currentPen->setColor(QColor(0,0,0));
    chosenToolItemFactory = new LineItemFactory(*currentPen);
}


void ToolBar::onActionPenTriggered() {
        delete chosenToolItemFactory;

    chosenToolItemFactory = new FreeLineItemFactory(*currentPen);

}

void ToolBar::onActionLineTriggered(){
    delete chosenToolItemFactory;
    chosenToolItemFactory = new LineItemFactory(*currentPen);
}

void ToolBar::onActionRectTriggered(){
    delete chosenToolItemFactory;
    chosenToolItemFactory = new RectangleItemFactory(*currentPen);

}
void ToolBar::onActionEllipseTriggered(){
    delete chosenToolItemFactory;
    chosenToolItemFactory = new EllipseItemFactory(*currentPen);
}

void ToolBar::onActionWidthTriggered() {
    int newWidth = QInputDialog::getInt(this, "Width","Input width value (1px - 100px):", 1, 1, 100 );
    currentPen->setWidth(newWidth);
    chosenToolItemFactory->setPen(*currentPen);
}

void ToolBar::onActionColorTriggered() {
    QColor newColor = QColorDialog::getColor();
    currentPen->setColor(newColor);
    chosenToolItemFactory->setPen(*currentPen);

}

void ToolBar::onActionStyleTriggered() {
    QString newStyleStr = QInputDialog::getItem(this, "Style", "Choose a style for the currentPen:", stylesList, 0, false);

    if (newStyleStr == tr("SolidLine")){
        currentPen->setStyle(Qt::SolidLine);

    } else  if (newStyleStr == tr("DashLine")){
        currentPen->setStyle(Qt::DashLine);

    } else  if (newStyleStr == tr("DotLine")){
        currentPen->setStyle(Qt::DotLine);

    } else  if (newStyleStr == tr("DashDotLine")){
        currentPen->setStyle(Qt::DashDotLine);

    } else {
        currentPen->setStyle(Qt::DashDotDotLine);
    }

    chosenToolItemFactory->setPen(*currentPen);
}

void ToolBar::onActionUndoTriggered() {
    emit undoActionTriggered();
}

ToolBar::~ToolBar() {
    delete chosenToolItemFactory;
    delete currentPen;
    delete regularPenAction;
    delete lineAction;
    delete rectangleAction;
    delete ellipseAction;
    delete setWidthAction;
    delete setColorAction;
    delete setStyleAction;
    delete undoAction;
}