#include "MainWindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->resize(900, 700);
    this->menuBar()->hide();

    connect(ui->createNewButton, SIGNAL(clicked()), this, SLOT(onCreateNewButtonClicked()));
}

void MainWindow::ResizeEvent(QResizeEvent* event){
    scene->setSceneRect(0, 0, view->width(), view->height());
}


MainWindow::~MainWindow(){
    delete controller;
    delete ui;
    delete view;
    delete toolbar;

}

void MainWindow::onCreateNewButtonClicked(){
    ui->label->hide();
    ui->createNewButton->hide();
    ui->connectButton->hide();
    ui->menubar->show();

    createScene();
    createView(scene);
    createToolBar();
    createController();
}

void MainWindow::createScene(){
    scene = new GraphicsScene(800, 600);
}

void MainWindow::createView(GraphicsScene *scene_){
    view = new View(scene_);
    setCentralWidget(view);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    view->setRenderHint(QPainter::Antialiasing);
    view->setMinimumSize (600, 400);
}

void MainWindow::createToolBar(){
    toolbar = new ToolBar();
    addToolBar(Qt::RightToolBarArea, toolbar);
}

void MainWindow::createController(){
    controller = new CanvasController(view, scene, toolbar);
}
