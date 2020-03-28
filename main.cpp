#include <stdlib.h> // srand() and rand()
#include <time.h>	// time()
#include "Game.h"	// Game Class

int main()
{
	srand((int)time(NULL));

	Game Obj;
	while (Obj.StatusCheck())
	{
		Obj.PrintMain();
		Obj.CheckGuess(Obj.GetAndValidateInput());
		Obj.CheckTurns();
	}
	if (!Obj.StatusCheck()) { Obj.~Game(); }

	return 0;
}