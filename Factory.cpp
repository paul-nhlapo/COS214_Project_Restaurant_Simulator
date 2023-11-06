#include "Factory.h"
#include <string>
#include <vector>
using namespace std;

Factory::Factory()
{
}

Factory::~Factory()
{
}

Customer* Factory::getCustomer()
{
    return this->c;
}
