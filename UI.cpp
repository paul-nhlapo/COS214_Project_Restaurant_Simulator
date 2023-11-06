#include "UI.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

UI::UI(concreteCommand *c, Floor *f)
{
    this->c1 = c;
    mainFloor = f;
}

UI::~UI()
{
    delete c1;
}

void UI::addCustomer()
{
    cout << "Table Size? " << endl;
    cout << "1. Single" << endl;
    cout << "2. Group" << endl;
    cout << endl;
    int size;
    cin >> size;
    if (size == 1)
    {
        Customer *single = c1->produceCustomer('!');
        // c1->seatCustomer(single);
    }
    else
    {
        if (size == 2)
        {
            cout << "Enter your group's size: " << endl;
            int gSize;
            cin >> gSize;
            vector<Customer *> tempVec;
            int x;
            int y;
            pair<int, int> option = c1->reserveGroupTable();
            x = option.first;
            y = option.second;
            for (int i = 0; i < gSize; i++)
            {
                tempVec.push_back(c1->produceCustomer(c1->getGroupID()));
            }
            cout << "x " << x << " y " << y << endl;
            int counter = 1;
            for (Customer *customer : tempVec)
            {
                cout << "Seating customer: " << counter << endl;
                c1->seatMultipleCustomers(x, y, customer);
                counter++;
            }
            c1->setGroupID();
        }
        else
        {
            cout << "Invalid input, moving forward as single" << endl;
            Customer *single = c1->produceCustomer('!');
            // c1->seatCustomer(single);
        }
    }
}

void UI::order()
{
    this->c1->startOrdering();
}

void UI::additionLoop()
{
    int choice;
    do
    {
        addCustomer();
        this->mainFloor->printFloor();

        std::cout << "Would you like to add another customer? 1 for yes, 2 for no: " << endl;
        std::cin >> choice;
    } while (choice == 1);

    char continueOrdering = 'Y';
    while (continueOrdering == 'Y' || continueOrdering == 'y')
    {
        this->mainFloor->options();
        order();
        cout << "Would you like to continue ordering? (Y/N): ";
        cin >> continueOrdering;
    }
}
