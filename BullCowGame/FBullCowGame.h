/* The game logic (no view code or direct user interaction)
* the game is a simple guess the word game based on mastermind
*/


#pragma once
#include <string>
#include <ctype.h> /* Islower() */


using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum class EGuessStatus 
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase

};


class FBullCowGame
{
public:
	FBullCowGame(); // Constructor
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	bool IsGameWon() const;
	EGuessStatus CheckGuessValidity(FString) const;

	void Reset(); 
	// counts bulls and cows, and increases try # assuming valid guess
	FBullCowCount SubmitValidGuess(FString);

private:
	// See constructor for initilisation
	int32 MyCurrentTry;
	FString MyHiddenWord;
	bool bGameIsWon;
	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
