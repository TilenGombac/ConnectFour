#include "mygraphicsview.h"

void delay(int MSecsWait)
{
	QTime dieTime = QTime::currentTime().addMSecs(MSecsWait);
	while(QTime::currentTime() < dieTime)
	{
		QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
	}
}

MyGraphicsView::MyGraphicsView(MyGraphicsScene *scene, QWidget *parent) :
    QGraphicsView(scene, parent)
{
    myScene = scene;
    turnNumber = 0;
    qsrand(time(NULL));
    // Get rating
    std::fstream file;
    file.open("rating.bin", std::ios::in | std::ios::binary);
    if(file.is_open()) {
        file.read((char*)&moj_rating, sizeof(int));
        file.close();
    } else {
		moj_rating = 1200; // Base - Depth 4
        file.open("rating.bin", std::ios::out | std::ios::binary);
        if(file.is_open()) {
            file.write((char*)&moj_rating, sizeof(int));
            file.close();
        }
    }
}

void MyGraphicsView::onLeftPress()
{
    QPointF koordinate;
    koordinate = item->pos();
    if(koordinate.x() >= 80)
        item->moveBy(-80, 0);
}

void MyGraphicsView::onRightPress()
{
    QPointF koordinate;
    koordinate = item->pos();
    if(koordinate.x() <= 400)
    item->moveBy(80, 0);
}

void MyGraphicsView::setCoins(Coin *array[7][6])
{
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 7; j++) {
            arrayOfCoins[j][i] = array[j][i];
        }
}

void MyGraphicsView::setItem(QGraphicsPixmapItem* _item)
{
    item = _item;
}

void MyGraphicsView::setTurn(bool* _turn, bool* _playerTurn)
{
    turn = _turn;
    playerTurn = _playerTurn;
}

void MyGraphicsView::setPixmaps(QPixmap first, QPixmap second)
{
    yellow = first;
    red = second;
}

int MyGraphicsView::getRating()
{
	return moj_rating;
}

void MyGraphicsView::moveDown()
{
	int x = item->pos().toPoint().x() / 80;
	bool reachedTheTop = false;
	for(int y = 5; y >= 0; y--) {
		if(!arrayOfCoins[x][y]->isVisible()) { // Ob prvem praznem polju
			arrayOfCoins[x][y]->setSide(*turn); // Nastavimo zeton na vrednost trenutnega igralca
			if(*turn) arrayOfCoins[x][y]->setPixmap(red); // Ce je na vrsti igralec 1 (true) nastavimo rdec pixmap
			else arrayOfCoins[x][y]->setPixmap(yellow); // Drugace pa rumenega
			arrayOfCoins[x][y]->setVisible(true); // Polje nato pokazemo
			break; // Zanko se prekinemo
		}
		if(y == 0) reachedTheTop = true; // Ce je stolpec ze v celoti zapolnjen nastavimo sastavico na 1 da poteze ne zamenjamo
	}
	if(!reachedTheTop) { // Ce je stolpec zapolnjen (od prej) ne preverjamo za zmago in ne menjamo poteze
		turnNumber++; // Za preverjanje izenacene igre
		if(checkWin(*turn))
			zakljucenaIgra(*turn);
		else if(checkDraw())
			zakljucenaIgra(-1);
		else {
			// Ce se igra ni koncala zamenjamo igralca na potezi in nadaljujemo z igro
			*turn = *turn ^ 1;
			if(*turn) item->setPixmap(red); // Ce je na potezi rdec nastavimo zgornji zeton na rdecega
			else item->setPixmap(yellow); // Drugace pa na rumenega
		}
	}
	delay(50);
}

bool MyGraphicsView::validCoin(int x, int y, bool side)
{
    if(arrayOfCoins[x][y]->isVisible() && (arrayOfCoins[x][y]->getSide() == side))
        return true;
    return false;
}

void MyGraphicsView::clearBoard() {
    for(int x = 0; x <= 6; x++)
        for(int y = 0; y <= 5; y++)
            arrayOfCoins[x][y]->setVisible(false);
}

