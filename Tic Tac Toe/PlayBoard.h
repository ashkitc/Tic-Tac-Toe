#pragma once
#include "PlayBoardCell.h"
class PlayBoard
{
public:
	PlayBoard(void);
	void displayToConsole();
	bool isEndOfGame();
	bool setValueOfCellWithCoordinates(char newValue, int row, int column);
	PlayBoardCell& maxRaitedColumn(char sign);
	char getWinner() { return winner; }
private:
	PlayBoardCell gamefield[9];
	void setWiner(char value);
	void setCorrnersRating();
	bool allCellsAreOccupied();
	void calculateRating(char sign);
	PlayBoardCell& centerCell() {return cellWithCoordinates(1,1); }
	void resetRating(char sign);
	void resetRatingOnRows(char sign);
	void resetRatingOnColumns(char sign);
	bool isEmpty(); 
    void checkWinner();
	PlayBoardCell& cellWithCoordinates(int row, int column);
	char winner;
};

