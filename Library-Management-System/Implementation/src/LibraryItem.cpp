#include "LibraryItem.h"
#include <iostream>
#include<vector>

using namespace std;

LibraryItem::LibraryItem(int d, string t, string a, string i) {
	title = t;
	author = a;
	ISBN = i;
	id = d;
}

int LibraryItem::getId() const { return id; }
string LibraryItem::getTitle() const { return title; }
string LibraryItem::getAuthor() const { return author; }
string LibraryItem::getISBN() const { return ISBN; }

