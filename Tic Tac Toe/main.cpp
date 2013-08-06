#include <iostream>
#include <conio.h>
#include "GameBrain.h"
using namespace std;
int main (int argc, char **argv)
{
	GameBrain game;
	game.startPlaying();
	_getch();
	return 0;
}
