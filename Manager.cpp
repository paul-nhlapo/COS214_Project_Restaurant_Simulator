#include "Manager.h"
using namespace std;

Manager::Manager(/* args */)
{
    this->f = nullptr;
    this->present = 0;
}

Manager::Manager(Floor *f)
{
    if (f != nullptr)
    {
        this->f = f;
        this->present = 0;
    }
    else
    {
        cout << "Invalid parameters" << endl;
    }
}

Manager::~Manager()
{
}

float Manager::monitor()
{
    for (int i = 0; i < f->numRows; i++)
    {
        for (int j = 0; j < f->numCols; j++)
        {
            // if (f->getTable(i, j)->getSatisfaction() != 0)
            // {

            cout << this->f->getTable(i, j)->tableID << " ";
            // this->result += f->getTable(i, j)->getSatisfaction();
            // this->present++;
            // }
        }
        cout << endl;
    }
    return 0.0;
    // return this->result / this->present;
}

void Manager::process(Table *t)
{
}

void Manager::visitTable(Table *table)
{
}
