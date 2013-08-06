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
	bool setValueOfCellWithCoordinates(char newValue, int row, int column);
	PlayBoardCell& cellWithCoordinates(int row, int column);
	PlayBoardCell& maxRaitedColumn(char sign);
	char getWinner() { return winner; }
	
private:
	PlayBoardCell gamefield[9];
	void setWiner(char value);
	void setCorrnersRaiting();
	bool allCellsAreOccupied();
	void calculateRaiting(char sign);
	PlayBoardCell& centerCell() {return cellWithCoordinates(1,1); }
	void resetRaiting(char sign);
	void resetRaitingOnRows(char sign);
	void resetRaitingOnColumns(char sign);
	char winner;
};

