#pragma once
#include "Factory.h"
#include "Customer.h"
#include "Individual.h"
using namespace std;

class customerFactory:public Factory
{
private:
    int current;
    Satisfaction *s;

public:
    customerFactory();
    ~customerFactory();
    Customer *getCustomer();
    void createProduct();
};

