#include "PlayBoardLine.h"
#include <iostream>
#include <cstddef>

PlayBoardLine::PlayBoardLine()
{
	cellsPtrs = new PlayBoardCell*[3];
	for (int i = 0; i < 3; ++i)
	{
		cellsPtrs[i] = NULL;
	}
}
 
PlayBoardLine::~PlayBoardLine()
{
	delete cellsPtrs;
}
void PlayBoardLine::initWithLine(PlayBoardCell *linePtr)
{
	for (int i = 0; i < 3; ++i)
	{
		cellsPtrs[i] = &linePtr[i];
	}
}

int PlayBoardLine::countOfSigns(char sign)
{
	int count = 0;
	for (int i = 0; i < 3; ++i)
	{
		if(cellsPtrs[i]->getValue() == sign)
		{
			++count;
		}
	}
	return count;
}
bool PlayBoardLine::hasCellWithValue(char sign)
{
	for ( int i = 0; i < 3; ++ i)
	{
		if( cellsPtrs[i]->getValue() == sign)
		{
			return true;
		}
	}
	return false;
}

PlayBoardCell* PlayBoardLine::emptyCell()
{
	for ( int i = 0; i < 3; ++ i)
	{
		if( cellsPtrs[i]->isEmpty())
		{
			return cellsPtrs[i];
		}
	}
	return NULL;
}
void PlayBoardLine::setRatingForSign(char sign)
{
	if(countOfSigns(' ') == 1)
	{
		if(hasCellWithValue(sign))
		{
			if(countOfSigns(sign) == 2)
			{
				if(emptyCell() != NULL &&  emptyCell()->getRating() < CAN_WIN_RATING)
				{
					emptyCell()->setRating(CAN_WIN_RATING);
				}
			}
		}
		else 
		{
			if(countOfSigns(sign) == 0)
			{
				if(emptyCell() != NULL && emptyCell()->getRating() < CAN_LOSE_RATING)
				{
					emptyCell()->setRating(CAN_LOSE_RATING);
				}
			}
		}
	}
}

void PlayBoardLine::addCellPtr(PlayBoardCell *cellPtr)
{
	for(int i = 0; i < 3; ++i)
	{
		if (cellsPtrs[i] == NULL)
		{
			cellsPtrs[i] = cellPtr;
			break;
		}
	}
}

