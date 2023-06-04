#include "View.h"
#include <QDebug>

View::View( QGraphicsScene *scene_) {
    this->scene = scene_;
    setScene(scene_);
}

void View::mousePressEvent( QMouseEvent* event){
    emit pressSignal(event->pos());
}


void View::mouseMoveEvent( QMouseEvent* event){
    emit moveSignal(event->pos());
}


void View::mouseReleaseEvent( QMouseEvent* event){
    emit releaseSignal(event->pos());
}
