#pragma once
using namespace std;
class Satisfaction
{
private:
    /* data */
public:
    int patience = 100;
    Satisfaction(/* args */);
    ~Satisfaction();
    virtual Satisfaction* moodSwing() = 0;
    virtual int tip() = 0;
};


