#include "PlayBoard.h"
#include <iostream>
#include <algorithm>
#include "PlayBoardLine.h"
PlayBoard::PlayBoard(void)
{
	winner = ' '; //we haven't winner when init playboard
	int current = 0;
	for (int row = 0; row < 3; ++ row)
	{
		for (int column = 0; column < 3; ++ column)
		{
			gamefield[current].setCoordinates(row,column); //Set column's coordinates
			gamefield[current].setRating(EMPTY_CELL_RATING); //End raiting for empty cells
			++current;
		}
	}
	//when game begins center cell and corner cells are most important
	centerCell().setRating(CENTER_RATING); 
	setCorrnersRating(); 
}

void PlayBoard::setWiner(char value) //For checking who wins
{
	if(value == 'x' || value == 'X' ||
	   value == 'o' || value == 'O')
	{
		winner = value;
	}
}

PlayBoardCell& PlayBoard::cellWithCoordinates(int row, int column) 
{
	PlayBoardCell *chosen = NULL; //Temporary pointer to the cell
	for(int i = 0; i <9; ++i) 
	{
		if(gamefield[i].row() == row && gamefield[i].column() == column)
		{
			chosen = &gamefield[i]; 
		}
	}
	return *chosen;
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
	for (int row = 0; row < 3; ++row) // checking if all cells are empty
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
	for (int row = 0; row < 3; ++ row) // checking if all cells are occupied
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

bool PlayBoard::isEndOfGame() // cheking if the game ends
{
	if(allCellsAreOccupied()) //cheking if all cells are occupied
	{
		return true;
	}  else 
	{
		checkWinner(); //checking if somebody wins
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
	for (int i = 0; i < 9; i +=3)
	{
		PlayBoardLine line; //Playboard lines is a support class who can check winner in one line
	    line.initWithLine( (gamefield + i) ); //Init Playboard lines with current row
		if(line.hasWinner())
		{
			setWiner(gamefield[i].getValue());
		}
	}
	//Checking columns
    for (int i = 0; i < 3; ++i)
	{
		PlayBoardLine line;
		for (int j = 0; j < 3; ++j) 
		{
			line.addCellPtr( &cellWithCoordinates(j,i) ); //add to the line the next cell from current column
		}
		if(line.hasWinner()) 
		{
			setWiner(gamefield[i].getValue());
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

void PlayBoard::setCorrnersRating() // sets raiting for all corners
{
	cellWithCoordinates(0,0).setRating(CORNER_RATING);
	cellWithCoordinates(2,2).setRating(CORNER_RATING);
	cellWithCoordinates(0,2).setRating(CORNER_RATING);
	cellWithCoordinates(2,0).setRating(CORNER_RATING);
}

void PlayBoard::resetRating(char sign)
{
	resetRatingOnRows(sign); //fing critical rows (rows where cpu can win or lose by one step)
	resetRatingOnColumns(sign);//fing critical columns 
	for (int i = 0; i < 9; ++i) //reset raiting on occupied cells
	{
		if(!gamefield[i].isEmpty())
		{
			gamefield[i].setRating(DONT_CARE_RATING);
		}
	}
}

void PlayBoard::resetRatingOnRows(char sign)
{
	/*
	Looking for row where sign can win or lose and set priority 
			of this row's empty cells 
	*/
	for (int i = 0; i < 9; i +=3)
	{
		PlayBoardLine line;
	    line.initWithLine( (gamefield + i) );
		line.setRatingForSign(sign);
	}
}

void PlayBoard::resetRatingOnColumns(char sign)
{

	/*
	Looking for column where sign can win or lose and set priority 
			of this colums's empty cells 
	*/
	for (int i = 0; i < 3; ++i)
	{
		PlayBoardLine line;
		for (int j = 0; j < 3; ++j)
		{
			line.addCellPtr( &cellWithCoordinates(j,i) );
		}
		line.setRatingForSign(sign);
	}
}
PlayBoardCell& PlayBoard::maxRaitedCell(char sign)
{
	resetRating(sign); //recalculate rating for all cells
	PlayBoardCell *maxRatedCell = new PlayBoardCell();
	for(int i = 0; i < 9; ++i)
	{
		if(gamefield[i].getRating() > maxRatedCell->getRating())
		{
			maxRatedCell = &gamefield[i]; //search cell with max raiting
		}
	}
	return *maxRatedCell;
}
