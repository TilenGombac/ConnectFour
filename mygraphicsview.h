#ifndef MYGRAPHICSVIEW_H
#define MYGRAPHICSVIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QDebug>
#include "mygraphicsscene.h"
#include "coin.h"
#include <QApplication>
#include <QMessageBox>
#include <QtGlobal>
#include <QTime>
#include <ctime>
#include <QAbstractButton>
#include <QPushButton>
#include <fstream>
#include <math.h>

#define PC_VISUAL false // Vklop pokaze proces minimax algoritma, vendar traja veliko dlje

struct Poteza {
	int vrednost, x;
	Poteza() : vrednost(0), x(0) {}
	Poteza(int _vrednost) : vrednost(_vrednost), x(0) {}
    Poteza(int _vrednost, int _x) : vrednost(_vrednost), x(_x) {}
};

class MyGraphicsView : public QGraphicsView
{
    QGraphicsPixmapItem *item;
    QPixmap yellow, red;
    Coin *arrayOfCoins[7][6];
    MyGraphicsScene *myScene;
    short turnNumber;
    bool *turn, *playerTurn;
    QPoint point_1, point_2; // Za izris zmage
    int moj_rating;

public:
    MyGraphicsView(MyGraphicsScene *scene, QWidget *parent = Q_NULLPTR);
    void onLeftPress();
    void onRightPress();

    void setCoins(Coin *array[7][6]);
    void setItem(QGraphicsPixmapItem* _item);
    void setTurn(bool* _turn, bool * _playerTurn);
    void setPixmaps(QPixmap, QPixmap);

	int getRating();

    void moveDown();

    bool validCoin(int, int, bool);

    void clearBoard();

    bool checkWin(bool);
    bool checkDraw();
    void zakljucenaIgra(int);

    void computerMakesMove(int);

    QPoint dropCoin(int, bool);
    void hideCoin(int, int);

    int evaluateBoardValue(bool);

    Poteza minimaximum(bool, int);

private slots:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MYGRAPHICSVIEW_H
