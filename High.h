#pragma once
#include "Satisfaction.h"
#include "Individual.h"
using namespace std;

class High : public Satisfaction
{
private:
public:
    High(int patience);
    ~High();
    Satisfaction *moodSwing();
    int tip();
};
