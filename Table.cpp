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
    this->placedOrder = false;
    this->bill = 0;
    this->mainCount = 0;
    this->starterCount = 0;
    this->dessertCount = 0;
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

// void Table::sendOrder(Waiter *w)
// {
//     w->process(this);
// }

double Table::getSatisfaction()
{
    int totalSatisfaction = 0;
    for (const auto &customer : customers)
    {
        totalSatisfaction += customer->s->patience;
    }
    return totalSatisfaction / this->customerTally;
}

double Table::getTip()
{
    int totalTip = 0;
    for (const auto &customer : customers)
    {
        totalTip += customer->s->tip();
    }
    return (double)totalTip;
}

void Table::printOrders()
{
    cout << "Table's orders:" << endl;
    for (Order_ *order : order)
    {
        cout << "Main Element: " << order->mainElement << " mainPrepStrategy:  " << order->mainPrepStrategy << " sauceChoice: " << order->sauceElement << " sidesChoice: " << order->sidesElement << endl;
    }
}

void Table::sendOrder(Waiter *visitor)
{
    visitor->visitTable(this);
}

void Table::setWaiter(Waiter *w)
{
    this->myWaiter = w;
}

double Table::getBill()
{
    double totalCost = 0.0;
    totalCost += this->starterCount * 50.0;
    totalCost += this->mainCount * 100.0;
    totalCost += this->dessertCount * 75.0;
    return totalCost;
}

void Table::setPaymentMethod(PaymentMethod *paymentMethod)
{
    this->paymentMethod = paymentMethod;
}

void Table::makePayment(double amount)
{
    paymentMethod->pay(amount);
}

void Table::askForTheCheque(Waiter *visitor)
{
    visitor->receiveBill(this);
}

void Table::payTheBill(Waiter *visitor)
{
    cout << "How will you be paying? " << endl;
    cout << "1. Cash" << endl;
    cout << "2. Credit Card" << endl;

    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
        setPaymentMethod(new Cash());
        break;
    case 2:
        setPaymentMethod(new CreditCard());
        break;
    default:
        setPaymentMethod(new Cash());
        break;
    }
    double tip = getTip();
    cout << "Your customers have tipped you R" << tip << endl
         << endl;

    this->bill += tip;
    this->bill += getBill();
    if (customerTally > 1)
    {
        cout << "Would you like to split the bill? " << endl;
        cout << "1. Yes" << endl;
        cout << "2. No" << endl;
        int choice1;
        double divided = 0.0;
        cin >> choice1;

        switch (choice1)
        {
        case 1:
            divided = this->bill / customerTally;
            for (int i = 0; i < customerTally; i++)
            {
                this->makePayment(divided);
                this->bill -= divided;
                visitor->balance += divided;
            }
            break;
        case 2:
            this->makePayment(this->bill);
            this->bill -= this->bill;
            visitor->balance += this->bill;
            break;
        default:
            this->makePayment(this->bill);
            this->bill -= this->bill;
            visitor->balance += this->bill;
            break;
        }
    }
    else
    {
        this->makePayment(this->bill);
        this->bill -= this->bill;
        visitor->balance += this->bill;
    }
}
