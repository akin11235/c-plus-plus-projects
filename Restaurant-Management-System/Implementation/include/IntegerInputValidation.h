#pragma once

#include<iostream>
#include<iomanip>
#include<limits>
#include<string>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::numeric_limits;
using std::streamsize;


//=============================================================
//////////// ** FUNCTION DEFINITIONS ** /////////////
//=============================================================

int getIntInput(const string& promptUser, bool& exitCondition) {
	int input;
	while (true) {

		cout << promptUser;
		cin >> input;
		if (input == -1)
		{
			exitCondition = true;
			return -1;
		}
		if (cin.fail()) {
			cin.clear(); // clear the error flags
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
			cout << "Invalid input... Enter an integer value." << endl;
		}
		else {
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard remaining input
			return input;
		}
	}
}
