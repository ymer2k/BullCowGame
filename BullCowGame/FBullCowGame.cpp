#pragma once

#include "FBullCowGame.h"
#include <map>
#define TMap std::map // to make syntax unreal friendly

FBullCowGame::FBullCowGame() // Default constructor
{
	Reset();
}

void FBullCowGame::Reset()
{
	const FString HIDDEN_WORD = "planet"; // this MUST be an isogram
	MyHiddenWord = HIDDEN_WORD;
	MyCurrentTry = 1;
	bGameIsWon = false;
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap<int32, int32> WordLengthToMaxTries{ {3,4}, {4,6}, {5,10}, {6,16} , {7,26} };
	return WordLengthToMaxTries[MyHiddenWord.length()]; // we input the length of the word (inputing the first element in the pair above) and returning the second element in the pair. 
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{

	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return bGameIsWon;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if(!IsIsogram(Guess))
	{
		return EGuessStatus::Not_Isogram;
	}

	else if (!IsLowercase(Guess))
	{
		return EGuessStatus::Not_Lowercase;
	}

	else if (Guess.length() != GetHiddenWordLength()) // if the guess length is wrong, return an error
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount; // create an instance of BullCowCount struct
	int32 MyGuessLength = Guess.length();
	int32 HiddenWordLength = MyHiddenWord.length();
	// loop through all letter in the hidden word
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against the guess
		for (int32 j = 0; j < MyGuessLength; j++)
		{
			// if they match then
			if (MyHiddenWord[i] == Guess[j])
			{
				// if thet're in the same place
				if (i == j)
				{
					BullCowCount.Bulls++; 	// increment bulls
				}
				else { BullCowCount.Cows++; } // increment cows if not

			}
		}
	}

	if (BullCowCount.Bulls == GetHiddenWordLength())
	{
		bGameIsWon = true;
	}
	else
		bGameIsWon = false;

	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Guess) const
{

	// treat 0 and 1 letter words as isograms
	if (Guess.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Guess)
	{
		Letter = tolower(Letter); //  handle mixed case (lower case capital letters)
		if (LetterSeen[Letter]) //Default empty values in LetterSeen are initilised to false
			return false;
		LetterSeen[Letter] = true;
	}

	return true;
}

bool FBullCowGame::IsLowercase(FString Guess) const
{
	for (auto Letter : Guess)
	{
		if (!islower(Letter)) // if the guess isn't all lowercase, return an error
			return false;
	}

	return true;
}
