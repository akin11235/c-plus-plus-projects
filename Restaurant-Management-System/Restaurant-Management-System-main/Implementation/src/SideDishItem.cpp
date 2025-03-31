#include"SideDishItem.h"

SideDishItem::SideDishItem(int idInput, string nameInput, float priceInput, string descInput, string orderID, bool isShareableInput, string dressingInput, bool glutenInput)
    : MealItem(idInput, nameInput, priceInput, descInput, orderID), isShareable(isShareableInput), dressing(dressingInput), isGlutenFree(glutenInput) {}


void SideDishItem::displayDetails() const {
    cout << getName() << endl
        << "        " << getDescription() << endl
        << "        Alcoholic Content: " << (isShareable ? "Yes" : "No") << endl
        << "        Gluten content: " << (isGlutenFree ? "Yes" : "No") << endl
        << "        Dressing: " << dressing << endl
        << "        $" << getPrice() << endl
        << "        Enter \"" << getOrderCode() << "\" to place an order" << endl;
}