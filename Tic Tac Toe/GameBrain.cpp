#include "GameBrain.h"
#include <iostream>
using namespace std;
GameBrain::GameBrain(void)
{
	usersSign = ' ';
}


GameBrain::~GameBrain(void)
{
}

void GameBrain::startPlaying()
{
	bool choseDone = false;
	cout << "Welcome to the Tic - Tac - Toe" << endl;
	choseSign();
	play();
}

void GameBrain::play()
{
	while (!playBoard.isEndOfGame())
	{
		if(usersSign == 'X' || usersSign == 'x')
		{
			userChoice();
			cpuChoice();
		} else 
		{
			cpuChoice();
			userChoice();
		}
	}
}

bool GameBrain::isCorrectCoordinates(int row, int column)
{
	if(row >= 3 || row < 0 || column >= 3 || column < 0)
	{ 
		return false;
	}
	return true;
}
void GameBrain::userChoice()
{
	int row = -1, column = -1;
	bool choiceDone = false;
	while (!choiceDone)
	{
		while ( !isCorrectCoordinates(row,column) )
		{
			cout << "Enter a coordinates of cell for choice" << endl;
			cin >> row >> column;
		}
		choiceDone = playBoard.setValueOfColumnWithCoordinates(usersSign, row, column);
		row = -1;
		column = -1;
	}
	 cout << "Game field: " << endl;
	 playBoard.displayToConsole();
}



void GameBrain::cpuChoice()
{

}

void GameBrain::choseSign()
{
	while ( !isCorrectSign (usersSign) )
	{
	   cout << "For begin playing chose your sign (type X or O)" << endl;
	   cin >> usersSign;
	}
}

bool GameBrain::isCorrectSign(char sign)
{
	if (sign == 'X' || sign == 'x' || sign == 'O' || sign == 'o')
	{
		return true;
	}
	return false;
}