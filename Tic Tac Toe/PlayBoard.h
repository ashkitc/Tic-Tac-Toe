#pragma once
#include "PlayBoardCell.h"
class PlayBoard
{
public:
	PlayBoard(void);
	void displayToConsole(); 
	bool isEndOfGame(); //Check if somebody wins or if all cells are occupied
	bool setValueOfCellWithCoordinates(char newValue, int row, int column); 
	PlayBoardCell& maxRaitedCell(char sign); //Search the best cell for next cpu step
	char getWinner() { return winner; }
private:
	PlayBoardCell gamefield[9]; //Stores all cells on the playboard
	void setWiner(char value);
	void setCorrnersRating(); //Sets rating to all corners
	bool allCellsAreOccupied(); //cheks if all cells are occupied
	PlayBoardCell& centerCell() {return cellWithCoordinates(1,1); } //returns center cell
	void resetRating(char sign); //recalculate rating for each cells
	void resetRatingOnRows(char sign); //recalculate rating for each cells (only on rows)
	void resetRatingOnColumns(char sign);// //recalculate rating for each cells (only on columns)
	bool isEmpty(); //Check if all cells are empty
    void checkWinner();//Check if somebody wins and sets winner
	PlayBoardCell& cellWithCoordinates(int row, int column); //returns cell with coordinates
	char winner; //stores who win (x or 0);
};

