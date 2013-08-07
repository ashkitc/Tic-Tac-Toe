#pragma once
#include "PlayBoardCell.h"
class PlayBoardLine
{
	PlayBoardCell** cellsPtrs;

public:
	PlayBoardLine();
	~PlayBoardLine();
	void initWithLine(PlayBoardCell *linePtr);
	void addCellPtr(PlayBoardCell *ptr);
	int countOfSigns(char sign);
	void setRatingForSign(char sign);
	bool hasCellWithValue(char sign);
	PlayBoardCell* emptyCell();

	
};

