#include"Book.h"
#include<iomanip>
#include <iostream>

using std::cout;
using std::endl;

using std::setw;
using std::left;
using std::right;

Book::Book(int d, const string& t, const string& a,
	const string& i, const string& g, int y) : LibraryItem(d, t, a, i) {
	genre = g; year = y;
};


void Book::displayDetails() const 
{
	cout << getTitle() << endl;
	cout << "      by " << getAuthor() << " - " << getYear() << endl;
	cout << "      ISBN: " << getISBN() << endl;
	cout << "      Genre: " << getGenre() <<  endl << endl;
}

string Book::displayGenre() const { return genre; }
int Book::getYear() const { return year; }
string Book::getGenre() const { return genre; }