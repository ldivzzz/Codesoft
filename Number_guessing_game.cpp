
#include <iostream> // Include the input-output stream library for basic input-output operations.
#include <ctime> // Include the ctime library for time-related functions.
#include <cstdlib> // Include the cstdlib library for general utilities.

class NumberGuessingGame { // Define a class called NumberGuessingGame.
private:
    int secretNumber; // Declare a private integer variable to store the secret number.
    int lowerBound; // Declare a private integer variable to store the lower bound of the guess range.
    int upperBound; // Declare a private integer variable to store the upper bound of the guess range.

public:
    NumberGuessingGame(int lower, int upper) : lowerBound(lower), upperBound(upper) { // Constructor to initialize the class with lower and upper bounds.
        std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed the random number generator using the current time.
        secretNumber = std::rand() % (upperBound - lowerBound + 1) + lowerBound; // Generate a random number within the specified range.
    }

    void play() { // Method to start the game.
        std::cout << "Welcome to the Number Guessing Game!\n"; // Display a welcome message.
        std::cout << "Try to guess the secret number between " << lowerBound << " and " << upperBound << ".\n"; // Display the range of numbers to guess.

        int guess; // Declare an integer variable to store the user's guess.
        do { // Start a do-while loop to repeatedly ask for guesses until the correct number is guessed.
            std::cout << "Enter your guess: "; // Prompt the user to enter their guess.
            std::cin >> guess; // Read the user's guess from the standard input.

            if (guess < secretNumber) { // Check if the guess is lower than the secret number.
                std::cout << "Too low! Try again.\n"; // Display a message indicating that the guess is too low.
            } else if (guess > secretNumber) { // Check if the guess is higher than the secret number.
                std::cout << "Too high! Try again.\n"; // Display a message indicating that the guess is too high.
            } else { // If the guess is correct.
                std::cout << "Congratulations! You guessed the secret number.\n"; // Display a message indicating that the guess is correct.
            }
        } while (guess != secretNumber); // Continue the loop until the guess matches the secret number.
    }
};

int main() { // The main function, entry point of the program.
    int lower, upper; // Declare integer variables to store the lower and upper bounds of the guess range.
    std::cout << "Enter the lower bound of the guess range: "; // Prompt the user to enter the lower bound.
    std::cin >> lower; // Read the lower bound from the standard input.
    std::cout << "Enter the upper bound of the guess range: "; // Prompt the user to enter the upper bound.
    std::cin >> upper; // Read the upper bound from the standard input.

    NumberGuessingGame game(lower, upper); // Create an instance of the NumberGuessingGame class with the specified bounds.
    game.play(); // Call the play method to start the game.

    return 0; // Return 0 to indicate successful execution of the program.
}
