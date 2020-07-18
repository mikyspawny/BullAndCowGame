#include <iostream>
#include <string>
using namespace std;


void PrintIntro();
void PlayGame();
string GetGuess();
bool AskToPlayAgain();


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
	constexpr int WORD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows, a fun word game!" << endl;
	cout << "Can you guess the " << WORD_LENGTH << " letter isogram I'm thinking of? " << endl;
	cout << endl;
	return;
}

void PlayGame()
{
	for (int count = 5; count >= 1; count--)
	{
		cout << "You have " << count << " more tries" << endl;
		string Guess = GetGuess();
		cout << "Your guess was: " << Guess << endl;
		cout << endl;
	}
}

//Ask for guess input
string GetGuess()
{

	string Guess = "";
	cout << "Write your guess: ";
	getline(cin, Guess);
	return Guess;
}

//Ask to play again
bool AskToPlayAgain()
{
	cout << "Do you want to play again?(y/n) "; 
	string Response = "";
	getline(cin, Response);
	cout << endl << endl;
	return (Response[0] == 'y' || Response[0] == 'Y');
}