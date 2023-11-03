#pragma once
#include "Individual.h"
using namespace std;

class maitreD;
class Customer : public Individual
{
private:
public:
    int tableNumber;
    bool hasReservation;
    int rX;
    int rY;
    Customer();
    Customer(int cID, Satisfaction *s);
    //~Customer();
    int tip();
    void setTableNo(int tN);
    int getTableNo();
    void makeReservation(int x, int y, maitreD* md);
};