bool MyGraphicsView::checkWin(bool side)
{
    int counter;
    // Horizontal
    for(int y = 5; y >= 0; y--) {
        counter = 0;
        for(int x = 0; x <= 6; x++) {
            if(validCoin(x, y, side)) {
                if(counter == 0) {
                    point_1.setX(x);
                    point_1.setY(y);
                }
                counter++;
                if(counter == 4) {
                    point_2.setX(x);
                    point_2.setY(y);
                    return true;
                }
            } else
                counter = 0;
        }
    }

    // Vertical
    for(int x = 0; x <= 6; x++) {
        counter = 0;
        for(int y = 5; y >= 0; y--) {
            if(validCoin(x, y, side)) {
                if(counter == 0) {
                    point_1.setX(x);
                    point_1.setY(y);
                }
                counter++;
                if(counter == 4) {
                    point_2.setX(x);
                    point_2.setY(y);
                    return true;
                }
            } else
                counter = 0;
        }
    }
    // Diagonali

    // Desno zgoraj -> Levo spodaj
    for(int y = 0; y <= 2; y++)
        for(int x = 3; x <= 6; x++) {
            counter = 0;
            for(int i = 0; i <= 3; i++) {
                if(validCoin((x - i), (y + i), side)) {
                    if(counter == 0) {
                        point_1.setX(x - i);
                        point_1.setY(y + i);
                    }
                    counter++;
                    if(counter == 4) {
                        point_2.setX(x - i);
                        point_2.setY(y + i);
                        return true;
                    }
                } else
                    counter = 0;
            }
        }

    // Levo zgoraj -> Desno spodaj
    for(int y = 0; y <= 2; y++)
        for(int x = 0; x <= 3; x++) {
            counter = 0;
            for(int i = 0; i <= 3; i++) {
                if(validCoin((x + i), (y + i), side)) {
                    if(counter == 0) {
                        point_1.setX(x + i);
                        point_1.setY(y + i);
                    }
                    counter++;
                    if(counter == 4) {
                        point_2.setX(x + i);
                        point_2.setY(y + i);
                        return true;
                    }
                } else
                    counter = 0;
            }
        }
    return false;
}

bool MyGraphicsView::checkDraw()
{
    if(turnNumber == 42)
        return true;
    else
        return false;
}

void MyGraphicsView::zakljucenaIgra(int zmagovalec)
{
    QPen pen;
    QColor color(255, 132, 240);
    pen.setColor(color);
    pen.setWidth(5);

    QPoint pointOne, pointTwo;
    pointOne.setX(point_1.x() * 80 + 40);
    pointOne.setY((point_1.y() + 1) * 80 + 40);

    pointTwo.setX(point_2.x() * 80 + 40);
    pointTwo.setY((point_2.y() + 1) * 80 + 40);

    QGraphicsLineItem *myLine = myScene->addLine(pointOne.x(), pointOne.y(), pointTwo.x(), pointTwo.y(), pen);


    QMessageBox box;
	QString rating_string = "RATING:\nVaš novi rating: ";
    if(zmagovalec != *playerTurn) {
		moj_rating -= 200;
		box.setWindowTitle("Zmagal je računalnik!");
		box.setText(rating_string + QString::number(moj_rating) + " (-200)\nRačunalnik je bil tokrat boljši. Želite poskusiti znova?");
    } else if(zmagovalec == *playerTurn) {
		moj_rating += 200;
        box.setWindowTitle("Zmagali ste");
		box.setText(rating_string + QString::number(moj_rating) + " (+200)\nTokrat vam je uspelo premagati računalnik. Želite poskusiti znova?");
    } else {
		QString change;
		if(moj_rating > (moj_rating / 300) * 300) {
			moj_rating -= 100;
			change = " (-100)\n";
		}
		else {
			moj_rating += 100;
			change = " (+100)\n";
		}
        box.setWindowTitle("Igra je bila izenačena");
		box.setText(rating_string + QString::number(moj_rating) + change + "Računalnik in vi ste bili na enakem nivoju. Želite poskusiti znova?");
    }
    std::fstream file;
    file.open("rating.bin", std::ios::out | std::ios::binary);
    if(file.is_open()) {
		file.write((char*)&moj_rating, sizeof(int));
        file.close();
    } else {
		QMessageBox boks;
		boks.setText("Prislo je do napake pri odpiranju rating datotetek. Aplikacija se bo zaradi kriticne napake zaprla.");
		if(boks.exec() == QMessageBox::Ok)
			QCoreApplication::exit();
    }
    QAbstractButton* pPoskusiZnova = box.addButton("Poskusi znova", QMessageBox::YesRole);
    box.addButton("Ne želim več igrati", QMessageBox::NoRole);
    box.exec();
    if(box.clickedButton() == pPoskusiZnova) { // Weird behavior?
		item->setPos(240, 0);
        turnNumber = 0;
        myScene->removeItem(myLine);
        clearBoard();
		delay(50);
		*turn = *turn ^ 1;
		if(*turn) item->setPixmap(red); // Ce je na potezi rdec nastavimo zgornji zeton na rdecega
		else item->setPixmap(yellow); // Drugace pa na rumenega
		QMessageBox boxy;
		if(*turn != *playerTurn) {
			computerMakesMove(moj_rating);
			boxy.setText("Računalnik ima prvo potezo");
			boxy.exec();
			delay(50);
		} else {
			*turn = *turn ^ 1;
			boxy.setText("Vi imate prvo potezo");
			boxy.exec();
		}


    } else {
        QCoreApplication::exit();
    }
}

