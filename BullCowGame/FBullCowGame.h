//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by ax on 1/30/17.
//  Copyright © 2017 COMP235. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <string>
// no namespace in header file

// using substitutions
using FString = std::string;
using int32 = int;

struct FBullCowCount {
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus {
    Invalid_Status,
    OK,
    Not_Isogram,
    Not_Lowercase,
    Wrong_Length
};

class FBullCowGame {
public:
    FBullCowGame(); // constructor
    int32 GetMaxTries() const; // const prevents getter from modifying values
    int32 GetCurrentTry() const; // const prevents getter from modifying values
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const; // possible const?
    EGuessStatus CheckGuessValidity(FString) const; // TODO: make more rich return value
    // public method to reset game
    void Reset(); // TODO: return more rich return value

    // provide method for counting bulls and cows, and increase turn count
    
    // counts bulls and cows and increases try number assuming valid guess
    FBullCowCount SubmitValidGuess(FString);
    
private:
    // private data members
    int32 MyMaxTries = 5; // see constructor for initialize values
    int32 MyCurrentTry = 1;  // see constructor for initialize values
    FString MyHiddenWord;
    bool bGameIsWon = false;
};


#endif /* FBullCowGame_hpp */
