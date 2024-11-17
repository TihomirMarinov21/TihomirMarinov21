#include <iostream>
#include <cstdlib>  // Include the library for rand()
#include <ctime>    // Include the library for time()

int main() {
    using namespace std;

    int choice;
    srand(time(0));  // Seed the random number generator with the current time
    int winNum = rand() % 100 + 1;  // Generate a random number between 1 and 100

    cout << "*****************" << '\n';
    cout << "Guess the Number" << '\n';
    cout << "                 " << '\n';

    bool guessedCorrectly = false;

    while (!guessedCorrectly) {
        cin >> choice;

        if (choice == winNum) {
            cout << "You won !!!" << '\n';
            guessedCorrectly = true;
        } else if (choice < winNum) {
            cout << "Your number is too low, try a higher number" << '\n';
        } else {
            cout << "Your number is too high, try a lower number" << '\n';
        }
    }   cout << "THANKS FOR PLAYING" << '\n';    
        cout << "******************************" << '\n';
    return 0;
}
