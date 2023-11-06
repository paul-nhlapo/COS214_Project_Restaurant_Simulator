#include "Satisfaction.h"
using namespace std;

Satisfaction::Satisfaction(int patience)
{
    this->patience = patience;
    this->myIn = myIn;
}

Satisfaction::~Satisfaction()
{
}

void Satisfaction::setIndividual(Individual *i)
{
    this->myIn = i;
}