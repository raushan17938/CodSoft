#include <iostream>
#include <cstdlib> // For rand() and srand() functions
#include <ctime>   // For time() function
using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(nullptr)));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    int guess;
    int attempts = 0;

    cout << "Welcome to the Guess the Number Game!" << endl;
    cout << "I'm thinking of a number between 1 and 100. Try to guess it!" <<endl;

    do {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try again." <<endl;
        } else {
            cout << "Congratulations! You guessed the correct number (" << secretNumber << ") in " << attempts << " attempts!" << endl;
        }
    } while (guess != secretNumber);

    return 0;
}













































/*



In this program:
(1) We include necessary header files for input/output, random number generation, and time.
(2) We seed the random number generator with the current time to make sure the random number is different each time the program runs.
(3) We generate a random number between 1 and 100 using std::rand().
(4) We enter a loop that continues until the user guesses the correct number.
(5) Inside the loop, we ask the user to enter their guess and provide feedback on whether it's too high or too low compared to the        secret number.
(6) When the user guesses the correct number, we display a congratulations message along with the number of attempts it took.


*/