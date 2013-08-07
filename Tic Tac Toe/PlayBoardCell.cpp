#include "PlayBoardCell.h"


PlayBoardCell::PlayBoardCell(void)
{
	value = ' '; // By default cell inits with space (cell is empty);
	rating = 0;
	
}



//Check if cell is empty
 bool PlayBoardCell::isEmpty()
{
	if (value != ' ')
	{
		return false;
	}
	return true;
}
 
//set value if cell is empty else returns false
 bool PlayBoardCell::setValue(char newValue)
 {
	 if( !isEmpty() )
	 {
		 return false;
	 }
	 value = newValue;
	 rating = DONT_CARE_RATING; //set rating for occupied cell
	 return true;
 }