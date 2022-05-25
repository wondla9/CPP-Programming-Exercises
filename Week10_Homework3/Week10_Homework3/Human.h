#pragma once
#pragma warning(disable : 4996)
#include "Monster.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Human : public Monster {
public:
	Human(string n = "�̷��η�", string i = "��", int px = 0, int py = 0)
		: Monster(n, i, px, py) {}
	~Human() { cout << " [Human   ]"; }
	int getDirKey() { return getche() == 224 ? getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (kbhit()) {
			char ch = getDirKey();
			if (ch == Left) x--;
			else if (ch == Right) x++;
			else if (ch == Up) y--;
			else if (ch == Down) y++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Tuman : public Human {
public:
	Tuman(string n = "�̷��η�2", string i = "��", int px = 0, int py = 0)
		: Human(n, i, px, py) {}
	~Tuman() { cout << " [Tuman   ]"; }
	void move(int** map, int maxx, int maxy, char ch) {
		if (ch == Left || ch == 'a') x--;
		else if (ch == Right || ch == 'd') x++;
		else if (ch == Up || ch == 'w') y--;
		else if (ch == Down || ch == 's') y++;
		else return;
		clip(maxx, maxy);
		eat(map);
	}
};
