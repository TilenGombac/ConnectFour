#include <QApplication>
#include <QPixmap>
#include <QtGlobal>
#include <ctime>

#include "coin.h"
#include "mygraphicsview.h"
#include "mygraphicsscene.h"

// TODO

// Fix drop on filled spot

int main(int argc, char *argv[])
{
    qsrand(time(NULL));
    QApplication a(argc, argv);
    QCoreApplication::setApplicationName("Štiri v vrsto - Tilen Gombač");
    QPixmap redCoin(":/coin/img/red_coin.png");
    QPixmap yellowCoin(":/coin/img/yellow_coin.png");
    MyGraphicsScene scene;
    MyGraphicsView view(&scene);
    Coin *coinItem, *coins[7][6]; // 7x6 polja
    bool turn = qrand() % 2, playerTurn = qrand() % 2;
    QPen pen;
    QColor color(0, 170, 238);
    pen.setColor(color);
    pen.setWidth(2);

    view.setTurn(&turn, &playerTurn);
    view.setPixmaps(yellowCoin, redCoin);

    if(turn == true)
        coinItem = scene.goAddPixmap(redCoin);
    else
        coinItem = scene.goAddPixmap(yellowCoin);
    coinItem->setPos(240, 0);
    view.setItem(coinItem);

    scene.addLine(0, 78, 560, 78, pen);

    // Narisemo crte, ki "omejujejo" zetone
    // Vertikalne
    for(int i = 0; i <= 5; i++)
        scene.addLine(78 + i * 80, 80, 78 + i * 80, 560, pen);

    // Horizontalne
    for(int i = 0; i <= 4; i++)
        scene.addLine(0, 158 + i * 80, 560, 158 + i * 80, pen);



    // Generiramo (skrite) rumene zetone
    for(int y = 0; y < 6; y++)
        for(int x = 0; x < 7; x++) {
            coins[x][y] = scene.goAddPixmap(yellowCoin);
            coins[x][y]->setPos(x * 80, (y + 1) * 80);
            coins[x][y]->setVisible(false);
        }
    view.setCoins(coins);
    if(turn != playerTurn)
        view.computerMakesMove(1200);

    scene.setSceneRect(scene.itemsBoundingRect());
    //scene.addLine(0, 0, 560, 560, pen);

    view.show();

    return a.exec();
}
