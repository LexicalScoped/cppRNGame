#include "Game.h"

int main()
{
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
