// focppp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> // For input and output operations
#include <iomanip>  // For std::setw function
#include <cmath>    // For exponentiation and fmod
#include <ctime>    // For seeding random numbers
using namespace std;

// Function to generate the number pyramid pattern
void task1(int rows) {
    for (int n = 1; n <= rows; ++n) {
        // Print leading spaces for alignment
        for (int space = 1; space <= rows - n; ++space) {
            cout << "   "; // Spaces for pyramid shape
        }

        // Print increasing numbers
        int num = n;
        for (int j = 1; j <= n; ++j) {
            cout << setw(2) << num << " "; // Print number with width
            ++num; // Increment number
        }

        // Print decreasing numbers
        num -= 2; // Start mirroring
        for (int j = 1; j < n; ++j) {
            cout << setw(2) << num << " "; // Print mirrored number
            --num; // Decrement number
        }

        cout << endl; // Move to the next line after each row
    }
}

// Function for addition
double addition(double a, double b) {
    return a + b;
}

// Function for subtraction
double subtraction(double a, double b) {
    return a - b;
}

// Function for multiplication
double multiplication(double a, double b) {
    return a * b;
}

// Function for division with error handling
double division(double a, double b) {
    if (b == 0) {
        cout << "ERROR: Division by 0 is undefined.\n";
        return 0;
    }
    return a / b;
}

// Function to calculate the remainder
double Remainder(double a, double b) {
    if (b == 0) {
        cout << "ERROR: Modulus by 0 is undefined.\n";
        return 0;
    }
    return fmod(a, b);
}

// Function to calculate exponentiation
double Exponentiation(double a, double b) {
    return pow(a, b);
}

// Function to generate a random number between 1 and 1000
int generateTargetNumber() {
    srand(static_cast<unsigned int>(time(0))); // Seed random number generator
    return rand() % 1000 + 1; // Random number between 1 and 1000
}

// Function to get the player's guess
int PlayerGuess() {
    int guess;
    cout << "\nEnter your guess: ";
    cin >> guess; // Get player's guess
    return guess; // Return the guess
}

// Function to evaluate the guess
string evaluateGuess(int guess, int targetNumber) {
    int difference = abs(guess - targetNumber); // Calculate difference

    if (difference == 0)
        return "Correct! You've guessed the number.\n";
    else if (difference > 200)
        return (guess > targetNumber) ? "Too high!\n" : "Too low!\n";
    else if (difference > 10)
        return (guess > targetNumber) ? "High!\n" : "Low!\n";
    else
        return (guess > targetNumber) ? "Slightly high!\n" : "Slightly low!\n";
}

// Function to apply penalties based on guess difference
int applyDynamicPenalty(int difference) {
    if (difference > 500)
        return 100;
    else if (difference > 300)
        return 50;
    else if (difference > 200)
        return 30;
    else if (difference > 100)
        return 20;
    else if (difference > 10)
        return 10;
    return 0; // No penalty for small differences
}

// Function to calculate penalties based on attempts
int applyAttemptPenalty(int attempts) {
    if (attempts >= 2 && attempts <= 5)
        return 10 * attempts;
    else if (attempts >= 6 && attempts <= 10)
        return 20 * attempts;
    else if (attempts > 10)
        return 50 * attempts;
    return 0;
}

// Function to calculate bonus points for fewer attempts
int applyBonusPoints(int attempts) {
    if (attempts <= 3)
        return 200;
    else if (attempts <= 6)
        return 100;
    return 0; // No bonus for more attempts
}

