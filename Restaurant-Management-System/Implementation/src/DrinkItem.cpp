#include "DrinkItem.h"


DrinkItem::DrinkItem(int idInput, string nameInput, float priceInput, 
    string descInput, string orderID, bool alcoholInput)
    : RestaurantItem(idInput, nameInput, priceInput, descInput, orderID) {}

void DrinkItem::displayDetails() const {
    cout << getName() << endl
        << "        " << getDescription() << endl
        << "        sAlcoholic: " << (isAlcoholic ? "Yes" : "No") << endl
        << "        Size: " << size << endl
        << "        $" << getPrice() << endl
        << "        Enter \"" << getOrderCode() << "\" to place an order" << endl;
}


string DrinkItem::getSize() const { return size; }
void DrinkItem::setSize(const string& sizeInput) { size = sizeInput; }

string DrinkItem::getAlcoholContent() const { return isAlcoholic ? "Yes" : "No"; }
void DrinkItem::setAlcoholicContent(bool AlcoholInput) { isAlcoholic = AlcoholInput; }