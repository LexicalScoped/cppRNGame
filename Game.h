#ifndef _GAME_H_
#define _GAME_H_

class Game
{
private:
	static const int turns = 10;
	static const int maxRand = 1000;
	static const int minRand = 1;

	int randomNumber;
	int turnCounter;
	bool gameState;
	int guesses[turns];

public:
	Game();
	bool StatusCheck();
	void PrintMain();
	int GetAndValidateInput();
	void CheckGuess(int guess);
	void CheckTurns();
};
#endif
