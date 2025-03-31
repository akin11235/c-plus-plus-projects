#pragma once
#include<iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

class RestaurantItem
{
public:

	RestaurantItem();
	RestaurantItem(int idInput, string nameInput, float priceInput,
		string descInput, string code);

	~RestaurantItem();

	// pure virtual function
	virtual void displayDetails() const = 0;

	// getters
	int getId() const;
	float getPrice() const;
	string getName() const;
	string getDescription() const;
	string getOrderCode() const;

	// setters
	void setDescription(const string& descInput);
	
private:
	int id;
	string name;
	string description;
	float price;
	string orderCode;
};