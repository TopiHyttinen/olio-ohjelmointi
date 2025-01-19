#ifndef GAME_H
#define GAME_H

#include <string>

class Game {

private:
    int maxNumber;
    int playerGuess;
    int randomNumber;
    int numOfGuesses;
public:
    Game(int);
    void play();
    void printGameResult() const;
};

#endif

#include <iostream>
#include <cstdlib>
#include <ctime>

Game::Game(int maxNumber) : maxNumber(maxNumber), numOfGuesses(0) {
    std::srand(static_cast<unsigned>(std::time(0)));
    randomNumber = std::rand() % maxNumber + 1;
    std::cout << "Game constructed with max number: " << maxNumber << std::endl;
}

void Game::play() {
    int guess = 0;


    while (guess != randomNumber) {
        std::cout << "Give your guess between 1-" << maxNumber << std::endl;
        std::cin >> guess;
        numOfGuesses++;

        if (guess < randomNumber) {
            std::cout << "Your guess is too small" << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Your guess is too big" << std::endl;
        }
    }
            std::cout << "Your guess is right = "<< randomNumber << std::endl;

}

void Game::printGameResult() const {
    std::cout << "You guessed the right answer = " << randomNumber << " with " << numOfGuesses << " guesses" << std::endl;
}


#include <iostream>

int main() {
    int maxNumber;

    std::cout << "Enter the maximum number for the game: ";
    std::cin >> maxNumber;

    Game game(maxNumber);
    game.play();
    game.printGameResult();

    return 0;
}
