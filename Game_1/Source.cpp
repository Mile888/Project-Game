#include<iostream>
#include<string>
#include<windows.h>

#include "Game.h"

using namespace std;



int main(int argc, char *argv[]) {

	Game g(30, 30);
	g.SetUp();

	while (!g.GameOver()) {
		Sleep(100);
		g.Draw();
		g.Input();
		g.Logic();
	};

	cout << "Game over" << endl;


	system("pause");
	return 0;
};