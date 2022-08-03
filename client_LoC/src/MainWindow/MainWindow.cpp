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

    this->setMinimumHeight(300);
    this->setMinimumWidth(500);

    createNewButton = new QPushButton("Create new canvas", this);
    connectButton = new QPushButton("Connect to existing", this);
    label = new QLabel("Life On Canvas", this);

    QFont labelFont("Helvetica [Cronyx]");
    labelFont.setPixelSize(55);
    label->setFont(labelFont);

    connect(createNewButton, SIGNAL(clicked()), this, SLOT(onCreateNewButtonClicked()));

}

void MainWindow::resizeEvent(QResizeEvent* event){
    Q_UNUSED(event);


    QRect geometryRect = this->geometry();
    createNewButton->setGeometry({geometryRect.bottomRight().x()/3 , geometryRect.bottomRight().y()/2,
                                  geometryRect.bottomRight().x()/3, 70});
    connectButton->setGeometry({geometryRect.bottomRight().x()/3 , geometryRect.bottomRight().y()/2 - 150,
                                geometryRect.bottomRight().x()/3, 70});
    label->setGeometry({geometryRect.bottomRight().x()/3 - 25, 30,
                        500, 100});
}


MainWindow::~MainWindow(){
    delete controller;
    delete ui;
    delete view;
    delete toolbar;

}

void MainWindow::onCreateNewButtonClicked(){
    //label->hide();
    createNewButton->hide();
    connectButton->hide();
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
