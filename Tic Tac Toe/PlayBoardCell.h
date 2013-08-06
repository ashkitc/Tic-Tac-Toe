#pragma once
#define MAX_RAITING 10
#define NORMAL_RAITING 5
#define LOW_RAITING 0
class PlayBoardCell
{

public:
  	
	PlayBoardCell(void);
	~PlayBoardCell(void);
    bool isEmpty(); 

	//Accessor methods
	char getValue() { return value; };
	int getRaiting() { return raiting; };
	void serRaiting(int newRaiting) { raiting = newRaiting; };
	bool setValue(char newValue);
  
private:
	char value; //Can be x or o
	int raiting;
	int rowNumber;
	int columnNumber;
};

