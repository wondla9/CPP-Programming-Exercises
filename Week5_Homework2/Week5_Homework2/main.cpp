#include "MineSweeper.h"
int main()
{
	int total;
	int size_x;
	int size_y;
	printf(" <Mine Sweeper>\n");
	printf("���� ũ�� �Է� : ");
	scanf_s("%d", &size_x);
	printf("���� ũ�� �Է� : ");
	scanf_s("%d", &size_y);
	printf("�ż��� �� ������ ���� �Է� : ");
	scanf_s("%d", &total);
	playMineSweeper(total, size_x, size_y);
}