#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;
	MyCurrentTry = 1;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;

}

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
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
	return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{


	for (int32 i = 0 ; i < GetHiddenWordLength();i++)
	{

	}

	if (false) 	// if the guess isn't an isogram, return an error
	{
		return EGuessStatus::Not_Isogram;
	}


	else if(false) 	// if the guess isn't all lowercase, return an error
	{
		return EGuessStatus::Not_Lowercase;
	}
	else if (false) // if the guess length is wrong, return an error
	{
		return EGuessStatus::Wrong_Length;
	}
	else
	{
		return EGuessStatus::OK;
	}

	// otherwise return OK.





}

// receives a VALID guess, increments turn, and returns count
FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	// increment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount; // create an instance of BullCowCount struct
	int32 MyGuessLength = Guess.length();
	int32 HiddenWordLength = MyHiddenWord.length();
	// loop through all letter in the guess
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		// compare letters against the hidden word.
		for (int32 j = 0; j < MyGuessLength; j++)
		{
			// if they match then
			if (MyHiddenWord[i] == Guess[j])
			{
				// if thet're in the same place
				if (i == j)
				{
					// increment bulls
					BullCowCount.Bulls++;
				}
				else { BullCowCount.Cows++; }


				// else
				// increment cows if not
			}
		}
	}

	return BullCowCount;
}
