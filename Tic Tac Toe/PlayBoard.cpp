#include "PlayBoard.h"
#include <iostream>

PlayBoard::PlayBoard(void)
{
	winner = ' '; //we haven't winner when init playboard
//	gamefield[1][1].serRaiting(MAX_RAITING);
	int current = 0;
	for (int row = 0; row < 3; ++ row)
	{
		for (int column = 0; column < 3; ++ column)
		{
			gamefield[current].setCoordinates(row,column);
			++current;
		}
	}
	centerCell().setRaiting(CENTER_RAITING);
	setCorrnersRaiting();
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

PlayBoardCell& PlayBoard::cellWithCoordinates(int row, int column)
{

	for(int i = 0; i <9; ++i)
	{
		if(gamefield[i].row() == row && gamefield[i].column() == column)
		{
			return gamefield[i];
		}
	}
	//return;
}

void PlayBoard::displayToConsole()
{
	for (int row = 0; row < 3; ++row)
	{
		for (int column = 0; column < 3; ++column)
		{
			std::cout << cellWithCoordinates(row,column).getValue();
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
			if(!cellWithCoordinates(row,column).isEmpty())
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
			if( cellWithCoordinates(row,column).isEmpty() ) 
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
		if( cellWithCoordinates(row,0).getValue() == cellWithCoordinates(row,1).getValue() &&
			cellWithCoordinates(row,0).getValue() == cellWithCoordinates(row,2).getValue() )
		{
			setWiner(  cellWithCoordinates(row,0).getValue() );
		}
	}

	//Checking columns
	for (int column = 0; column < 3; ++column)
	{
		if( cellWithCoordinates(0,column).getValue() == cellWithCoordinates(1,column).getValue() && 
			cellWithCoordinates(0,column).getValue() ==cellWithCoordinates(2,column).getValue() )
		{
				setWiner( cellWithCoordinates(0,column).getValue());
		}
	}

	//Checking diagonals
	if ( cellWithCoordinates(0,0).getValue() == cellWithCoordinates(1,1).getValue() &&
		 cellWithCoordinates(0,0).getValue() == cellWithCoordinates(2,2).getValue())
	{
		setWiner(cellWithCoordinates(0,0).getValue() );
	}

	if ( cellWithCoordinates(0,2).getValue() == cellWithCoordinates(1,1).getValue() &&
		 cellWithCoordinates(0,2).getValue() == cellWithCoordinates(2,0).getValue())
	{
		setWiner(cellWithCoordinates(0,2).getValue() );
	}
}

bool PlayBoard::setValueOfCellWithCoordinates( char newValue, int row, int column)
{
	if( cellWithCoordinates(row,column).isEmpty() )
	{
		cellWithCoordinates(row,column).setValue(newValue);
		return true;
	}
	return false;
}

void PlayBoard::setCorrnersRaiting()
{
	cellWithCoordinates(0,0).setRaiting(CORNER_RAITING);
	cellWithCoordinates(2,2).setRaiting(CORNER_RAITING);
	cellWithCoordinates(0,2).setRaiting(CORNER_RAITING);
	cellWithCoordinates(2,0).setRaiting(CORNER_RAITING);
}

void PlayBoard::resetRaiting(char sign)
{
	centerCell().setRaiting(CENTER_RAITING);
	setCorrnersRaiting();
	resetRaitingOnRows(sign);
	resetRaitingOnColumns(sign);
	for(int i = 0; i < 9; ++i)
	{
		if (!gamefield[i].isEmpty())
		{
			gamefield[i].setRaiting(DONT_CARE_RAITING);
		}
	}
}

void PlayBoard::resetRaitingOnRows(char sign)
{
	/*
	Looking for row where sign can win or lose and set priority 
			of this row's empty cells 
	*/
	for (int i = 0; i < 3; ++ i) 
	{
		int j = 0;
		if(cellWithCoordinates(i,j).getValue() == cellWithCoordinates(i,j+1).getValue()
									&& !cellWithCoordinates(i,j).isEmpty())
		{
			if( cellWithCoordinates(i,j+2).isEmpty() )
			{
				if(cellWithCoordinates(i,j).getValue() == sign)
				{
					cellWithCoordinates(i,j+2).setRaiting(CAN_WIN_RAITING);
				}
				else
				{
					cellWithCoordinates(i,j+2).setRaiting(CAN_LOSE_RAITING);
				}
			}
		}
		if(cellWithCoordinates(i,j).getValue() == cellWithCoordinates(i,j+2).getValue()
									&& !cellWithCoordinates(i,j).isEmpty())

		{
			if( cellWithCoordinates(i,j+1).isEmpty() )
			{
				if(cellWithCoordinates(i,j).getValue() == sign)
				{
					cellWithCoordinates(i,j+1).setRaiting(CAN_WIN_RAITING);
				}
				else
				{
					cellWithCoordinates(i,j+1).setRaiting(CAN_LOSE_RAITING);
				}
			}
		}
	}	
}

void PlayBoard::resetRaitingOnColumns(char sign)
{

	/*
	Looking for column where sign can win or lose and set priority 
			of this row's empty cells 
	*/
	for (int i = 0; i < 3; ++ i) 
	{
		int j = 0;
		if(cellWithCoordinates(j,i).getValue() == cellWithCoordinates(j+1,i).getValue()
									&& !cellWithCoordinates(j,i).isEmpty())
		{
			if( cellWithCoordinates(j+2,i).isEmpty() )
			{
				if(cellWithCoordinates(j,i).getValue() == sign)
				{
					cellWithCoordinates(j+2,i).setRaiting(CAN_WIN_RAITING);
				}
				else
				{
					cellWithCoordinates(j+2,i).setRaiting(CAN_LOSE_RAITING);
				}
			}
		}
		if(cellWithCoordinates(j,i).getValue() == cellWithCoordinates(j+2,i).getValue()
									&& !cellWithCoordinates(j,i).isEmpty())

		{
			if( cellWithCoordinates(j+1,i).isEmpty() )
			{
				if(cellWithCoordinates(j,i).getValue() == sign)
				{
					cellWithCoordinates(j+1,i).setRaiting(CAN_WIN_RAITING);
				}
				else
				{
					cellWithCoordinates(j+1,i).setRaiting(CAN_LOSE_RAITING);
				}
			}
		}
	}	
}

PlayBoardCell& PlayBoard::maxRaitedColumn(char sign)
{
	resetRaiting(sign);
	PlayBoardCell *maxRatedCell = new PlayBoardCell();
	for(int i = 0; i < 9; ++i)
	{
		if(gamefield[i].getRaiting() > maxRatedCell->getRaiting())
		{
			maxRatedCell = &gamefield[i];
		}
	}
	return *maxRatedCell;
}
