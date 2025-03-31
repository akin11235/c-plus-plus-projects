#pragma once

#include<iostream>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cstdlib>
#include<map>

#include "Book.h"
#include "Catalog.h"

using std::cout;
using std::endl;
using namespace std;

// Template class for Catalog
template <typename T>
class Catalog {
private:
	string userName;
	int index = 0;
	vector<T*> itemsList; // vector to store all categories of library items
	map<string, string> titleAndAuthor; // map to store title and author
	vector<LibraryItem*>::iterator it; // iterator for itemsList vector
	map<string, string>::iterator itMap; // iterator for titleAndAuthor map

public:
	
	Catalog(string name); // default constructor 

	// destructor
	~Catalog()
	{
		for (T* item : itemsList)
		{
			delete item;
		}
		itemsList.clear();
		cout << "Destructor for Catalog class is called" << endl;
	}

	// Accessor method for items
	const vector<T*>& getItemsList() const;


	// base condition for adding to vector
	void addItemToMainList();

	// variadic function
	template<typename... Args>
	void addItemToMainList(T* value, Args... args);

	void addItemToMap();

	template<typename... Args>
	void addItemToMap(T* value, Args... args);


	void totalItemsInList();
	void removeLastItem();
	void removeItem(const T& item);
	void removeAllItems();

	void displayAll();

	void displayAuthors();

	void displayAllGenres();

	static void showAuthors(T* n, int index);

	static void showGenres(T* n, int index);

	void displayTitleAndAuthor();

	// Functor for sorting by title
	struct SortByTitle {
		bool operator()(const T* a, const T* b) {
			return a->getTitle() < b->getTitle();
		}
	};

	// function for sort by title
	void sortByTitle();

	// Functor for sorting by genre
	struct SortByGenre {
		bool operator()(const T* a, const T* b) {
			return a->getGenre() < b->getGenre();
			
		}
	};


	void sortByGenre();

	template <typename Func>
	T* searchItem(Func func) const;

	const T* searchItem(const string& key) const;

	const T* searchItem(int key) const;

	void getLastAdded();
		
};  // End Catalog class


//=============================================================
///////////// ** CONSTRUCTOR FUNCTION DEFINITION ** ///////////
//=============================================================
template <typename T>
Catalog<T>::Catalog(string name)
{
	userName = name;
}


//=============================================================
///////////// ** GETTER FOR ITEMSLIST ** ///////////
//=============================================================
template <typename T>
const vector<T*>& Catalog<T>::getItemsList() const {
	return itemsList;
}


//=============================================================
//////////// ** ADD ITEMS FUNCTION DEFINITIONS ** //////////////
//=============================================================
template<typename T>
void Catalog<T>::addItemToMainList()
{};

// variadic function to add multiple items to the vector
template<typename T>
template<typename... Args>
void Catalog<T>::addItemToMainList(T* value, Args... args)
{
	itemsList.push_back(value); // Push the first element
	addItemToMainList(args...); // Recursively push the rest
	titleAndAuthor.insert(pair<string, string>(value->getAuthor(), value->getTitle()));
}

template<typename T>
void Catalog<T>::addItemToMap() {};

template<typename T>
template<typename... Args>
void Catalog<T>::addItemToMap(T* value, Args... args)
{
	titleAndAuthor[value->getTitle] = value->getAuthor();
	addItemToMap(args...);
	titleAndAuthor.insert({ value->getTitle(), value->getAuthor() });
};


//=============================================================
///////////// ** DISPLAY FUNCTION DEFINITIONS ** //////////////
// 
//=============================================================
template<typename T>
void Catalog<T>::displayAll()
{
	if (itemsList.size() < 1)
		cout << "There are no items in the catalog.";
	else
	{
		for (it = itemsList.begin(), index = 1; it != itemsList.end(); it++, ++index)
		{
			cout << index << ". ";
			(*it)->displayDetails();
		}
	}
};

template<typename T>
void Catalog<T>::displayTitleAndAuthor()
{
	if (itemsList.size() < 1)
		cout << "There are no items in the catalog.";
	else
	{
		for (itMap = titleAndAuthor.begin(); itMap != titleAndAuthor.end(); itMap++)
		{
			cout << "Title: " << (*itMap).first << endl;
			cout << "Author: " << (*itMap).second << endl << endl;
		}
	}
};

template<typename T>
void Catalog<T>::getLastAdded()
{
	if (itemsList.empty())
		throw std::runtime_error("There are no items in the catalog.");
	else
	{
		T* lastItem = itemsList.back();
		cout << lastItem->getTitle();
	}
};

//cout << getTitle() << endl;
//cout << "      by " << getAuthor() << " - " << getYear() << endl;
//cout << "      ISBN: " << getISBN() << endl;
//cout << "      Genre: " << getGenre() << endl << endl;


//void showGenres()
//{
//	for (it = itemsList.begin(); it != itemsList.end(); it++)
//	{
//		(*it)->getAuthor();
//		cout << endl;
//	}
//}

template<typename T>
void Catalog<T>::showGenres(T* n, int index)
{
	cout << index << ". " << n->getGenre() << endl;

}

template<typename T>
void Catalog<T>::displayAllGenres()
{
	int index = 1;
	for_each(itemsList.begin(), itemsList.end(), [&index](T* n)
		{showGenres(n, index); ++index; });
}

template<typename T>
void Catalog<T>::showAuthors(T* n, int index)
{
	cout << index << ". " << n->getAuthor() << endl;

}

template<typename T>
void Catalog<T>::displayAuthors()
{
	int index = 1;
	for_each(itemsList.begin(), itemsList.end(), [&index](LibraryItem* n)
		{showAuthors(n, index); ++index; });
}

template <typename T>
void Catalog<T>::totalItemsInList()
{
	cout << "Total number of items in the catalog: ";
	cout << itemsList.size() << endl;
}


//=============================================================
///////////// ** REMOVE ITEMS FUNCTION DEFINITIONS ** //////////////
//=============================================================
template<typename T>
void Catalog<T>::removeLastItem()
{
	itemsList.pop_back();
}

template<typename T>
void Catalog<T>::removeItem(const T& item)
{
	itemsList.pop_back();
};

template<typename T>
void Catalog<T>::removeAllItems()
{
	itemsList.clear();
}


//=============================================================
///////////// ** SORTING FUNCTION DEFINITIONS ** //////////////
//=============================================================

// sorting items by title using functor
template<typename T>
void Catalog<T>::sortByTitle() {
	sort(itemsList.begin(), itemsList.end(), SortByTitle());
}

// sorting items by genre using functor
template<typename T>
void Catalog<T>::sortByGenre() {
	sort(itemsList.begin(), itemsList.end(), SortByGenre());
}


//=============================================================
//////////// ** SEARCHING FUNCTION DEFINITIONS ** /////////////
//=============================================================

// custom search function
template <typename T>
template <typename Func>
T* Catalog<T>::searchItem(Func func) const {
	return *itemsList.begin();
}

template <typename T>
const T* Catalog<T>::searchItem(const string& key) const {
	auto it = std::find_if(itemsList.begin(), itemsList.end(), [&key](const T* item) {
		return item->getTitle() == key;
		});

	if (it != itemsList.end()) {
		return *it;
	}
	else {
		throw std::runtime_error("Item not found");
	}
}

// Method to get a int key 
template <typename T>
const T* Catalog<T>::searchItem(int key) const {
	auto it = find_if(itemsList.begin(), itemsList.end(), [key](const T* item) {
		return item->getId() == key;
		});

	if (it != itemsList.end()) {
		return *it;
	}
	else {
		throw std::runtime_error("Item not found");
	}
}

