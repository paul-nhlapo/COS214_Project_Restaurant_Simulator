#ifndef STAFF_H
#define STAFF_H

#include "Table.h"
#include <vector>

class Staff{

    public:
        virtual void visitTable(Table* table) = 0;
        virtual void visitAllTable(std::vector<Table*>) = 0;

    private:
        

};
#endif