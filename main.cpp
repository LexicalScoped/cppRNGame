#include <stdlib.h> 
#include <time.h>	
#include "Game.h"

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
