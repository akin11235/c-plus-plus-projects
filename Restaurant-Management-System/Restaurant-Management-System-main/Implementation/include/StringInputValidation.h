#pragma once

#include<iostream>
#include<string>
#include <regex>

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

// Function to validate the input string
string isValidInput(const string& input) {
    // Check for empty input
    if (input.empty()) {
        return "Input cannot be empty.";
    }

    // Check for special characters using regex
    std::regex specialChars("[^a-zA-Z0-9]");
    if (std::regex_search(input, specialChars)) {
        return "Input cannot contain special characters.";
    }

    // Check for minimum and maximum length
    const int minLength = 3;
    const int maxLength = 20;
    if (input.length() < minLength) {
        return "Input must be at least " + std::to_string(minLength) + " characters long.";
    }
    if (input.length() > maxLength) {
        return "Input must be no more than " + std::to_string(maxLength) + " characters long.";
    }

    // If all checks pass
    return "";
}

// Function to get and validate string input
string getStringInput(const string& promptUser, bool& exitCondition) {
    string input;

    while (true) {
        cout << promptUser;
        getline(cin, input);

        if (input == "x" || input == "X") {
            exitCondition = true;
            return "";
        }

        // Validate input
        string errorMessage = isValidInput(input);
        if (errorMessage.empty()) {
            return input;
        }
        else {
            cout << errorMessage << endl;
            // Continue the loop to prompt the user again
        }
    }
}
