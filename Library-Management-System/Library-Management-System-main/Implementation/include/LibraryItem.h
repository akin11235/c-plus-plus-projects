#pragma once
#include<iostream>



using std::string;
using std::cout;
using std::endl;


class LibraryItem
{
private:
	string title;
	string author;
	string ISBN;
	int id;

public:
	LibraryItem(int d, string t, string a, string i);

	// pure virtual function
	virtual void displayDetails() const = 0;
	virtual string displayGenre() const = 0;

	virtual ~LibraryItem() 
	{
		cout << "Destructor for LibraryItem called..." << endl << endl;
	};
	

	// getters
	int getId() const;

	std::string getTitle() const;


	std::string getAuthor() const;


	std::string getISBN() const;

	virtual string getGenre() const { return genre; };

protected:
	std::string genre;
	int year = 0;
};
