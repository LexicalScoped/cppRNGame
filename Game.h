#ifndef _GAME_H_
#define _GAME_H_

class Game
{
private:
	// Configure these variables to adjust the guessing range and number of turns.
	static const int turns = 10;
	static const int maxRand = 100;
	static const int minRand = 1;


	// these variables will be used by the engine.
	int randomNumber;
	int turnCounter;
	bool gameState;
	int guesses[turns];

public:
	Game(int);
	bool StatusCheck();
	void PrintMain();
	int GetAndValidateInput();
	void CheckGuess(int guess);
	void CheckTurns();
};
#endif
