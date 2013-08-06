#include "PlayBoardCell.h"


PlayBoardCell::PlayBoardCell(void)
{
	value = ' '; // By default cell inits with space (cell is empty);
	raiting = 0;
	
}


PlayBoardCell::~PlayBoardCell(void)
{
	raiting = 0;
}

 bool PlayBoardCell::isEmpty()
{
	if (value != ' ')
	{
		return false;
	}
	return true;
}

 bool PlayBoardCell::setValue(char newValue)
 {
	 if( !isEmpty() )
	 {
		 return false;
	 }
	 value = newValue;
	 return true;
 }