#include "Waiter.h"
#include <iostream>

void Waiter::visitTable(Table* table){
    std::cout << "taking order at table : " << table->getTableNumber() << "\n";
}

void Waiter::visitAllTable(std::vector<Table*> table){
    std::cout << "floor waiter cant visit all tables, not a head waiter\n";
}