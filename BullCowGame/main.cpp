#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; // make an instance of a new game

// entry point for application
int main()
{
	bool bPlayAgain = false;
	do
	{
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	} while (bPlayAgain);
    return 0;
}





// introduce the game
void PrintIntro()
{
	constexpr int WORD_LENGTH = 9;
	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? " << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we have validateing tries
	for (int count = 1; count <= MaxTries; count++)
	{
		std::string Guess = GetGuess(); // TODO make loop to check valid guesses

		// submit valid guess to the game
		// print number of bulls and cows

		std::cout << "Your guess was: " << Guess << std::endl;
		std::cout << std::endl;
	}
}

//TODO summarise game

//Ask for guess input
std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();
	std::string Guess = "";
	std::cout << "Try " << CurrentTry << ". Write your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

//Ask to play again
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?(y/n) "; 
	std::string Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}