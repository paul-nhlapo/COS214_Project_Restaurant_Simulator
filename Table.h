#pragma once
#include "Customer.h"
#include "Staff.h"
// #include "Waiter.h"
#include <vector>
#include <memory>
#include <string>
#include "Order.h"
#include "MainOrder.h"
#include "BasicOrder.h"
#include "OrderDetail.h"
#include "PaymentMethod.h"
#include "Cash.h"
#include "CreditCard.h"
using namespace std;

class Waiter;
class Table
{
private:
public:
    Waiter *myWaiter;
    vector<Customer *> customers;
    vector<Order_ *> order;
    // vector<Meal> Meals;
    int tableID;
    char tableGroup;
    // string tempOrder;
    bool hasCustomer;
    bool placedOrder;
    int customerTally;
    double bill;
    PaymentMethod *paymentMethod;
    int mainCount;
    int starterCount;
    int dessertCount;

    Table();
    ~Table();
    void addCustomer(Customer *c);
    // string getOrder();
    void assignWaiter(Waiter *w);
    // void sendOrder(Waiter *w);
    double getSatisfaction();
    double getTip();
    void printOrders();
    void sendOrder(Waiter *visitor);
    void setWaiter(Waiter *w);
    double getBill();
    void setPaymentMethod(PaymentMethod *paymentMethod);
    void makePayment(double amount);
    void payTheBill(Waiter *visitor);
    void askForTheCheque(Waiter *visitor);
};
