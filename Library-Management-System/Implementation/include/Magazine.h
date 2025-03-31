#pragma once
#include<iostream>
#include "LibraryItem.h"
#include<string>

using std::string;
class Magazine : public LibraryItem {

protected:
	std::string genre;
	int year = 0;

public:
	Magazine(int d, const string& t, const string& a,
		const string& i, const string& g, int y);

	void displayDetails() const override;
	string displayGenre() const override;

	// Getters for attributes to be used in functors and templates
	int getYear() const;
	string getGenre() const override;

	~Magazine()
	{
		cout << "Destructor for Book item with " << getTitle() << " called" << endl;
	}
};
