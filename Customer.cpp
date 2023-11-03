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
}

Customer::Customer(int cID, Satisfaction *s) : Individual(cID, s)
{
    hasReservation = false;
    tableNumber = -1;
}

// Customer::~Customer()
// {
// }

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

void Customer::makeReservation(int x, int y, maitreD* md)
{
    if(md->floor->getTable(x,y)->hasCustomer)
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
