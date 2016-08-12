#include "mygraphicsscene.h"

MyGraphicsScene::MyGraphicsScene(QObject *parent) :
    QGraphicsScene(parent)
{
	scene = new QGraphicsScene(parent);
}

Coin *MyGraphicsScene::goAddPixmap(const QPixmap &pixmap)
{
    addPixmap(pixmap);
	Coin *c = new Coin();
	return c;
}

QRectF MyGraphicsScene::itemsBoundingRect()
{
	return sceneRect();
}

void MyGraphicsScene::setSceneRect(const QRectF &rect)
{

}
