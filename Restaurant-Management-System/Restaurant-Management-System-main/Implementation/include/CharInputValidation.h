#pragma once

#include<iostream>

#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;

// Function to get and validate character input
char getCharInput(const string& promptUser, bool& exitCondition) {
    char input;
    while (true) {
        cout << promptUser;
        cin >> input;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the newline character left in the buffer

        // Handle invalid input or clear the fail state
        if (cin.fail()) {
            cin.clear(); // Clear the fail state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a single alphabet character." << endl;
            continue;
        }

        if (input == 'x') {
            exitCondition = true;
            return 'x';
        }
        if (!isalpha(input)) { // Check if input is not an alphabet character
            cout << "\nInvalid input. Please enter a single alphabet character." << endl;
        }
        else {
            return input;
        }
    }
}