void MyGraphicsView::computerMakesMove(int rating)
{
	turnNumber++; // za preverjanje izenacene igre
	Poteza move;
	QPoint droppedTo;
	//poteze.clear();
	move = minimaximum(*turn, (rating / 300));
	droppedTo = dropCoin(move.x, *turn);
	if(droppedTo.y() == -1) {
		int tmpY;
		for(int x = 0; x <= 6; x++) {
			tmpY = dropCoin(x, *turn).y();
			if(tmpY != -1) {
				droppedTo.setY(tmpY);
				break;
			}
		}
	}
	//if(*turn) arrayOfCoins[move.x][droppedTo.y()]->setPixmap(red);
	//else arrayOfCoins[move.x][droppedTo.y()]->setPixmap(yellow);

	if(checkWin(*turn))
		zakljucenaIgra(*turn);
	else if(checkDraw())
		zakljucenaIgra(-1);
	*turn = *turn ^ 1;
	if(*turn) item->setPixmap(red); // Ce je na potezi rdec nastavimo zgornji zeton na rdecega
	else item->setPixmap(yellow); // Drugace pa na rumenega
	delay(50);
}


QPoint MyGraphicsView::dropCoin(int x, bool side)
{
	if(x >= 0 && x <= 6)
		for(int y = 5; y >= -1; y--) {
			if(y >= 0) {
				if(!arrayOfCoins[x][y]->isVisible()) {
					arrayOfCoins[x][y]->setVisible(true);
					arrayOfCoins[x][y]->setSide(side);
					if(side) arrayOfCoins[x][y]->setPixmap(red); // Ce je na potezi rdec nastavimo zgornji zeton na rdecega
					else arrayOfCoins[x][y]->setPixmap(yellow); // Drugace pa na rumenega
					return QPoint(x, y);
				}
			}
		}
    return QPoint(x, -1);
}

void MyGraphicsView::hideCoin(int x, int y)
{
    arrayOfCoins[x][y]->setVisible(false);
}

int MyGraphicsView::evaluateBoardValue(bool side)
{
    /*
     * Vrednosti
	 * 1 in a row / draw: +1/-1
     * 2 in a row:        +2/-2
     * 3 in a row:        +3/-3
     * 4 in a row (win):  +4/-4
     */
    int counter = 0, max_counter = 0;

    // Ni vec prazni polj - DRAW
    for(int x = 0; x <= 6; x++)
        for(int y = 5; y >= 0; y--)
            if(arrayOfCoins[x][y]->isVisible())
                counter++;
    if(counter == 42)
        return qrand() % 3 - 1;


    // Horizontal
    for(int y = 5; y >= 0; y--) {
		counter = 0;
        for(int x = 0; x <= 6; x++) {
            if(validCoin(x, y, side)) {
                counter++;
                if(counter > max_counter)
                    max_counter = counter;
                if(counter == 4)
                    return 4;
            } else
                counter = 0;
        }
    }

    // Vertical
    for(int x = 0; x <= 6; x++) {
        counter = 0;
        for(int y = 5; y >= 0; y--) {
            if(validCoin(x, y, side)) {
                counter++;
                if(counter > max_counter)
                    max_counter = counter;
                if(counter == 4)
                    return 4;
            } else
                counter = 0;
        }
    }

    // Diagonali

    // Desno zgoraj -> Levo spodaj
    for(int y = 0; y <= 2; y++)
        for(int x = 3; x <= 6; x++) {
            counter = 0;
            for(int i = 0; i <= 3; i++) {
                if(validCoin((x - i), (y + i), side)) {
                    counter++;
                    if(counter > max_counter)
                        max_counter = counter;
                    if(counter == 4)
                        return 4;
                } else
                    counter = 0;
            }
        }

    // Levo zgoraj -> Desno spodaj
    for(int y = 0; y <= 2; y++)
        for(int x = 0; x <= 3; x++) {
            counter = 0;
            for(int i = 0; i <= 3; i++) {
                if(validCoin((x + i), (y + i), side)) {
                    counter++;
                    if(counter > max_counter)
                        max_counter = counter;
                    if(counter == 4)
                        return 4;
                } else
                    counter = 0;
            }
        }
		return max_counter;
}

