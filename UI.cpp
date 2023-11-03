#include "UI.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

UI::UI(concreteCommand *c)
{
    this->c1 = c;
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
