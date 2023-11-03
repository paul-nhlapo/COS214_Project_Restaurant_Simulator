#pragma once
#include "Customer.h"
#include "Individual.h"
using namespace std;

class Factory
{
private:
public:
    Factory();
    ~Factory();
    Customer *getCustomer();
    virtual void createProduct() = 0;

protected:
    Customer *c;
};
