#include"EntreeItem.h"

EntreeItem::EntreeItem(int idInput, string nameInput, float priceInput, 
    string descInput, string orderID, bool isVegInput)
    : MealItem(idInput, nameInput, priceInput, descInput, orderID), isVegetarian(isVegInput), isSpicy(false) {}

void EntreeItem::displayDetails() const {
    cout << getName() << endl
        << "        " << getDescription() << endl
        << "        Vegetarian: " << (isVegetarian ? "Yes" : "No") << endl
        << "        Spicy: " << (isSpicy ? "Yes" : "No") << endl
        << "        $" << getPrice() << endl
        << "        Enter \"" << getOrderCode() << "\" to place an order" << endl;

}