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
            }
        }
    }
}