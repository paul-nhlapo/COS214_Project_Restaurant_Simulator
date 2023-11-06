#include "UI.h"
#include <string>
#include <iostream>
#include <vector>
#include <limits>
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
            if (gSize < 2 || gSize > 150)
            {
                cout << "\033[1;31mInvalid group size. We only accommodate groups of 2 to 150. Moving forward as single. \033[0m" << endl;
                Customer *single = c1->produceCustomer('!');

                // c1->seatCustomer(single);
            }
            else
            {
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
        }
    }
}

void UI::order()
{
    this->c1->startOrdering();
}

void UI::additionLoop()
{

    int choice = 1;
    int customerCount = 0; // add a counter for the number of customers
    while (choice == 1)
    {
        addCustomer();
        this->mainFloor->printFloor();
        customerCount++; // increment the counter each time a customer is added

        // if 2 customers have been added, break the loop
        if (customerCount >= 1)
        {
            choice = 2; // set choice to 2 to stop the loop

            std::cout << "Would you like to add another customer? 1 for yes, 2 for no: " << endl;
            if (!(std::cin >> choice) || (choice != 1 && choice != 2))
            {
                // clear the error state of cin
                std::cin.clear();
                // ignore the bad input
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Defaulting to no." << std::endl;
                choice = 2; // set default value
            }
            break; // exit the loop
        }
    }

    this->mainFloor->options();
    order();
}