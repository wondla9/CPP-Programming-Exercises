#include "MineSweeper.h"
int main()
{
	int total;
	int size_x;
	int size_y;
	printf(" <Mine Sweeper>\n");
	printf("가로 크기 입력 : ");
	scanf_s("%d", &size_x);
	printf("세로 크기 입력 : ");
	scanf_s("%d", &size_y);
	printf("매설할 총 지뢰의 개수 입력 : ");
	scanf_s("%d", &total);
	playMineSweeper(total, size_x, size_y);
}