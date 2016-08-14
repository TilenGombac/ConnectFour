#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

Coin *MyGraphicsScene::goAddPixmap(const QPixmap &pixmap)
{
    addPixmap(pixmap);
}

QRectF MyGraphicsScene::itemsBoundingRect()
{
}

void MyGraphicsScene::setSceneRect(const QRectF &rect)
{

}
