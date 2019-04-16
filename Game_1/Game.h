#ifndef GAME_H
#define GAME_H

#include<iostream>
#include<string>
#include<conio.h>

using namespace std;

enum Direction { STOP = 0,RIGHT,LEFT,UP,DOWN};


class Game {
private:
	int x,y;
	int Xmax,Ymax;
	int Xmonster,Ymonster;
	int score;
	Direction dir;
	bool gameOver;
	int arrayX[200];
	int arrayY[200];
	int arrayN=20;
	int bodyX, bodyY;
	int body2X, body2Y;

public:
	Game(int Xmax, int Ymax) {
		this->Xmax = Xmax;
		this->Ymax = Ymax;
	}
	
	void SetUp() {
		dir = STOP;
		x = Xmax / 2;
		y = Ymax / 2;
		Xmonster = rand() % Xmax;
		Ymonster = rand() % Ymax;
		score = 0;
	}

	bool GameOver() {
		gameOver = false;
		return gameOver;
	}

	void Draw() {
		system("cls");
		for (int i = 0; i < Xmax; i++)
			cout << "#";
		cout << endl;
		for (int i = 0; i < Ymax; i++) {
			for (int j = 0; j < Xmax; j++) {
				if (j == 0)
					cout << "#";
				
				if (i == y && j == x)
					cout << "O";
				else if (i == Ymonster && j == Xmonster)
					cout << "M";
				else
				{
					bool snake = false;
					for (int k = 0; k < arrayN; k++)
					{
					
						if (arrayX[k] == Xmonster && arrayY[k] == Ymonster)
						{
							cout << "0";
							snake = true;

						}

					}
					if (!snake)
						cout << " ";
				}
					

			    if (j== Xmax)
					cout << "#";
			}
			cout<<endl;
		}

		for (int i = 0; i < Xmax; i++)
			cout << "#";
		cout << endl;
		cout << "Score: "<<score << endl;
	}

	void Input() {
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
				dir = DOWN;
				break;
			case 'x':
				gameOver = true;
				break;
			}
		}
	}

	void Logic() {

		bodyX = arrayX[0];
		bodyY = arrayY[0];
		arrayX[0] = x;
		arrayY[0] = y;

		for (int i = 0; i < arrayN; i++) {
			body2X = arrayX[i];
			body2Y = arrayY[i];
			arrayX[i] = bodyX;
			arrayY[i] = bodyY;
			bodyX = body2X;
			bodyY = body2Y;
		}

		switch (dir) {
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		}

		if (x >= Xmax)
			x = 0;
		else if (x < 0)
			x = Xmax - 1;

		if (y>= Ymax)
			y = 0;
		else if (y < 0)
			y = Ymax - 1;

		if (x == Xmonster && y == Ymonster) {
			score = score + 1;
			Xmonster = rand() % Xmax;
			Ymonster = rand() % Ymax;
			arrayN++;
		}
	}




};






#endif
