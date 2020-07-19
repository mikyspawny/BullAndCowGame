#pragma once
#include <string>



class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	void Reset(); // TODO make a more rich return value.
	bool CheckGuessValidty(std::string); // TODO make a more rich return value

	// provide a method for counting bulls and cows, and increasing try number

// ^^ Please try and ignore this and focus on the interface above ^^
private:
	// see constructor for initialization
	int MyCurrentTry = 1;
	int MyMaxTries = 5;
};