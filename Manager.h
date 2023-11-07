#pragma once
#include "Floor.h"
#include "Table.h"
#include "Staff.h"
using namespace std;

class Manager : public Staff
{
private:
    Floor *f;

public:
    float result;
    int present;
    Manager(/* args */);
    Manager(Floor *f);
    ~Manager();
    float monitor();
    void process(Table *t);
    void visitTable(Table *table);
    void receiveNotification(Staff *senderChef){};
};
