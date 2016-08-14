#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H
#include <QGraphicsScene>
#include <coin.h>


class MyGraphicsScene : public QGraphicsScene
{
public:
    MyGraphicsScene(QObject *parent = Q_NULLPTR);
    Coin *goAddPixmap(const QPixmap &pixmap);
    QRectF itemsBoundingRect();
    void setSceneRect(const QRectF &rect);
};

#endif // MYGRAPHICSSCENE_H
