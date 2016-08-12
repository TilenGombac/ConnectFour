#include "coin.h"

Coin::Coin(QGraphicsItem* parent) :
    QGraphicsPixmapItem(parent)
{
    side = 0;
    setPos(0, 0);
}

void Coin::setSide(bool _side)
{
    side = _side;
}

bool Coin::getSide()
{
    return side;
}
