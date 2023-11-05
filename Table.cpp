#include "Table.h"

Table::Table(int tn){
    tableNumber = tn;
}

void Table::accept(Staff* visitor){
    visitor->visitTable(this);
}

void Table::accept(Staff* visitor, std::vector<Table*> vect){
    visitor->visitAllTable(vect);
}

int Table::getTableNumber(){
    return tableNumber;
}