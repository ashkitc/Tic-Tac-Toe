#pragma once
#define CAN_WIN_RAITING 4
#define CAN_LOSE_RAITING 3
#define CENTER_RAITING 2
#define CORNER_RAITING 1
#define DONT_CARE_RAITING 0
class PlayBoardCell
{

public:
  	
	PlayBoardCell(void);
	~PlayBoardCell(void);
    bool isEmpty(); 

	//Accessor methods
	char getValue() { return value; };
	int getRaiting() { return raiting; };
	void setRaiting(int newRaiting) { raiting = newRaiting; };
	bool setValue(char newValue);
	void setCoordinates(int row, int column) { rowNumber = row; columnNumber = column; }
	int row(){ return rowNumber;}
	int column() {return columnNumber;}

private:
	char value; //Can be x or o
	int raiting;
	int rowNumber;
	int columnNumber;
};

