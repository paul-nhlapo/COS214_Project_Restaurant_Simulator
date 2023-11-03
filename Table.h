#pragma once
#include "Customer.h"
#include "Staff.h"
// #include "Waiter.h"
#include <vector>
#include <memory>
#include <string>
using namespace std;

class Waiter;
class Table
{
private:
public:
    vector<Customer *> customers;
    // vector<Meal> Meals;
    int tableID;
    char tableGroup;
    // string tempOrder;
    bool hasCustomer;
    int customerTally;
    Table();
    ~Table();
    void addCustomer(Customer *c);
    // string getOrder();
    void assignWaiter(Waiter *w);
    void sendOrder(Waiter *w);
    int getSatisfaction();
};
