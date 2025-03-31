#include"Magazine.h"
#include <iostream>

using std::cout;
using std::endl;

Magazine::Magazine(int d, const string& t, const string& a,
	const string& i, const string& g, int y) : LibraryItem(d, t, a, i) 
{
	genre = g; year = y;
};

void Magazine::displayDetails() const
{
	cout << getTitle() << endl;
	cout << "      by " << getAuthor() << " - " << getYear() << endl;
	cout << "      ISBN: " << getISBN() << endl;
	cout << "      Genre: " << getGenre() << endl << endl;

}

string Magazine::displayGenre() const { return genre; }
int Magazine::getYear() const { return year; }
string Magazine::getGenre() const { return genre; }