#include "RestaurantItem.h"


RestaurantItem::RestaurantItem() : id(0), price(0.0f) {}
RestaurantItem::RestaurantItem(int idInput, string nameInput, float priceInput, string descInput, string code)
	: id(idInput),
	name(nameInput),
	description(descInput),
	price(priceInput),
	orderCode(code) {}

RestaurantItem::~RestaurantItem()
{
	cout << "Destructor for MenuItem called..." << endl << endl;
}


// getters
int RestaurantItem::getId() const { return id; }
float RestaurantItem::getPrice() const { return price; }
string RestaurantItem::getName() const { return name; }
string RestaurantItem::getDescription() const { return description; }
string RestaurantItem::getOrderCode() const { return orderCode; }


// setters
void RestaurantItem::setDescription(const string& descInput) { description = descInput; }