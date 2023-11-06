#ifndef WAITER_H
#define WAITER_H

#include "Staff.h"
#include "Table.h"

class Waiter : public Staff
{

public:
    vector<Table *> tables;
    vector<Order_ *> orders;
    double balance;

    Waiter();
    void process(Table *t);
    void visitTable(Table *table);
    void visitAllTable(std::vector<Table *>);
    void printOrders();
    void receiveBill(Table *table);

private:
};
#endif