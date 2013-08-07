#pragma once

// Constants for cell's rating
const int CAN_WIN_RATING = 5;   //For cell where cpu can win in one step
const int CAN_LOSE_RATING = 4;  //For cell where cpu can lose in one step
const int CENTER_RATING = 3;    //For center
const int CORNER_RATING = 2;    //For corners
const int EMPTY_CELL_RATING = 1;//For empty cell
const int DONT_CARE_RATING = 0; //For occupied cell
class PlayBoardCell
{
public:
	PlayBoardCell(void);
    bool isEmpty(); 

	//Accessor methods
	char getValue() { return value; };
	int getRating() { return rating; };
	void setRating(int newrating) { rating = newrating; };
	bool setValue(char newValue);
	void setCoordinates(int row, int column) { rowNumber = row; columnNumber = column; }
	int row(){ return rowNumber;}
	int column() {return columnNumber;}
private:
	char value; //Can be x or o
	int rating; 
	int rowNumber;
	int columnNumber;
};

