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

#define PC_VISUAL false // Setting this to 'True' will display the 'thinking' done by Minimax

struct Move {
	int value, x;
	Move() : value(0), x(0) {}
	Move(int _value) : value(_value), x(0) {}
	Move(int _value, int _x) : value(_value), x(_x) {}
};

class MyGraphicsView : public QGraphicsView
{
    QGraphicsPixmapItem *item;
    QPixmap yellow, red;
    Coin *arrayOfCoins[7][6];
    MyGraphicsScene *myScene;
    short turnNumber;
    bool *turn, *playerTurn;
	QPoint point_1, point_2; // For drawing the winning line
	int my_rating;

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

	Move minimaximum(bool, int);

private slots:
    void keyPressEvent(QKeyEvent *event);
};
#endif // MYGRAPHICSVIEW_H
