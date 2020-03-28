#include "Game.h"
#include <random>

int main()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(1, 100);

	Game Obj(dist(gen));
	while (Obj.StatusCheck())
	{
		Obj.PrintMain();
		Obj.CheckGuess(Obj.GetAndValidateInput());
		Obj.CheckTurns();
	}
	if (!Obj.StatusCheck()) { Obj.~Game(); }

	return 0;
}
