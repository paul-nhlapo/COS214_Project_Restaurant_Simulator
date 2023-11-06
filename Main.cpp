#include "Floor.h"
#include "Table.h"
#include "Waiter.h"
#include "Manager.h"
#include "maitreD.h"
#include "Factory.h"
#include "customerFactory.h"
#include "Command.h"
#include "concreteCommand.h"
#include "UI.h"
#include <iostream>
#include <memory>
#include <Satisfaction.h>
#include <High.h>
#include <Medium.h>
#include <Low.h>
#include "OrderFactory.h"
#include "Order.h"
// #include "PaymentMethod.h"
// #include "Cash.cpp"
#include "CreditCard.h"
// #include "MainOrder.cpp"
// #include "BasicOrder.h"
// #include "OrderDetail.h"
// #include "ProteinDecorator.cpp"
// #include "SauceDecorator.cpp"
// #include "SideDecorator.cpp"
// #include "StarterDecorator.cpp"
// #include "VegDecorator.cpp"
// #include "DessertDecorator.cpp"

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
    OrderFactory *of1 = new OrderFactory();

    f1->printFloor();
    // Customer* c1 = cf1->getIndividualCustomer();
    // cout << c1->cID << endl;

    concreteCommand *command1 = new concreteCommand(md1, f1, cf1, of1);
    // Customer* c2 = command1->produceCustomer('!');
    UI *inter = new UI(command1, f1);
    inter->additionLoop();

    cout << endl;
    //  << endl
    //  << "Bill: " << f1->getTable(0, 0)->bill << endl;
    // inter->addCustomer();
    // f1->printFloor();

    // inter->addCustomer();
    // f1->printFloor();
    // m1->monitor();
    //  Waiter *w1 = new Waiter();
    //  f1->tables[0][0].assignWaiter(w1);
    //  f1->tables[2][2].assignWaiter(w1);
    //  w1->printOrders();

    // Manager *m1 = new Manager(f1);
    // cout << m1->monitor() << endl;
    return 0;
}