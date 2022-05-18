#pragma once
#include "Monster.h"

class Zombie : public Monster {
public:
	Zombie(string n = "허접좀비", string i = "§", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Zombie() { cout << " Zombie"; }
};

class Vampire : public Monster {
public:
	Vampire(string n = "뱀파이어", string i = "★", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Vampire() { cout << " Vampire"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--;
		else if (dir == 1) x++;
		else if (dir == 2) y--;
		else y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class KGhost : public Monster {
public:
	KGhost(string n = "처녀귀신", string i = "♥", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~KGhost() { cout << " KGhost"; }

	void move(int** map, int maxx, int maxy) {
		x = rand() % maxx;
		y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};

class Jiangshi : public Monster {
public:
	bool bHori;
	Jiangshi(string n = "대륙강시", string i = "↔", int x = 0, int y = 0, bool bH = true)
		: Monster(n, i, x, y), bHori(bH) {}
	~Jiangshi() { cout << " Jiangshi"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 2;
		int jump = rand() % 2 + 1;
		if (bHori) x += ((dir == 0) ? -jump : jump);
		else y += ((dir == 0) ? -jump : jump);
		clip(maxx, maxy);
		eat(map);
	}
};

class Lucky : public Monster {
public:
	Lucky(string n = "럭키클로에", string i = "↗", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Lucky() { cout << " Lucky"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 4;
		if (dir == 0) x--, y--;
		else if (dir == 1) x++, y++;
		else if (dir == 2) x++, y--;
		else x--, y++;
		clip(maxx, maxy);
		eat(map);
	}
};

class Sadako : public Jiangshi {
	int clk = 0;
public:
	Sadako(string n = "사다코", string i = "☎", int x = 0, int y = 0, bool bH = true)
		:Jiangshi(n, i, x, y, bH) {}
	~Sadako() { cout << " Sadako"; }

	void move(int** map, int maxx, int maxy) {
		Jiangshi::move(map, maxx, maxy);
		clk++;
		if (clk == 25) {
			bHori = !bHori;
			clk = 0;
		}
	}
};

class Fox : public Monster {
public:
	Fox(string n = "구미호", string i = "♨", int x = 0, int y = 0)
		: Monster(n, i, x, y) {}
	~Fox() { cout << " Fox"; }

	void move(int** map, int maxx, int maxy) {
		int dir = rand() % 6;
		if (dir == 0) x = rand() % maxx;
		else if (dir == 1) x++, y++;
		else if (dir == 2) x++, y--;
		else if (dir == 3) x--, y--;
		else if (dir == 4) x--, y++;
		else y = rand() % maxy;
		clip(maxx, maxy);
		eat(map);
	}
};