#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>

#include "View.h"
#include "ToolBar.h"
#include "GraphicsScene.h"
#include "CanvasController.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    GraphicsScene *scene = nullptr;
    View* view = nullptr;
    ToolBar *toolbar = nullptr;
    CanvasController* controller = nullptr;


    void createScene();
    void createView(GraphicsScene *scene_);
    void createToolBar();
    void createController();

protected:
    void ResizeEvent( QResizeEvent* event);

public slots:
    void onCreateNewButtonClicked();
};
#endif // MAINWINDOW_H
