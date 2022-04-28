#include "Hangman.h"
#include "MyDic.h"
#include <cstdlib>
#include <string>

int main()
{
	srand((unsigned)time(NULL));
	Hangman game;
	MyDic hello;

	hello.load("example.txt");

	int random_num = rand() % 8;
	game.play(hello.getEng(random_num));


	cout << endl << "영어단어 :" << hello.getEng(random_num) << endl;
	cout << "한국어의미: " << hello.getKor(random_num) << endl;

	return 0;
}