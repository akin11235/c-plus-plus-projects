#pragma once

#include "RestaurantItem.h"


class MealItem : public RestaurantItem {
private:
    int calories;
    string allergensInfo;
    string portionSize;
    string ingredients;

public:
    MealItem(int idInput, string nameInput, float priceInput, string descInput, string code);
    void displayDetails() const override;
    string getIngredients() const;
    void setIngredients(const string& ingredientInput);
    string getPortionSize() const;
    void setPortionSize(const string& ingredientInput);
};

