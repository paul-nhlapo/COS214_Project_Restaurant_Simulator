#pragma once
#include <iostream>
#include "Waiter.h"
#include "Table.h"

class Floor
{
private:
public:
    Table **tables;
    int numRows;
    int numCols;

    Floor(int numRows, int numCols);
    ~Floor();
    Table *getTable(int row, int col);
    void printFloor();
    void options();
};
