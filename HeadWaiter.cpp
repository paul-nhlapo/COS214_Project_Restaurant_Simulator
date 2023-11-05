#include "HeadWaiter.h"
#include <iostream>

void HeadWaiter::visitTable(Table* table){
    std::cout << "head waiter visiting table : " << table->getTableNumber() << "\n";
}

void HeadWaiter::visitAllTable(std::vector<Table*> vect){
    for (auto table : vect) {
        std::cout << "Head waiter visiting all tables: " << table->getTableNumber() << "\n";
    }
}