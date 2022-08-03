#ifndef VIEW_H
#define VIEW_H

#include <QObject>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QMouseEvent>

class View : public QGraphicsView

{
    Q_OBJECT
public:
    explicit View( QGraphicsScene* scene);

private:
    QGraphicsScene *scene;

protected:
    void mousePressEvent (QMouseEvent *event);
    void mouseMoveEvent (QMouseEvent *event);
    void mouseReleaseEvent (QMouseEvent *event);

signals:
    void pressSignal(QPoint);
    void moveSignal(QPoint);
    void releaseSignal(QPoint);
};

#endif // VIEW_H
