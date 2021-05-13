/* This is the console executable, that makes use of the BUllCow class
* This acts as the view in a MVC pattern, and is resposible for all 
* user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// to make suntax unreal friendly
using Ftext = std::string;
using int32 = int;

// function prototypes as outside a class
void PrintIntro();
void PrintGameSummary();
Ftext GetValidGuess();
void PlayGame();
bool AskToPlayAgain();


FBullCowGame BCGame; //Instantiate a new game, which we re-use across plays.

// the entry point of our application
int main()
{
    do {
        PrintIntro();
        PlayGame();
        PrintGameSummary();
    }while (AskToPlayAgain());

    return 0;
}

void PrintIntro()
{
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "\\|/          (__)" << std::endl;
    std::cout << "     `\\------(oo)" << std::endl;
    std::cout << "        ||   (__)" << std::endl;
    std::cout << "        ||w--||     \\|/" << std::endl;
    std::cout << "\\|/" << std::endl;

    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

// plays a single game to completion.
void PlayGame()
{
    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << "Maximum number of tries: " << MaxTries << std::endl;

    // loop asking for guesses while the game is NOT won.
    // Is NOT won and there are still tries remaning.
    FBullCowCount BullCowCount;
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
    {
        Ftext Guess = GetValidGuess();

        // submit valid guess to the game, and receive counts
        BullCowCount =  BCGame.SubmitValidGuess(Guess);
        // print number of bulls and cows.
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
    }

}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again with the same hidde word (y/n)? ";
    Ftext Response = "";
    std::getline(std::cin, Response);
    //std::cout << "Is it y? ";
    if (((Response[0] == 'y') || (Response[0] == 'Y')))
    {
        return true;
    }
    else 
    { 
        return false;
    }
    std::cout << std::endl;
}

// loop continually until the user gives a valid guess.
Ftext GetValidGuess()
{   
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    do
    {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try: " << CurrentTry << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
        Ftext Guess = "";
        std::getline(std::cin, Guess);

        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status)
        {
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter an isogram." << std::endl;
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter only lowercase letters." << std::endl;
            break;
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
            break;
        default:
            return Guess;
        }
        std::cout << std::endl;
    } while (Status != EGuessStatus::OK); // Keep looping until we get no errors
}

void PrintGameSummary()
{
    if (BCGame.IsGameWon())
    {
        std::cout << "Correct! Congratulations!" << std::endl;
    }
    else
    {
        std::cout << "Game Over, Better luck next time!" << std::endl;
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