// Main function for the guessing game
void playGame() {
    int targetNumber = generateTargetNumber(); // Generate target number
    int guess, attempts = 0, score = 1000;     // Initialize variables

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "I have chosen a number between 1 and 1000. Try to guess it!\n";

    // Game loop
    while (true) {
        guess = PlayerGuess(); // Get player's guess
        attempts++; // Increment attempt count
        int difference = abs(guess - targetNumber); // Calculate difference

        cout << evaluateGuess(guess, targetNumber); // Display feedback

        if (difference == 0)
            break; // End loop if correct guess

        // Apply penalty and update score
        int penalty = applyDynamicPenalty(difference);
        score -= penalty;
        if (penalty > 0) {
            cout << "Dynamic Penalty: -" << penalty << " points applied.\n";
        }
        cout << "Current score: " << score << endl; // Display updated score
    }

    // Apply penalties based on attempts
    int attemptPenalty = applyAttemptPenalty(attempts);
    score -= attemptPenalty;
    if (attemptPenalty > 0) {
        cout << "Attempt-based Penalty: -" << attemptPenalty << " points for " << attempts << " attempts.\n";
    }

    // Apply bonus points and update score
    int bonusPoints = applyBonusPoints(attempts);
    score += bonusPoints;
    if (bonusPoints > 0) {
        cout << "Bonus Points: +" << bonusPoints << " points for " << attempts << " attempts.\n";
    }

    // Ensure score doesn't go below zero
    if (score < 0)
        score = 0;

    // Display final results
    cout << "\nGame Over! You took " << attempts << " attempts to guess the number.\n";
    cout << "Your final score is: " << score << endl;
}

// Function for task 3
void task3() {
    playGame(); // Start the game
}

int main() {
    int choice;
    while (true) {
        cout << "\nMain Menu \n";
        cout << "1. Numbers Pyramid\n";
        cout << "2. Calculator\n";
        cout << "3. Guessing Game\n";
        cout << "4. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Task 1 Started\n";
            int rows; // Variable for number of rows

            cout << "Enter the number of rows: ";
            cin >> rows; // Read number of rows from user input

            task1(rows); // Display the pyramid pattern
            break;
        }
        case 2: {
            double num1 = 0, num2 = 0; // Initialize numbers
            char calcChoice;

            cout << "Task 2 Started\n";

            while (true) {
                cout << "First Number = " << num1 << " | Second Number = " << num2 << endl;
                cout << "\nCalculator Menu\nSelect an Option (a-f) or (x,n):\n";
                cout << "a. Addition\nb. Subtraction\nc. Multiplication\nd. Division\ne. Remainder\nf. Exponentiation\nx. Exit\nn. Enter New Numbers\n";

                cout << "Select an Option: ";
                cin >> calcChoice;

                // Handle exiting or entering new numbers
                if (calcChoice == 'x') {
                    cout << "Exiting the Program.\n";
                    return 0; // Exit the program
                }
                else if (calcChoice == 'n') {
                    cout << "Enter First Number: ";
                    cin >> num1;
                    cout << "Enter Second Number: ";
                    cin >> num2;
                    continue; // Restart the loop with new numbers
                }

                // Perform operations based on user's choice
                switch (calcChoice) {
                case 'a':
                    cout << "Sum: " << addition(num1, num2) << endl;
                    break;
                case 'b':
                    cout << "Difference: " << subtraction(num1, num2) << endl;
                    break;
                case 'c':
                    cout << "Product: " << multiplication(num1, num2) << endl;
                    break;
                case 'd':
                    cout << "Quotient: " << division(num1, num2) << endl;
                    break;
                case 'e':
                    cout << "Remainder: " << Remainder(num1, num2) << endl;
                    break;
                case 'f':
                    cout << num1 << " raised to the power of " << num2 << " is " << Exponentiation(num1, num2) << endl;
                    break;
                default:
                    cout << "Invalid Choice. Please TRY AGAIN!\n";
                    break;
                }
            }
            break;
        }
        case 3:
            cout << "Task 3:\n";
            task3(); // Start the guessing game
            break;
        case 4:
            cout << "Exiting the program." << endl << "Goodbye!";
            return 0; // Exit the program
        default:
            cout << "Invalid choice! TRY AGAIN.\n";
            break;
        }
    }
    return 0; // Indicates successful completion
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
