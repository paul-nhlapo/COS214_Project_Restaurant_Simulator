#include "maitreD.h"
#include "Floor.h"
#include "Customer.h"
#include <string>
using namespace std;

maitreD::maitreD(Floor *f)
{
    this->floor = f;
}

maitreD::~maitreD()
{
}

void maitreD::process(Table *t)
{
}

void maitreD::seat(Customer *c)
{
    if (c->hasReservation)
    {
        this->floor->getTable(c->rX, c->rY)->addCustomer(c);
    }
    else
    {
        for (int i = 0; i < this->floor->numRows; i++)
        {
            for (int j = 0; j < this->floor->numCols; j++)
            {
                if (!this->floor->getTable(i, j)->hasCustomer)
                {
                    this->floor->getTable(i, j)->addCustomer(c);
                    return;
                }
                else
                {
                    if (this->floor->getTable(i, j)->tableGroup == c->groupID)
                    {
                        this->floor->getTable(i, j)->addCustomer(c);
                        return;
                    }
                }
            }
        }
    }
}

void maitreD::seatGroup(vector<Customer *> vc)
{

    for (Customer *customer : vc)
    {
        seat(customer);
    }
    vc.clear();
}

pair<int, int> maitreD::findNext()
{
    for (int i = 0; i < this->floor->numRows; i++)
    {
        for (int j = 0; j < this->floor->numCols; j++)
        {
            if (!this->floor->getTable(i, j)->hasCustomer)
            {
                pair<int, int> res;
                res.first = i;
                res.second = j;
                return res;
            }
        }
    }
}

bool maitreD::reserve(int x, int y)
{
    if (floor->getTable(x, y)->hasCustomer)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void maitreD::visitTable(Table *table)
{
}
