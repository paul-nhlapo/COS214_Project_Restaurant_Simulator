#include "concreteCommand.h"
#include <string>
#include <vector>
#include <limits>
using namespace std;

concreteCommand::concreteCommand::concreteCommand(maitreD *md, Floor *f, customerFactory *cf, OrderFactory *of)
{
    this->floor = f;
    this->md = md;
    this->cf = cf;
    this->of = of;
}

concreteCommand::~concreteCommand()
{
    delete floor;
    delete md;
    delete cf;
}

Customer *concreteCommand::produceCustomer(char group)
{
    if (group == '!')
    {
        Customer *res = cf->getIndividualCustomer();
        seatCustomer(res);
        return res;
    }
    else
    {
        Customer *res = cf->getMultiCustomers(group);
        // seatCustomer(res);
        return res;
    }
}

void concreteCommand::seatCustomer(Customer *c)
{
    cout << "Would you like to reserve a table? " << endl;
    cout << "Y or N";
    cout << endl;
    char response;
    while (true) // loop until valid input is received
    {
        cin >> response;
        if (response == 'y' || response == 'Y' || response == 'n' || response == 'N')
            break; // exit the loop if valid input is received
        else
        {
            cout << "Invalid input. Please enter" << endl;
            cout << " Y or N: " << endl;
            cin.clear();                                         // clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard the rest of the line
        }
    }
    if (response == 'y' || response == 'Y')
    {
        int _x;
        int _y;
        cout << "Choose your location: " << endl;
        cout << "Row: 1, 2, 3, 4: " << endl;
        while (true) // loop until valid input is received
        {
            cin >> _x;
            if (_x >= 1 && _x <= 4)
                break; // exit the loop if valid input is received
            else
            {
                cout << "Invalid input.\nPlease enter a number between 1 and 4:\n";
                cin.clear();                                                   // clear the error flag on cin
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        }
        cout << "Isle: 1, 2, 3, 4: " << endl;
        while (true) // loop until valid input is received
        {
            cin >> _y;
            if (_y >= 1 && _y <= 4)
                break; // exit the loop if valid input is received
            else
            {
                cout << "Invalid input. \nPlease enter a number between 1 and 4:\n ";
                cin.clear();                                                   // clear the error flag on cin
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard the rest of the line
            }
        }
        c->makeReservation(_x - 1, _y - 1, md);
        md->seat(c);
    }
    else
    {
        cout << "The next available table will be allocated to you" << endl;
        pair<int, int> work = md->findNext();
        c->makeReservation(work.first, work.second, md);
        md->seat(c);
    }
}

void concreteCommand::seatMultipleCustomers(int x, int y, Customer *c)
{
    this->floor->getTable(x, y)->addCustomer(c);
}

pair<int, int> concreteCommand::reserveGroupTable()
{
    cout << "Would you like to reserve a table? " << endl;
    cout << "Y or N";
    cout << endl;
    char response;
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        int x;
        int y;
        cout << "Choose your location: " << endl;
        cout << "Row: 1, 2, 3, 4: " << endl;
        cin >> x;
        cout << "Isle: 1, 2, 3, 4: " << endl;
        cin >> y;
        x -= 1;
        y -= 1;
        if (md->reserve(x, y))
        {
            pair<int, int> result;
            result.first = x;
            result.second = y;
            return result;
        }
        else
        {
            cout << "Table not available" << endl;
            cout << "The next available table will allocated to you" << endl;
            pair<int, int> result = md->findNext();
            return result;
        }
    }
    else
    {
        cout << "The next available table will allocated to you" << endl;
        pair<int, int> result = md->findNext();
        return result;
    }
}

char concreteCommand::getGroupID()
{
    return this->cf->getGID();
}

char concreteCommand::setGroupID()
{
    this->cf->nextGroupID++;
}

void concreteCommand::startOrdering()
{
    int x;
    int y;
    cout << "Choose your location: " << endl;
    cout << "Row: 1, 2, 3, 4: " << endl;
    cin >> x;
    cout << "Isle: 1, 2, 3, 4: " << endl;
    cin >> y;
    x--;
    y--;
    char userChoice;
    do
    {
        this->floor->getTable(x, y)->order = this->of->getOrder(this->floor->getTable(x, y));
        cout << "Do you want to continue ordering? (y/n): ";
        cin >> userChoice;
    } while (userChoice == 'y' || userChoice == 'Y');
    this->floor->getTable(x, y)->placedOrder = true;
    this->floor->getTable(x, y)->bill = this->floor->getTable(x, y)->getBill();
    this->floor->getTable(x, y)->sendOrder(this->floor->getTable(x, y)->myWaiter);
    this->floor->getTable(x, y)->myWaiter->printOrders();
    this->floor->getTable(x, y)->askForTheCheque(this->floor->getTable(x, y)->myWaiter);
}