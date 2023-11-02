#pragma once
// #include "Table.h"
class Table;
class Staff
{
private:
    /* data */
public:
    Staff(/* args */);
    virtual ~Staff();
    virtual void process(Table *t) = 0;
};
