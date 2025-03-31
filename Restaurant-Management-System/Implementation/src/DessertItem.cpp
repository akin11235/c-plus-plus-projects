
#include "DessertItem.h"

DessertItem::DessertItem(int idInput, string nameInput, float priceInput, 
    string descInput, string orderID, bool nutsInput)
    : MealItem(idInput, nameInput, priceInput, descInput, orderID), containsNuts(false) {}

void DessertItem::displayDetails() const {
    cout << getName() << endl
        << "        " << getDescription() << endl
        << "        IsAlcoholic: " << (containsNuts ? "Yes" : "No") << endl
        << "        $" << getPrice() << endl
        << "        Enter \"" << getOrderCode() << "\" to place an order" << endl;
}