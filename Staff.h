#pragma once
// #include "Table.h"
#include "Order.h"
class Table;
class Staff
{
private:
    /* data */
public:
    Staff(/* args */);
    virtual ~Staff();
    virtual void process(Table *t) = 0;
    virtual void visitTable(Table *table) = 0;
};
