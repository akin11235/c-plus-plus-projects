#include"Node.h"


Node::Node(int id, const string& name, float price,
    string& descInput, string orderID)
    : RestaurantItem(id, name, price, descInput, orderID),
    next(nullptr) {}

Node::~Node() {}

Node::Node(RestaurantItem* menuItem)
    : next(nullptr), data(menuItem)
{}

void Node::displayDetails() const {

    data->displayDetails();
}