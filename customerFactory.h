#pragma once
#include "Factory.h"
#include "Customer.h"
#include "Individual.h"
using namespace std;

class customerFactory : public Factory
{
private:
    int current;
    Satisfaction *s;

public:
    char nextGroupID;
    customerFactory();
    ~customerFactory();
    Customer *getIndividualCustomer();
    Customer *getMultiCustomers(char group);
    void createProduct();
    char getGID();
};
