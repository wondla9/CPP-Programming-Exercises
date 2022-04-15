#include "Ranking.h"
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <cstdio>
#include <time.h>
#define DIM 4		

#define RecOrder 1000
#define ShuffleAmt 100
static RecInput Record[RecOrder];
static ReplayCopy Replay[RecOrder];

enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };
static int DirKey[4] = { Left, Right, Up, Down };
static int map[DIM][DIM];
static int x, y;			
static int nMove;		
static clock_t tStart;	



void SaveRecord(const char* filename)
{
	FILE* fp = NULL;
	fopen_s(&fp, filename, "w");
	if (fp == NULL) return;
	for (int i = 0; i < RecOrder; i++)
	{
		fprintf(fp, " %4d   %5.5lo\n", Record[i].MoveDir, Record[i].TimePassed);
	}
	fclose(fp);
}

void addRecord(int Dir, long Time)
{
	int order = 0;
	for (int i = 0; i < RecOrder; i++)
	{
		if (Record[i].MoveDir == 0)
		{
			Record[i].MoveDir = Dir;
			Record[i].TimePassed = Time;
			break;
		}
	}
}




static void init()
{
	for (int i = 0; i < DIM * DIM - 1; i++)
		map[i / DIM][i % DIM] = i + 1;
	map[DIM - 1][DIM - 1] = 0;
	x = DIM - 1;
	y = DIM - 1;

	srand(time(NULL));		
	tStart = clock();	
	nMove = 0;			
}
static void display()
{
	system("cls");
	printf("\tFifteen Puzzle\n\t");
	printf("----------------\n\t");
	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			if (map[r][c] > 0)
				printf("%3d", map[r][c]);
			else printf("   ");
		}
		printf("\n\t");
	}
	printf("----------------\n\t");
	clock_t t1 = clock();
	long d = (long)(t1 - tStart) / CLOCKS_PER_SEC;
	printf("\n\t�̵� Ƚ��:%6d\n\t�ҿ� �ð�:%6.1lo\n\n", nMove, d);
}
static bool move(int dir)
{
	if (dir == Right && x > 0)
	{							
		map[y][x] = map[y][x - 1];
		map[y][--x] = 0;
	}
	else if (dir == Left && x < DIM - 1)
	{									
		map[y][x] = map[y][x + 1];
		map[y][++x] = 0;
	}
	else if (dir == Up && y < DIM - 1)
	{									
		map[y][x] = map[y + 1][x];
		map[++y][x] = 0;
	}
	else if (dir == Down && y > 0)
	{									
		map[y][x] = map[y - 1][x];
		map[--y][x] = 0;
	}
	else return false;


	clock_t t1 = clock();	
	long d = (long)(t1 - tStart) / CLOCKS_PER_SEC;
	addRecord(dir, d);
	SaveRecord("Record.txt");

	nMove++;
	return true;
}
static void shuffle(int nShuffle)
{
	for (int i = 0; i < nShuffle; i++)
	{
		int key = DirKey[rand() % 4];
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
	}
}
static bool isDone()
{
	for (int r = 0; r < DIM; r++)
	{
		for (int c = 0; c < DIM; c++)
		{
			if (map[r][c] != r * DIM + c + 1)
				return (r == DIM - 1) && (c == DIM - 1);
		}
	}
	return true;
}
static int getDirKey() { return _getche() == 224 ? _getche() : 0; }

void LoadRecord(const char* filename)
{
	FILE* fp = NULL;
	fopen_s(&fp, filename, "r");
	if (fp == NULL)
	{
		printf("\n ����� ���̺갡 �����ϴ�\n");
		_getche();
		return;
	}
	else
	{
		for (int i = 0; i < RecOrder; i++)
			fscanf_s(fp, "%d %lo", &Record[i].MoveDir, &Record[i].TimePassed);
		fclose(fp);
	}
	if (Record[1].MoveDir == 0)
	{
		printf("\n ����� ������ �����ϴ�\n\n ������ ���� �����մϴ�\n");
		_getche();
		shuffle(ShuffleAmt);			
		printf("\n ������ ���۵˴ϴ�...\n");
		_getche();

		nMove = 0;			
		tStart = clock();	

		return;
	}
	for (int i = 0; Record[i].MoveDir != 0; i++)
	{
		Replay[i].MoveDir = Record[i].MoveDir;
		Replay[i].TimePassed = Record[i].TimePassed;
		Record[i].MoveDir = 0;
	}
	printf("\n ���� ���¸� �ҷ��ɴϴ�\n");
	_getch();
	int count = 0;
	for (int i = 0; i < ShuffleAmt; i++)
	{
		int key = Replay[i].MoveDir;
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
		count++;
	}
	nMove = 0;
	printf("\n �÷��� ����� �ҷ��ɴϴ�\n");
	_getche();
	for (int i = ShuffleAmt; Replay[i].MoveDir != 0; i++)
	{
		int key = Replay[i].MoveDir;
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
		count++;
	}
	printf("\n ������ ���۵˴ϴ�\n");
	tStart = clock() - (Replay[count - 1].TimePassed * CLOCKS_PER_SEC);
	_getche();

}
void EndReplay()
{
	for (int i = 0; Record[i].MoveDir != 0; i++)
	{
		Replay[i].MoveDir = Record[i].MoveDir;
		Replay[i].TimePassed = Record[i].TimePassed;
	}
	init();
	display();

	for (int i = 0; i < ShuffleAmt; i++)
	{
		int key = Replay[i].MoveDir;
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(50);
	}
	nMove = 0;
	printf("\n ���÷��̸� �����մϴ�\n");
	_getche();
	for (int i = ShuffleAmt; Replay[i].MoveDir != 0; i++)
	{
		int key = Replay[i].MoveDir;
		if (move(key) == false) { i--; continue; }
		display();
		Sleep(250);
	}
}
int playFifteenPuzzle()
{
	init();
	display();
	printRanking();
	printf("\n ������ �����ּ���(L : ����� ���� �ҷ�����)\n");

	int key = _getch();

	if ((key == 76) || (key == 108))
		LoadRecord("Record.txt");
	else
	{
		shuffle(ShuffleAmt);		
		printf("\n ������ ���۵˴ϴ�\n");
		_getche();

		nMove = 0;			
		tStart = clock();	
	}
	while (!isDone())
	{					
		move(getDirKey());	
		display();			
	}
	clock_t t1 = clock();	
	long d = (long)(t1 - tStart) / CLOCKS_PER_SEC;

	printf("\n ���÷��̸� �غ��մϴ�\n");
	_getche();
	EndReplay();
	int r;
	r = remove("Record.txt");
	return addRanking(nMove, d);	
}