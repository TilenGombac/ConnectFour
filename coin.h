#ifndef COIN_H
#define COIN_H
#include <QGraphicsPixmapItem>


class Coin : public QGraphicsPixmapItem {
	bool side; // 0 - yellow, 1 - red
public:
    Coin(QGraphicsItem* parent = 0);
    void setSide(bool);

    bool getSide();
};

#endif // COIN_H
