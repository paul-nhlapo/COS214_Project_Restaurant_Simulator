
#include <iostream>
#include "UI.h"
#include "Staff.h"
#include "Table.h"
#include "Waiter.h"
#include "HeadWaiter.h"

#include "Table.cpp"
#include "Waiter.cpp"
#include "HeadWaiter.cpp"


int main() {
    UI ui;
    Table* table1 = new Table(1);
    Table* table2 = new Table(2);
    Waiter* waiter1 = new Waiter();
    HeadWaiter* head1 = new HeadWaiter();

    std::vector<Table*> allTables = {table1 , table2};

    ui.placeOrder(table1, waiter1);
    ui.placeOrder(table2, waiter1);
    ui.visitAll(table1, allTables, head1);

    delete table1;
    delete table2;
    delete waiter1;
    delete head1;

    return 0;
}
