#pragma once

#include<iostream>
#include "LibraryItem.h"
#include<string>

using std::string;
using std::cout;
using std::endl;

class Book : public LibraryItem {
protected:

	/*std::string genre;
	int year = 0;*/

public:
	Book(int d, const string& t, const string& a,
		const string& i, const string& g, int y);

	void displayDetails() const override;
	string displayGenre() const override;

	// Getters for attributes to be used in functors and templates
	
	int getYear() const;
	string getGenre() const override;

	// Implement constructors and other necessary member functions
	~Book()
	{
		cout << "Destructor for " << getTitle() << " called." << endl ;
	}
};
