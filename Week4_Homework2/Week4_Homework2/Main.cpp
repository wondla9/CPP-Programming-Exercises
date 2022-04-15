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
	printf("\t3X3 51입력, 4X4 52입력, 5X5 53입력, 그 외:4X4를 실행합니다.\n");
	printf("\n\t플레이할 모드 선택: \n\t");

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