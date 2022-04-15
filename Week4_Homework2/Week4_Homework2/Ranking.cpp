#define _CRT_SECURE_NO_WARNINGS
#include "Ranking.h"
#define NUM_MVP 10
static PlayInfo MVP[NUM_MVP];	
static int nMVP = NUM_MVP;		

static void initRanking(){
	PlayInfo noname = { "C++���ƿ�", 1000, 1000.0 };
	for (int i = 0; i < nMVP; i++)
		MVP[i] = noname;
}
void loadRanking(const char* filename) {
	FILE* fp = fopen(filename, "r");
	if (fp == NULL)
		initRanking();
	else {
		fread(&MVP[0], sizeof(PlayInfo), nMVP, fp);
		fclose(fp);
	}
}
void storeRanking(const char* filename){
	FILE* fp = NULL;
	fopen_s(&fp, filename, "w");
	if (fp == NULL) return;
	for (int i = 0; i < nMVP; i++)
		fprintf(fp, " %4d %-16s %-5.1f\n", MVP[i].nMove, MVP[i].name, MVP[i].tElapsed);
	fclose(fp);
}
void printRanking(){
	for (int i = 0; i < nMVP; i++)
		printf(" [%2d��] %4d %-16s %5.1f\n", i + 1, MVP[i].nMove,
			MVP[i].name, MVP[i].tElapsed);
}
int addRanking(int nMove, double tElap){
	if (nMove < MVP[nMVP - 1].nMove){
		int pos = nMVP - 1;
		for (; pos > 0; pos--){
			if (nMove >= MVP[pos - 1].nMove) break;
			MVP[pos] = MVP[pos - 1];
		}
		MVP[pos].nMove = nMove;
		MVP[pos].tElapsed = tElap;
		printf(" %d���Դϴ�. �̸��� �Է��ϼ���: ", pos + 1);
		scanf_s("%s", MVP[pos].name, 10);
		return pos + 1;
	}
	return 0;
}