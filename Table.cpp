#include "Table.h"
#include <string>
#include <vector>
#include "Waiter.h"
using namespace std;

Table::Table()
{
    // this->tempOrder = "";
    this->hasCustomer = false;
    this->customerTally = 0;
    vector<Customer *> customers;
}

Table::~Table()
{
}

void Table::addCustomer(Customer *c)
{
    this->customerTally++;
    customers.push_back(c);
    c->tableNumber = tableID;
    this->hasCustomer = true;
    this->tableGroup = c->groupID;
}

// string Table::getOrder()
// {
//     return this->tempOrder;
// }

void Table::assignWaiter(Waiter *w)
{
    w->tables.push_back(this);
}

void Table::sendOrder(Waiter *w)
{
    w->process(this);
}

int Table::getSatisfaction()
{
    int totalSatisfaction = 0;
    for (const auto &customer : customers)
    {
        totalSatisfaction += customer->s->patience;
    }
    return totalSatisfaction;
}
