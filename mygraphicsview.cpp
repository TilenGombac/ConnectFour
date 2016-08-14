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
		file.read((char*)&my_rating, sizeof(int));
        file.close();
    } else {
		my_rating = 1200; // Base rating - Minimax Depth 4
        file.open("rating.bin", std::ios::out | std::ios::binary);
        if(file.is_open()) {
			file.write((char*)&my_rating, sizeof(int));
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
	return my_rating;
}

void MyGraphicsView::moveDown()
{
	int x = item->pos().toPoint().x() / 80;
	bool reachedTheTop = false;
	for(int y = 5; y >= 0; y--) {
		if(!arrayOfCoins[x][y]->isVisible()) { // First empty field in the column
			arrayOfCoins[x][y]->setSide(*turn); // Change the coin value to the current player's
			if(*turn) arrayOfCoins[x][y]->setPixmap(red); // Setting the coin color based on player value (1 or 0)
			else arrayOfCoins[x][y]->setPixmap(yellow);
			arrayOfCoins[x][y]->setVisible(true); // Setting the hidden field to visible
			break;
		}
		if(y == 0) reachedTheTop = true; // If the column has already been filled, we don't want to swap player turns
	}
	if(!reachedTheTop) { // Full column -> don't check win, don't swap turns
		turnNumber++; // Checking for draw -> max turns and no victory => draw
		if(checkWin(*turn))
			zakljucenaIgra(*turn);
		else if(checkDraw())
			zakljucenaIgra(-1);
		else {
			// If the game didn't end, swap player turns and continue
			*turn = *turn ^ 1;
			if(*turn) item->setPixmap(red); // Setting the coin color based on player value (1 or 0)
			else item->setPixmap(yellow);
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
	// Diagonal

	// Up right to down left
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

	// Up left to down right
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
	QString rating_string = "RATING:\nYour new rating: ";
    if(zmagovalec != *playerTurn) {
		my_rating -= 200;
		box.setWindowTitle("The computer was victorious!");
		box.setText(rating_string + QString::number(my_rating) + " (-200)\nThe computer was better this time. Wish to try again?");
    } else if(zmagovalec == *playerTurn) {
		my_rating += 200;
		box.setWindowTitle("You win");
		box.setText(rating_string + QString::number(my_rating) + " (+200)\nYou managed to beat the computer this time. Wish to try again?");
    } else {
		QString change;
		if(my_rating > (my_rating / 300) * 300) {
			my_rating -= 100;
			change = " (-100)\n";
		}
		else {
			my_rating += 100;
			change = " (+100)\n";
		}
		box.setWindowTitle("Draw!");
		box.setText(rating_string + QString::number(my_rating) + change + "The game resulted in a draw. Wish to try again?");
    }
    std::fstream file;
    file.open("rating.bin", std::ios::out | std::ios::binary);
    if(file.is_open()) {
		file.write((char*)&my_rating, sizeof(int));
        file.close();
    } else {
		QMessageBox boks;
		boks.setText("an error has occurred during a file opnening process. Due to this critical error the application will now quit.");
		if(boks.exec() == QMessageBox::Ok)
			QCoreApplication::exit();
    }
	QAbstractButton* pTryAgain = box.addButton("Try again", QMessageBox::YesRole);
	box.addButton("I don't wish to play again", QMessageBox::NoRole);
    box.exec();
	if(box.clickedButton() == pTryAgain) { // Weird behavior?
		item->setPos(240, 0);
        turnNumber = 0;
        myScene->removeItem(myLine);
        clearBoard();
		delay(50);
		*turn = *turn ^ 1;
		if(*turn) item->setPixmap(red); // Setting the coin color based on player value (1 or 0)
		else item->setPixmap(yellow);
		QMessageBox boxy;
		if(*turn != *playerTurn) {
			computerMakesMove(my_rating);
			boxy.setText("The computer goes first");
			boxy.exec();
			delay(50);
		} else {
			*turn = *turn ^ 1;
			boxy.setText("You go first");
			boxy.exec();
		}


    } else {
        QCoreApplication::exit();
    }
}

void MyGraphicsView::computerMakesMove(int rating)
{
	turnNumber++; // Checking draw
	Move move;
	QPoint droppedTo;
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
	if(*turn) item->setPixmap(red); // Setting the coin color based on player value (1 or 0)
	else item->setPixmap(yellow);
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
					if(side) arrayOfCoins[x][y]->setPixmap(red); // Setting the coin color based on player value (1 or 0)
					else arrayOfCoins[x][y]->setPixmap(yellow);
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
	 * Values
	 * 1 in a row / draw: +1/-1
     * 2 in a row:        +2/-2
     * 3 in a row:        +3/-3
     * 4 in a row (win):  +4/-4
     */
    int counter = 0, max_counter = 0;

	// No empty fields - DRAW
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

	// Diagonal

	// Up right to down left
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

	// Up left to down right
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

Move MyGraphicsView::minimaximum(bool miniOrMax, int depth)
{
	if(depth <= 0 || checkDraw()) {
        int tmpValue = evaluateBoardValue(miniOrMax);
        if(miniOrMax == *playerTurn)
			return Move(-tmpValue); // Minimizing
        else
			return Move(tmpValue); // Maximizing
    }
	else if(checkWin(*playerTurn)) // Minimizing
		return Move(-4);
	else if(checkWin(!(*playerTurn))) // Maximizing
		return Move(4);

	Move bestMove;
    QPoint droppedTo;
    if(miniOrMax != *playerTurn) { // Maximizing
		bestMove.value = -4; // Worst option for the maximizing
		for(int x = 0; x <= 6; x++) {
            droppedTo = dropCoin(x, miniOrMax);
			if(droppedTo.y() != -1) { // Column at the current x has not yet been filled
				if(PC_VISUAL == true) {
					if(item->pos().x() != (x * 80)) {
						item->setPos(x * 80, 0);
						delay(1); // Displaying the minimax visual
					}
				}
				Move MoveNew;
				MoveNew.value = minimaximum(!miniOrMax, (depth - 1)).value;
				hideCoin(x, droppedTo.y());
				if(bestMove.value < MoveNew.value) {
					bestMove.value = MoveNew.value;
					bestMove.x = x;
				} else if(bestMove.value == MoveNew.value) {
					if(qrand() % 2 == 1) { // "random" decision making
						bestMove.value = MoveNew.value;
						bestMove.x = x;
					}
				}
            }
        }
    } else { // Minimizing
		bestMove.value = 4; // Worst option for the minimizing
		for(int x = 0; x <= 6; x++) {
            droppedTo = dropCoin(x, miniOrMax);
			if(droppedTo.y() != -1) { // Column at the current x has not yet been filled
				if(PC_VISUAL == true) {
					if(item->pos().x() != (x * 80)) {
						item->setPos(x * 80, 0);
						delay(1); // Displaying the minimax visual
					}
				}
				Move MoveNew;
				MoveNew.value = minimaximum(!miniOrMax, (depth - 1)).value;
				hideCoin(x, droppedTo.y());
				if(bestMove.value > MoveNew.value) {
					bestMove.value = MoveNew.value;
					bestMove.x = x;
				} else if(bestMove.value == MoveNew.value) {
					if(qrand() % 2 == 1) { // "random" decision making
						bestMove.value = MoveNew.value;
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
			moveDown(); // Player drops coin
		if(*turn != *playerTurn) // Computer drops coin
			computerMakesMove(my_rating);
    }
}
