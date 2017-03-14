//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by ax on 1/30/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#include "FBullCowGame.h"

// Default constructor calls own method Reset, and that's OK
FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const {return static_cast<int32>(MyHiddenWord.length()); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

void FBullCowGame::Reset(){
    constexpr int MAX_TRIES = 10;
    const FString HIDDEN_WORD = "qwert";
    MyMaxTries = MAX_TRIES;
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString input) const {
    if (false) {
    // if the guess isn't an isogram
        // return error
        return EGuessStatus::Not_Isogram;
    } else if (false) {
    // if the guess isn't all lowercase
        // return error
        return EGuessStatus::Not_Lowercase;
    } else if (input.length() != GetHiddenWordLength()) {
    // if the guess length is wrong
        // return error
        return EGuessStatus::Wrong_Length;
    } else {
    // otherwise
        // return OK
        return EGuessStatus::OK;
    }
}

// receives a valid guess, increments turn and returns count
FBullCowCount FBullCowGame::SubmitValidGuess(FString input_guess) {

    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = GetHiddenWordLength();
    
    FString guess = input_guess;
    FString hidden_word = MyHiddenWord;
    
    // loop through all letter in hidden word
    for (int32 i = 0; i < WordLength; i++) {
        for (int32 j = 0; j < WordLength; j++) {
        // compare letters against the guess
            if (guess[i] == hidden_word[j]) { // if they match then
                if (i == j) {
                    // increment bulls if theyre in the right spot
                    BullCowCount.Bulls++;
                } else {
                    // increment cows if they're not in the right spot
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    if (BullCowCount.Bulls == WordLength) {
        bGameIsWon = true;
    } else {
        bGameIsWon = false;
    }
    
    return BullCowCount;
};
