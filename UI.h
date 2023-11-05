#ifndef UI_H
#define UI_H

#include "Waiter.h"
#include "HeadWaiter.h"
#include "Table.h"

class UI {
public:
    void placeOrder(Table* table, Waiter* waiter) {
        table->accept(waiter);
    }
    void visitAll(Table* table, std::vector<Table*> vect, HeadWaiter* hw) {
        table->accept(hw);
    }
};

#endif