#include "concreteCommand.h"
#include <string>
#include <vector>
using namespace std;

concreteCommand::concreteCommand::concreteCommand(maitreD *md, Floor *f, customerFactory *cf)
{
    this->floor = f;
    this->md = md;
    this->cf = cf;
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
    cin >> response;
    if (response == 'y' || response == 'Y')
    {
        int _x;
        int _y;
        cout << "Choose your location: " << endl;
        cout << "Row: 1, 2, 3, 4: " << endl;
        cin >> _x;
        cout << "Isle: 1, 2, 3, 4: " << endl;
        cin >> _y;
        c->makeReservation(_x - 1, _y - 1, md);
        cout << "The next available table will be allocated to you" << endl;
        md->seat(c);
    }
    else
    {
        cout << "The next available table will be allocated to you" << endl;
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
