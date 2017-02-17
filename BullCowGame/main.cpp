//
//  main.cpp
//  BullCowGame
//
//  Created by ax on 1/27/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

// declare
void PrintGameIntro();
FText GetValidGuess();
void PlayGame();
bool AskToPlayAgain();
void PrintGameSummary();

// Instantiate a game to play
FBullCowGame BCGame;

// run
int main() {
    
    std::cout << "TRY: " << BCGame.GetCurrentTry() << std::endl;
    
    bool bPlayAgain = false;
    do {
        PrintGameIntro(); // print the intro text
        PlayGame(); // play game
        // TODO add a game summary
        bPlayAgain = AskToPlayAgain();
    } while(bPlayAgain);
    return 0;
}

// define
void PrintGameIntro() {
    // Game introduction
    std::cout << "Bulls and Cows Word Game" << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I'm thinking of?" << std::endl;
}

void PlayGame() {
    
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    // loop asking for guesses while the game
    // is NOT won and there are tries remaining
    while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) {
        FText Guess = GetValidGuess();

        // submit valid guess to game and get back counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        std::cout << "Number Bulls \"" << BullCowCount.Bulls << "\"." << std::endl;
        std::cout << "Number Cows \"" << BullCowCount.Cows << "\"." << std::endl;
    }

    //TODO: summarize game
    PrintGameSummary();
    return;
}

// TODO: Loop contiunually until user gives valid guess
FText GetValidGuess() {
    
    FText Guess = "";
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    
    do {
        // get guess from the player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << "Try number " << CurrentTry << ". " << "Enter your guess: ";
        
        std::getline(std::cin, Guess);
        // check guess validity
        Status = BCGame.CheckGuessValidity(Guess);
        switch (Status) {
            case EGuessStatus::Not_Isogram:
                std::cout << "An isogram cannot have more than one of each letter." << std::endl;
                break;
            case EGuessStatus::Not_Lowercase:
                std::cout << "Word guess must be lowercase." << std::endl;
                break;
            case EGuessStatus::Wrong_Length:
                std::cout << "Word length must be " << BCGame.GetHiddenWordLength() << " letters." << std::endl;
                break;
            default:
                // must have been valid, eh?
                break;
        }
    } while (Status != EGuessStatus::OK);
    // fake return because compiler won't compile, damn you udemy
    return Guess;
}

bool AskToPlayAgain() {
    bool response_bool = false;
    std::cout << "Do you want to play again, [Y]es or [N]o?: ";
    FText response = "";
    std::getline(std::cin, response);
    char answer_letter = tolower(response[0]);
    if (answer_letter == 'y') {
        response_bool = true;
    }
    return response_bool;
}

void PrintGameSummary() {
    if (BCGame.IsGameWon() == true) {
        std::cout << "YOU WON!!!" << std::endl;
    } else {
        std::cout << "YOU LOSE!!!" << std::endl;
    }
}


