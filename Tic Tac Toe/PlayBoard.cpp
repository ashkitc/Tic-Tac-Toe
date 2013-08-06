#include "PlayBoard.h"
#include <iostream>

PlayBoard::PlayBoard(void)
{
	winner = ' '; //we haven't winner when init playboard
	gamefield[1][1].serRaiting(MAX_RAITING);
}

void PlayBoard::setWiner(char value)
{
	if(value == 'x' || value == 'X' ||
	   value == 'o' || value == 'O')
	{
		winner = value;
	}
}

PlayBoard::~PlayBoard(void)
{
}

void PlayBoard::displayToConsole()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int column = 0; column < 3; ++column)
		{
			std::cout << gamefield[row][column].getValue();
			if(column < 2)
			{
				std::cout<< '|';
			}
		}
		std::cout << std::endl;
		if(row < 2)
		{
			std::cout <<"------";
			std::cout << std::endl;
		}
	}
}

bool PlayBoard::isEmpty()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int column = 0; column < 3; ++column)
		{
			if(!gamefield[row][column].isEmpty())
			{
				return false;
			}
		}
	}
	return true;
}

bool PlayBoard::allCellsAreOccupied()
{
	for (int row = 0; row < 3; ++ row)
	{
		for (int column = 0; column < 3; ++column)
		{
			if( gamefield[row][column].isEmpty() ) 
			{
				return false;
			}
		}
	}
	return true;
}

bool PlayBoard::isEndOfGame()
{
	if(allCellsAreOccupied())
	{
		return true;
	}  else 
	{
		checkWinner();
		if (winner != ' ')
		{
			return true;
		}
	}
	return false;
}

void PlayBoard::checkWinner()
{

	//Checking rows
	for (int row = 0; row< 3; ++row)
	{
		if( gamefield[row][0].getValue() == gamefield[row][1].getValue() &&
			gamefield[row][0].getValue() ==  gamefield[row][2].getValue() )
		{
			setWiner(  gamefield[row][0].getValue() );
		}
	}

	//Checking columns
	for (int column = 0; column < 3; ++column)
	{
		if( gamefield[0][column].getValue() == gamefield[1][column].getValue() && 
			gamefield[0][column].getValue() == gamefield[2][column].getValue() )
		{
				setWiner( gamefield[0][column].getValue() );
		}
	}

	//Checking diagonals
	if ( gamefield[0][0].getValue() == gamefield[1][1].getValue() &&
		 gamefield[0][0].getValue() == gamefield[2][2].getValue())
	{
		setWiner( gamefield[0][0].getValue() );
	}

	if ( gamefield[0][2].getValue() == gamefield[1][1].getValue() && 
		 gamefield[0][2].getValue() == gamefield[2][0].getValue())
	{
		setWiner( gamefield[0][2].getValue() );
	}
}

bool PlayBoard::setValueOfColumnWithCoordinates( char newValue, int row, int column)
{
	if( gamefield[row][column].isEmpty() )
	{
		gamefield[row][column].setValue(newValue);
		return true;
	}
	return false;
}