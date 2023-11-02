#pragma once
#include "Staff.h"
#include "Table.h"
#include <vector>
#include <iostream>
// class Table;

class Floor;
class Customer;
class maitreD : public Staff
{
private:
    /* data */
public:
    Floor *floor;
    maitreD(Floor *f);
    ~maitreD();
    void process(Table *t);
    void seat(Customer *c);
};
