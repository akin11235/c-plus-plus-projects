#pragma once

#include<iostream>



using std::string;
using std::cout;
using std::cin;
using std::endl;

int menuAdmin()
{
    int ch;

    while (true) {
        try {
            cout << "Admin Navigation Options" << "\n----------------" << endl;
            cout << "1: View Meal Items" << endl;
            cout << "2: View Drink Items" << endl;
            //cout << "3: View Order" << endl << endl;
            cout << "0: Exit" << endl << endl;
            cout << "Enter your choice: ";
            cin >> ch;

            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw invalid_argument("Invalid input. Please enter an integer.");
            }
            return ch;
        }
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    }
}


int menuCustomer()
{
    int ch;

    while (true)
    {
        try {
            //cout << "\nMenu Options" << "\n----------------" << endl;
            cout << "------------------------------------------------------------------------------------------------------------" << endl;
            cout << "\nMENUS\n" << endl;
            cout << "1. Select Entree";
            cout << "   2. Select Side Dishes"
                 << "   3. Select Desserts"
                 << "   4. Select Drinks";
            cout << "   5. Place Order";
            cout << "   0. Exit" << endl << endl;

            cout << "Enter your choice: ";
            cin >> ch;
            cin.clear(); // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input

            if (cin.fail()) {
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                throw invalid_argument("Invalid input. Please enter an integer.");
            }
            return ch;
        }
        
        catch (const invalid_argument& e) {
            cout << e.what() << endl;
        }
    } 
}
