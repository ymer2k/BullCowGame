// BullCowGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


/* This is the console executable, that makes use of the BUllCow class
* This acts as the view in a MVC pattern, and is resposible for all 
* user interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using Ftext = std::string;
using int32 = int;

void PrintIntro();
Ftext GetGuess();
void PlayGame();
bool AskToPlayAgain();

FBullCowGame BCGame; //Instantiate a new game

int main()
{
   

    do {
        PrintIntro();
        PlayGame();
    }while (AskToPlayAgain());

    return 0;
}

void PlayGame()
{
    BCGame.Reset();

    int32 MaxTries = BCGame.GetMaxTries();
    std::cout << "Maximum number of tries: " << MaxTries << std::endl;
    // loop for the number of turns askingn for guesses.
   // TODO change from FOR to WHILE loop once we have are validating tries.
    for (int32 i = 0; i < MaxTries; i++)
    {
        //std::cout << i + 1 << " guess." << std::endl;
        Ftext Guess = GetGuess(); // TODO make loop checking valid

        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);

        // submit valid guess to the game, and receive counts
        FBullCowCount BullCowCount =  BCGame.SubmitGuess(Guess);
        // print number of bulls and cows.
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
        std::cout << std::endl;
    }

    // TODO summarise gamesu
}

bool AskToPlayAgain()
{
    std::cout << "Do you want to play again? (y/n)";
    Ftext Response = "";
    std::getline(std::cin, Response);
    std::cout << "Is it y? ";
    if (((Response[0] == 'y') || (Response[0] == 'Y')))
    {
        std::cout << "true" << std::endl;
        return true;
    }
    else 
    { 
        std::cout << "false" << std::endl; 
        return false;
    }
    std::cout << std::endl;
        
    //std::cout << "Is it y? " << ((Response[0] == 'y') || (Response[0] == 'Y')) << std::endl;
}


Ftext GetGuess() // TODO change to get valid guess
{   
    int32 CurrentTry = BCGame.GetCurrentTry();
    std::cout << "Try: " << CurrentTry << ". " << "Enter your guess: ";
    Ftext Guess = "";
    std::getline(std::cin, Guess);
    return Guess;
}

//Introduce the game
void PrintIntro()
{
    std::cout << "Welcome to Bulls and Cows, a fun word game." << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
    std::cout << std::endl;
    return;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
