#include "customerFactory.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

customerFactory::customerFactory::customerFactory()
{
    this->current = 0;
    this->s = new High(1000);
    this->c = new Customer(current, '!', false, this->s);
    this->nextGroupID = 'A';
}

customerFactory::~customerFactory()
{
    delete this->c;
}

void customerFactory::createProduct()
{
    return;
}

Customer *customerFactory::getIndividualCustomer()
{
    Customer *res = new Customer(current, '!', false, s);
    current++;

    return res;
}

Customer *customerFactory::getMultiCustomers(char group)
{
    Customer *res = new Customer(current, group, true, s);
    return res;
}

char customerFactory::getGID()
{
    return this->nextGroupID;
}
