#include "Ranking.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstdio>
#include <time.h>
#define DIM 4

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int Dirkey[4] = { Left, Right, Up, Down };
static int map[DIM][DIM];
static int x, y;
static int nMove;
static clock_t tStart;

static void init() {
	for (int i = 0; i < DIM * DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1; y = DIM - 1;

	srand((unsigned int)time(NULL));
	tStart = clock();
	nMove = 0;
}
static void display() {
	system("cls");
	printf("\tFifteen Puzzle\n\t");
	printf("--------------\n\t");
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] > 0)
				printf("%3d", map[r][c]);
			else printf("  ");
		}
		printf("\n\t");
	}
	printf("--------------\n\t");
	clock_t t1 = clock();
	long d = (long)(t1 - tStart) / CLOCKS_PER_SEC;
	printf("\n\t�̵� Ƚ��:%6d\n\t�ҿ� �ð�:%6.1lo\n\n", nMove, d);
}
static bool move(int dir) {
	if (dir == Right && x > 0) {
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1) {
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1) {
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0) {
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;

	nMove++;
	return true;
}
static void shuffle(int nShuffle) {
	for (int i = 0; i < nShuffle; i++) {
		int key = Dirkey[rand()%4];
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
	}
}
static bool isDone() {
	for (int r = 0; r < DIM; r++) {
		for (int c = 0; c < DIM; c++) {
			if (map[r][c] != r * DIM + c + 1)
				return (r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}
static int getDirKey() { return _getche() == 224 ? _getche() : 0; }
int playFifteenPuzzle() {
	init();
	display();
	printRanking();
	printf("\n ������ �����ּ���(����)...");
	_getche();
	shuffle(100);
	printf("\n ������ ���۵˴ϴ�...");
	_getche();

	nMove = 0;
	tStart = clock();
	while (!isDone()) {
		move(getDirKey());
		display();
	}
	clock_t t1 = clock();
	long d = (long)(t1 - tStart) / CLOCKS_PER_SEC;
	return addRanking(nMove, d);
}