#ifndef SCENE_H
#define SCENE_H
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QGraphicsTextItem>
#include <QGraphicsWidget>
#include <QTransform>
#include <QPen>
#include <QBrush>
#include <QTime>
#include <QTimer>
#include <QDebug>
#include <random>


class Scene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Scene(QObject* parent = 0);
    ~Scene();
private:
    QGraphicsEllipseItem* Leaves;
    QGraphicsPixmapItem* Apple;
    QGraphicsRectItem* Log;
    QGraphicsPixmapItem* Bird;
    QGraphicsRectItem* up;
    QGraphicsRectItem* right;
    QGraphicsLineItem* bottom;
    QGraphicsLineItem* left;
    QGraphicsRectItem* bottom1;
    QGraphicsRectItem* left1;
    int R;
    QGraphicsItem* itemCollidesWith(QGraphicsItem* item);
public slots:
    void MoveBird();
};

#endif // SCENE_H
