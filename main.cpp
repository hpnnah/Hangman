#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cctype>
#include <random>


class Hangman {
    private:
    std::vector<std::string> wordList = {"programming", "hangman", "challenge", "computer", "science", "development", "keyboard", "function", "variable", "iteration","algorithm", "pointer", "compiler", "website","engineer"};

    std::string selectedWord;
    std::string letterGuessed;
    std::string wrongLetters;
    bool correctWord = false;
    
    public:
    int maxAttempts = 9; // max attempts


    Hangman() {
        int randomIndex = rand() % wordList.size();
        selectedWord = wordList[randomIndex];

        letterGuessed = "";
        for (int i = 0; i < selectedWord.length(); i++) {
            letterGuessed += "_ ";
    }
    
    }

    void disguiseWord() {
        // function used to disguise the word with underscores
 
        std::cout << letterGuessed << std::endl;
    }
    std::string getWord() {
        return selectedWord;
    }

    void chooseLetterorWord() {
        // allows user to choose between letter or word guess
        /* The code uses the two functions guessWord and guessLetter 
        to let the user choose between a letter(L) or word(W) to guess
        */
        std::string choice;
        std::cout << "Would you like to guess a letter or the whole word? (L/W): ";
        std::cin >> choice;
        if (choice == "L") {
            char letter;
            std::cout << "Enter your letter: ";
            std::cin >> letter;
            guessLetter(letter); // calls guessLetter function
        }
        else if (choice == "W") {
            std::string word;
            std::cout << "Enter your word: ";
            std::cin >> word;
            guessWord(word); // calls guessWord function
        } else {
        std::cout << "Invalid choice. Please enter L or W.";
    }


    }
    void guessLetter(char letter) {
        /* This function checks to see if the player guessed the right
        letter that has not been guessed yet
        if correct letteRight will be true, it resets back to false whenever guessLetter() is called again
        wrongLetters are saved from their previous wrong guesses to show user*/
        bool letterRight = false;
        for (int i = 0; i<selectedWord.length(); i++ ) {
            if (selectedWord[i] == letter) {
                letterGuessed[i*2] = letter; // its i*2 because the words are spaced _ _ _ for the disguised word
                letterRight = true;
            }


        }
            if (letterRight == true) {
                std::cout << "Letter is correct!" << std::endl;
            }
            else {
                maxAttempts--;
                wrongLetters += letter;
                wrongLetters += ' ';
                displayHangman();
                std::cout << "Wrong letter! Attempts left: " << maxAttempts <<" Wrong letters: " << wrongLetters << std::endl;
            }
        }
    void guessWord(std::string word) {
        // Function to handle word guessing
        if (selectedWord == word) {
            std::cout << "Congratulations! You've guessed it right!" << std::endl;
            correctWord = true;
            // exits function when word is guessed correctly
            maxAttempts = 0;
            return;
        }
       
        else if (selectedWord != word) {
            maxAttempts--;;
            displayHangman();
            std::cout << "Wrong word! Attempts left: " << maxAttempts << std::endl;
            } 
            
        
    }
    void displayHangman() {
        //Each time maxAttempts decreases a new piece of hangmanis printed out
        if (maxAttempts == 8) {
            std::cout << "  |_ " << std::endl;
        }
        else if (maxAttempts == 7) { 
            std::cout << "  | " << std::endl;
            std::cout << "  |_ " << std::endl;
        }
        else if (maxAttempts == 6) { 
            std::cout << "  -- " << std::endl;
            std::cout << "  | " << std::endl;
            std::cout << "  |_ " << std::endl;
        }
        else if (maxAttempts == 5) { 

            std::cout << "  -- O" << std::endl;
            std::cout << "  | " << std::endl;
            std::cout << "  |_ " << std::endl;
        }

        else if (maxAttempts == 4) { 
            std::cout << "  -- O" << std::endl;
            std::cout << "  |  |" << std::endl;
            std::cout << "  |_ " << std::endl;
        }

        else if (maxAttempts == 3) { 
            std::cout << "  -- O" << std::endl;
            std::cout << "  | -|" << std::endl;
            std::cout << "  |_ " << std::endl;
        }
        else if (maxAttempts == 2) { 
            std::cout << "  -- O" << std::endl;
            std::cout << "  | -|-" << std::endl;
            std::cout << "  |_ " << std::endl;
        }
        else if (maxAttempts == 1) {
            std::cout << "  -- O" << std::endl;
            std::cout << "  | -|-" << std::endl;
            std::cout << "  |_| " << std::endl;
         }

        else if (maxAttempts == 0) { 
            std::cout << "  -- O" << std::endl;
            std::cout << "  | -|-" << std::endl;
            std::cout << "  |_| | " << std::endl;
        }


    }
    
    bool isWordGuessed() {
        // Check if the word has been completely guessed
        return letterGuessed.find('_') == std::string::npos || correctWord;
            return selectedWord.find('_') == std::string::npos || correctWord;

    }


};

int main() {
    // main() is used for the Hangman game to function using the Hangman class's methods and attributes
    srand(time(0)); // it seeds a random number at the start
    std::cout << "Welcome to Hangman. Would you like to play? (Y/N): ";
    char condition;
    std::cin >> condition;
    while (condition == 'Y' ) // looped until user answers N for playing again
    {

    
    Hangman game; 
    while (game.maxAttempts > 0 && !game.isWordGuessed())  {
        game.disguiseWord();
        game.chooseLetterorWord();
    }
        if (game.isWordGuessed()) {
            std::cout << "The word was: " << game.getWord() << "! :) " << std::endl;
        } 
        else {
            std::cout << "Game Over! The word was: " << game.getWord() << std::endl;
        }


            std::cout << "Do you wish to play again? (Y/N)" << std::endl;
                std::cin >> condition;


}
    return 0;
}