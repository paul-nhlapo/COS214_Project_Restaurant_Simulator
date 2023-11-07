#include "Individual.h"
#include <string>
#include <vector>
using namespace std;

Individual::Individual()
{
    this->s = new High(100);
    this->s->myIn = this;
    cID = -1;
}

Individual::Individual(int cID, Satisfaction *s)
{
    this->s = s;
    this->s->myIn = this;
    this->cID = cID;
}

Individual::~Individual()
{
    delete this->s;
}