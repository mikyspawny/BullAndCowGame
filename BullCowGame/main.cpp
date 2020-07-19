/* This is the console executable, that makes use of the BullCowClass
This acts as the view in a MVC pattern and is responsible for all user interaction.
For game logic, see the FBullCowGame class.
*/


#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
void PrintGameSummary();



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

	std::cout << "Welcome to Bulls and Cows, a fun word game!" << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of? " << std::endl;
	std::cout << std::endl;
	return;
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	// loop for the number of turns asking for guesses
	// TODO change from FOR to WHILE loop once we have validateing tries
	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText Guess = GetGuess(); // TODO make loop to check valid guesses

		// submit valid guess to the game, and receive counts
		FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
		// print number of bulls and cows
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl << std::endl;
	}
	PrintGameSummary();
}


//Ask for guess input
FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();
	FText Guess = "";
	std::cout << "Try " << CurrentTry << ". Write your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

//Ask to play again
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again?(y/n) "; 
	FText Response = "";
	std::getline(std::cin, Response);
	std::cout << std::endl << std::endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}



// game summary
void PrintGameSummary()
{
	if (BCGame.IsGameWon())
		std::cout << "Congratulations! YOU WON - Well Done." << std::endl;
	else
		std::cout << "Better Luck Next Time !" << std::endl;
	return;
}