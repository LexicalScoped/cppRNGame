#include <iostream> 
#include <random>
#include "Game.h"	

Game::Game()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<int> dist(minRand, maxRand);
	randomNumber = dist(gen);
	turnCounter = turns;
	gameState = true;
	for (int i = turns - 1; i >= 0; i--)
	{
		guesses[i] = minRand - 1;
	}
}

bool Game::StatusCheck()
{
	return gameState;
}

void Game::PrintMain() 
{
	std::cout << "\n\nYou have " << turnCounter << " turns remaining." << std::endl;
	std::cout << "Previous Guesses: ";
	for (int i = turns - 1; i >= 0; i--)
	{
		if (guesses[i] != minRand - 1) { std::cout << guesses[i] << " "; }
		if (guesses[i] == minRand - 1) { break; }
	}
}

int Game::GetAndValidateInput()
{
	bool validInput = true;
	int validatedInput;
	do {
		validInput = true;
		std::cout << "\nGuess a number between " << minRand << " and " << maxRand << ": ";
		int guess;
		std::cin >> guess;
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cout << "Invalid Input" << std::endl;
			validInput = false;
			continue;
		}

		if (guess >= minRand && guess <= maxRand)
		{
			for (int i = turns - 1; i >= 0; i--)
			{
				if (guess == guesses[i])
				{
					std::cout << "You have already guessed this number " << std::endl;
					validInput = false;
					continue;
				}
				if (guesses[i] == minRand - 1) { break; }
			}
			if (!validInput) { continue; }
		}
		else
		{
			std::cout << "Number is outside of guessing range" << std::endl;
			validInput = false;
			continue;
		}

		if (validInput) { validatedInput = guess; }
	} while (!validInput);
	return validatedInput;
}

void Game::CheckGuess(int guess)
{
	guesses[--turnCounter] = guess;

	if (guess > randomNumber) { std::cout << "Your guess (" << guess << ") was higher than the random number" << std::endl; }
	if (guess < randomNumber) { std::cout << "Your guess (" << guess << ") was lower than the random number" << std::endl; }
	if (guess == randomNumber)
	{
		std::cout << "Congratulations! You guessed (" << guess << ") which matches the random number (" << randomNumber << ")" << std::endl;
		gameState = false;
	}
}

void Game::CheckTurns()
{
	if (turnCounter == 0)
	{
		std::cout << "Game Over: You have run out of turns" << std::endl;
		gameState = false;
	}
}
