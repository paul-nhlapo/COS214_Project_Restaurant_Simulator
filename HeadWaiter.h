#ifndef HEADWAITER_H
#define HEADWAITER_H

#include "Staff.h"
#include "Table.h"

class HeadWaiter : public Staff{

    public:
        void visitTable(Table* table);
        void visitAllTable(std::vector<Table*>);

    private:
        

};
#endif