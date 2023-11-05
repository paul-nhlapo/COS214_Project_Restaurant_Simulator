#ifndef WAITER_H
#define WAITER_H

#include "Staff.h"
#include "Table.h"

class Waiter : public Staff{

    public:
        void visitTable(Table* table);
        void visitAllTable(std::vector<Table*>);

    private:
        

};
#endif