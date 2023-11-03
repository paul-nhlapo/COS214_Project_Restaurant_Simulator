#include "Floor.h"
#include "Table.h"
#include "Waiter.h"
#include "Manager.h"
#include "maitreD.h"
#include "Factory.h"
#include "customerFactory.h"
#include <iostream>
#include <memory>

int main()
{
    Floor *f1 = new Floor(4, 4);
    Floor *f2 = new Floor(-1, 900);
    Floor *f3 = new Floor(2, 9000);
    delete f2;
    delete f3;

    Manager *m1 = new Manager(f1);
    maitreD *md1 = new maitreD(f1);
    customerFactory *cf1 = new customerFactory();

    vector<Customer *> cv;
    Customer *c1 = cf1->getCustomer();
    cv.push_back(c1);

    Customer *c2 = cf1->getCustomer();
    cv.push_back(c2);

    Customer *c3 = cf1->getCustomer();
    cv.push_back(c3);

    Customer *c4 = cf1->getCustomer();
    cv.push_back(c4);

    Customer *c5 = cf1->getCustomer();
    cv.push_back(c5);

    for (const auto &customer : cv)
    {
        cout << "Customer ID: " << customer->cID << '\n';
    }

    f1->printFloor();
    cout << endl;

    md1->seat(c1);
    f1->printFloor();
    cout << endl;

    md1->seat(c2);
    f1->printFloor();
    cout << endl;

    c3->makeReservation(0, 1, md1);
    md1->seat(c3);
    f1->printFloor();
    cout << endl;

    c4->makeReservation(3, 3, md1);
    f1->printFloor();
    cout << endl;

    md1->seat(c4);
    f1->printFloor();
    cout << endl;

    md1->seat(c5);
    f1->printFloor();
    cout << endl;

    // m1->monitor();
    //  Waiter *w1 = new Waiter();
    //  f1->tables[0][0].assignWaiter(w1);
    //  f1->tables[2][2].assignWaiter(w1);
    //  w1->printOrders();

    // Manager *m1 = new Manager(f1);
    // cout << m1->monitor() << endl;
    return 0;
}