Poteza MyGraphicsView::minimaximum(bool miniOrMax, int depth) // Improve
{
	if(depth <= 0 || checkDraw()) {
        int tmpValue = evaluateBoardValue(miniOrMax);
        if(miniOrMax == *playerTurn)
			return Poteza(-tmpValue); // Minimizing
        else
			return Poteza(tmpValue); // Maximizing
    }
	else if(checkWin(*playerTurn)) // Minimizing
		return Poteza(-4);
	else if(checkWin(!(*playerTurn))) // Maximizing
		return Poteza(4);

    Poteza bestMove;
    QPoint droppedTo;
    if(miniOrMax != *playerTurn) { // Maximizing
        bestMove.vrednost = -4; // Najslabsa mozna vrednost za maximizing
		for(int x = 0; x <= 6; x++) {
            droppedTo = dropCoin(x, miniOrMax);
            if(droppedTo.y() != -1) { // Vrstica pri x se ni bila zapolnjena
				if(PC_VISUAL == true) {
					if(item->pos().x() != (x * 80)) {
						item->setPos(x * 80, 0);
						delay(1); // za prikaz premika
					}
				}
				Poteza nova;
				nova.vrednost = minimaximum(!miniOrMax, (depth - 1)).vrednost;
				hideCoin(x, droppedTo.y());
				if(bestMove.vrednost < nova.vrednost) {
					bestMove.vrednost = nova.vrednost;
					bestMove.x = x;
				} else if(bestMove.vrednost == nova.vrednost) {
					if(qrand() % 2 == 1) { // "random" odlocanje
						bestMove.vrednost = nova.vrednost;
						bestMove.x = x;
					}
				}
            }
        }
    } else { // Minimizing
        bestMove.vrednost = 4; // Najslabsa mozna vrednost za minimizing
		for(int x = 0; x <= 6; x++) {
            droppedTo = dropCoin(x, miniOrMax);
            if(droppedTo.y() != -1) { // Vrstica pri x se ni bila zapolnjena
				if(PC_VISUAL == true) {
					if(item->pos().x() != (x * 80)) {
						item->setPos(x * 80, 0);
						delay(1); // za prikaz premika
					}
				}
				Poteza nova;
				nova.vrednost = minimaximum(!miniOrMax, (depth - 1)).vrednost;
				hideCoin(x, droppedTo.y());
				if(bestMove.vrednost > nova.vrednost) {
					bestMove.vrednost = nova.vrednost;
					bestMove.x = x;
				} else if(bestMove.vrednost == nova.vrednost) {
					if(qrand() % 2 == 1) { // "random" odlocanje
						bestMove.vrednost = nova.vrednost;
						bestMove.x = x;
					}
				}
			}
        }
    }
    return bestMove;
}

void MyGraphicsView::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left)
        onLeftPress();
    else if(event->key() == Qt::Key_Right)
        onRightPress();
    else if(event->key() == Qt::Key_Space || event->key() == Qt::Key_Down) {
		if(*turn == *playerTurn)
			moveDown(); // Igralec postavi zeton
		if(*turn != *playerTurn) // Racunalnik postavi zeton
			computerMakesMove(moj_rating);
    }
}
