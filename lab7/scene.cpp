#include "scene.h"

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    R = 2;
    Apple = addPixmap(QPixmap("../lab7/apple.png"));
    QTransform tran = Apple->transform();
    tran.translate(25, 25);
    Apple->setTransform(tran);
    Apple->setData(0, "Obstacle");
    Apple->setFlags(QGraphicsItem::ItemIsMovable);

    QPen pen(Qt::black);
    QBrush brush(Qt::black);
    Log = addRect(QRectF(20, 80, 40, 160), pen, brush);
    Log->setData(0, "Obstacle");
    Log->setFlags(QGraphicsItem::ItemIsMovable);

    pen.setColor(Qt::black);
    brush.setColor(Qt::green);
    Leaves = addEllipse(QRectF(40, 40, 180, 120), pen, brush);
    Leaves->setData(0, "Obstacle");
    Leaves->setFlags(QGraphicsItem::ItemIsMovable);

    Bird = addPixmap(QPixmap("../lab7/bird.png"));
    tran = Bird->transform();
    tran.translate(300, 250);
    Bird->setTransform(tran);
    Bird->setData(0, "Bird");

    pen.setColor(Qt::yellow);
    brush.setColor(Qt::yellow);
    left = addLine(10, 350, 10, 0, pen);
    left->setData(0, "Obstacle");
    bottom = addLine(450, 340, 0, 340, pen);
    bottom->setData(0, "Obstacle");
    left1 = addRect(QRectF(10, 350, -10, -350), pen, brush);
    left1->setData(0, "Obstacle");
    bottom1 = addRect(QRectF(450, 350, -450, -10), pen, brush);
    bottom1->setData(0, "Obstacle");
    right = addRect(QRectF(450, 0, -10, 350), pen, brush);
    right->setData(0, "Obstacle");
    up = addRect(QRectF(0, 0, 450, 10), pen, brush);
    up->setData(0, "Obstacle");

//    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(MoveBird()));
    timer->start(25);
}

QGraphicsItem* Scene::itemCollidesWith(QGraphicsItem* item)
{
    QList<QGraphicsItem* > collisions = collidingItems(item);
    foreach(QGraphicsItem* it, collisions)
    {
        if (it == item) continue;
        return it;
    }
    return NULL;
}

void Scene::MoveBird()
{
    QPointF np;
    np.setX(0);
    np.setY(0);
    switch(R)
    {
        case 1: np.setX(-10); break;
        case 2: np.setX(10); break;
        case 3: np.setY(-10); break;
        case 4: np.setY(10); break;
    }
//    qDebug << std::to_string(np.x());
    QTransform tran = Bird->transform();
    tran.translate(np.x(), np.y());
    Bird->setTransform(tran);
    QGraphicsItem* obstacle = itemCollidesWith(Bird);
    tran = Bird->transform();
    if (obstacle)
    {
        if (obstacle->data(0) == "Obstacle")
        {
            tran.translate(-np.x(), -np.y());
            Bird->setTransform(tran);
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distr(1, 4);
            R = (int)distr(gen);
        }
    }
}

Scene::~Scene()
{
    delete this;
}
