#pragma once
#include "PlayBoardCell.h"
class PlayBoard
{
public:
	PlayBoard(void);
	~PlayBoard(void);
	void displayToConsole();
	bool isEmpty(); 
	bool isEndOfGame();
    void checkWinner();
	bool setValueOfColumnWithCoordinates(char newValue, int row, int column);
private:
	PlayBoardCell gamefield[3][3];
	void setWiner(char value);
	bool allCellsAreOccupied();
	char winner;
};

