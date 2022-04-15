#include "Ranking.h"
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

extern int playFifteenPuzzle();
extern int playFifteenPuzzle3();
extern int playFifteenPuzzle5();
int main()
{
	printf("\t3X3 51�Է�, 4X4 52�Է�, 5X5 53�Է�, �� ��:4X4�� �����մϴ�.\n");
	printf("\n\t�÷����� ��� ����: \n\t");

	int key = _getch();

	if (key == 51)
	{
		loadRanking("ranking3.txt");
		int rank = playFifteenPuzzle3();
		printRanking();
		storeRanking("ranking3.txt");
	}

	else if (key == 53)
	{
		loadRanking("ranking5.txt");
		int rank = playFifteenPuzzle5();
		printRanking();
		storeRanking("ranking5.txt");
	}
	else                             
	{
		loadRanking("ranking.txt");
		int rank = playFifteenPuzzle();
		printRanking();
		storeRanking("ranking.txt");
	}
}