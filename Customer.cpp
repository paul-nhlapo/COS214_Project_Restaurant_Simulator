#include "Customer.h"
#include "maitreD.h"
#include "Floor.h"
#include <string>
#include <vector>
using namespace std;

Customer::Customer() : Individual()
{
    hasReservation = false;
    tableNumber = -1;
    rX = -1;
    rY = -1;
    groupID = '!';
    hasGroup = false;
    hasReservation = false;
}

Customer::Customer(int cID, char groupID, bool hG, Satisfaction *s) : Individual(cID, s)
{
    tableNumber = -1;
    this->groupID = groupID;
    hasGroup = hG;
}

Customer::~Customer()
{
}

int Customer::tip()
{
    s->tip();
}

void Customer::setTableNo(int tN)
{
    this->tableNumber = tN;
}

int Customer::getTableNo()
{
    return this->tableNumber;
}

void Customer::makeReservation(int x, int y, maitreD *md)
{
    if (md->floor->getTable(x, y)->hasCustomer)
    {
        cout << "Table not available" << endl;
    }
    else
    {
        rX = x;
        rY = y;
        hasReservation = true;
    }
}
