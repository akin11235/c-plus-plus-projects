
#include"MealItem.h"

MealItem::MealItem(int idInput, string nameInput, float priceInput, string descInput, string code)
    : RestaurantItem(idInput, nameInput, priceInput, descInput, code), calories(30) {}



void MealItem::displayDetails() const {
    cout << getName() << endl
        << "  " << getDescription() << endl
        << "  $" << getPrice() << endl
        << "  $" << getOrderCode() << endl << endl;
}


string MealItem::getIngredients() const { return ingredients; }
void MealItem::setIngredients(const string& ingredientInput) { ingredients = ingredientInput; }

string MealItem::getPortionSize() const { return ingredients; }
void MealItem::setPortionSize(const string& ingredientInput) { ingredients = ingredientInput; }
