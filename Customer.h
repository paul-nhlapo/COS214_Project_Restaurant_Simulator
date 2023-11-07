#pragma once
#include "Individual.h"
#include "PaymentMethod.h"

using namespace std;

class maitreD;
class Customer : public Individual
{
private:
public:
    char groupID;
    int tableNumber;
    bool hasReservation;
    bool hasGroup;
    int rX;
    int rY;

    Customer();
    Customer(int cID, char groupID, bool hG, Satisfaction *s);
    ~Customer();
    int tip();
    void setTableNo(int tN);
    int getTableNo();
    void makeReservation(int x, int y, maitreD *md);
};
