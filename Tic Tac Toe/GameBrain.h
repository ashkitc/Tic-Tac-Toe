#pragma once
#include "PlayBoard.h"
class GameBrain
{
public:
	GameBrain(void);
	~GameBrain(void);
	void startPlaying();
	void play();
	void choseSign();
	void userChoice();
	void cpuChoice();
//	void cpuMakeBestChoiceForX();
//	void cpuMakebestChoiceForO();
	bool isCorrectSign(char sign);
private:
	PlayBoard playBoard;
	bool isCorrectCoordinates(int row, int column);
	char usersSign;
};

