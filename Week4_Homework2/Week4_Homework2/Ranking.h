#include <cstdio>

struct PlayInfo{
	char   name[200];		
	int    nMove;
	double tElapsed;
};
struct RecInput{
	int    MoveDir;		
	long TimePassed;	
};
struct ReplayCopy{
	int    MoveDir;	
	long TimePassed;
};
extern void loadRanking(const char* filename);
extern void storeRanking(const char* filename);
extern void printRanking();
extern int addRanking(int nMove, double tElap);