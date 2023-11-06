#include "Floor.h"
#include "Table.h"
#include "Waiter.h"
#include "Manager.h"
#include <iostream>
#include <memory>

int main()
{
    Floor *f1 = new Floor(4, 4);
    // Customer *c1 = new Customer(1);
    // Customer *c2 = new Customer(2);
    // c2->s->patience = 56;
    // c2->s->moodSwing();

    int ids = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            f1->tables[i][j].tableID = ids;
            ids++;
        }
    }
    // f1->tables[0][0].addCustomer(c1);
    // f1->tables[2][2].addCustomer(c2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!f1->tables[i][j].hasCustomer)
            {
                cout << "|" << f1->tables[i][j].tableID << "| ";
            }
            else
            {
                cout << "|" << f1->tables[i][j].tableID << "[C]| ";
            }
        }
        cout << endl;
    }

    // Waiter *w1 = new Waiter();
    // f1->tables[0][0].assignWaiter(w1);
    // f1->tables[2][2].assignWaiter(w1);
    // w1->printOrders();

    // Manager *m1 = new Manager(f1);
    // cout << m1->monitor() << endl;
    return 0;
}