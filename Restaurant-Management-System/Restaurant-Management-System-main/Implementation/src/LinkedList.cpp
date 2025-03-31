#include "LinkedList.h"



void LinkedList::InsertAtStart(int idInput, string nameInput, float priceInput, string& descInput, string orderID)
{

    Node* temp = new Node(idInput, nameInput, priceInput, descInput, orderID);
    //temp->data = value;
    temp->next = nullptr;

    if (!head) //list is empty
    {
        head = temp;
    }
    else // list exist
    {
        temp->next = head; // new node is now connected/pointing to the first node of linked list
        head = temp; // update head to point to new first node
    }
}


void LinkedList::InsertAtStart(RestaurantItem* menuItem)
{

    //Node* temp = new Node(mealItem->getId(), mealItem->getName(), mealItem->getPrice(), mealItem->getDescription());
    Node* temp = new Node(menuItem);
    //temp->data = value;
    temp->next = nullptr;

    if (!head) //list is empty
    {
        head = temp;
    }
    else // list exist
    {
        temp->next = head; // new node is now connected/pointing to the first node of linked list
        head = temp; // update head to point to new first node
    }
}

void LinkedList::displayList() const
{
    /*   cout << "\nDisplaying List Elements..." << endl;*/
    for (Node* p = head; p != nullptr; p = p->next)
    {
        p->displayDetails();

    }
    cout << "NULL" << endl;
}

void LinkedList::InsertAtMiddle(int pos, RestaurantItem* value)
{
    Node* p = head;

    for (int i = 1; i < pos && p != NULL; i++)
    {
        p = p->next;
    }

    if (p != NULL) //enough nodes in the list to insert after position pos
    {
        Node* temp = new Node(value);
        temp->data = value;
        temp->next = nullptr;

        temp->next = p->next;
        p->next = temp;
    }
    else  //not enough nodes in the list 
    {
        cout << "Invalid position for the current linked list" << endl;
    }
}

Node* LinkedList::searchList(RestaurantItem* value)
{
    Node* temp = head; // temp pointer for transversal
    cout << "TESTING" << endl << endl;

    while (temp != NULL)
    {
        cout << value->getName() << endl;
        if (temp->getName() == value->getName())
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

//searches for a node by its ID and returns a pointer to the node if found.
Node* LinkedList::searchList(int id) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->getId() == id) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

int LinkedList::searchCount(RestaurantItem* value)
{
    Node* temp = head;
    int count = 0;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            count++;
        }
        temp = temp->next;
    }
    return count;
}

void LinkedList::updateElement(RestaurantItem* old_data, RestaurantItem* new_data)
{
    Node* temp = searchList(old_data);

    if (temp) //temp!=NULL
    {
        temp->data = new_data;
        cout << old_data << " is updated with " << new_data << endl;
    }
    else
    {
        cout << old_data << " value does not exist in the current list" << endl;
    }
}


void LinkedList::deleteNode(RestaurantItem* value)
{
    if (searchList(value)) //searchList(value) != NULL
    {
        cout << "Node Found, Deleting ... " << endl;
    }
    else
    {
        cout << "Node doesn't exist, can't delete." << endl;
        return;
    }

    Node* before, * discard;

    before = NULL;
    discard = head;

    while (discard != NULL)
    {
        if (discard->data == value)  //case where node is found and will be deleted
        {
            if (before) // Node is not the first node
            {
                before->next = discard->next;   //connect the previous and next node of discard node

                delete discard;
                discard = NULL;

                cout << "Node Deleted Successfully" << endl;
            }
            else // Node is first node
            {
                head = discard->next;
                delete discard;
                discard = NULL;

                cout << "Node Deleted Successfully" << endl;
            }

        }
        else  // node not found, move to the next node
        {
            before = discard;
            discard = discard->next;
        }
    }
}

// Function to search the list, retrieve items based on a condition, and store them in a vector
void LinkedList::searchAndRetrieve(vector<RestaurantItem*>& vec, RestaurantItem* value) {
    Node* temp = head;
    while (temp) {
        if (temp->data->getName() == value->getName()) {
            vec.push_back(temp->data);
        }
        temp = temp->next;
    }
}