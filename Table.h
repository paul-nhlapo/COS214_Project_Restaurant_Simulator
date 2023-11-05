#ifndef TABLE_H
#define TABLE_H

#include "Staff.h"
class Staff;
class Table{

    public:
        Table(int tn);
        void accept(Staff* visitor);
        void accept(Staff* visitor, std::vector<Table*> vect);
        int getTableNumber();

    private:
        int tableNumber;

};
#endif