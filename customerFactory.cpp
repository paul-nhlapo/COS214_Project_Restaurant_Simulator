#include "customerFactory.h"
#include <string>
#include <vector>
using namespace std;

customerFactory::

    customerFactory::customerFactory()
{
    this->current = 0;
    this->s = new High();
    this->c = new Customer(current, s);
}

customerFactory::~customerFactory()
{
    delete this->c;
}

void customerFactory::createProduct()
{
    return;
}

Customer *customerFactory::getCustomer()
{
    Customer *res = new Customer(current, s);
    current++;
    return res;
}