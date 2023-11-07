#include "Medium.h"
#include "Low.h"
#include "Individual.h"
#include <chrono>
#include <thread>
using namespace std;

Medium::Medium(int patience) : Satisfaction(patience)
{
    this->type = 'm';
    std::thread([this]()
                {
            while (this->patience >= 400) {
                std::this_thread::sleep_for(std::chrono::seconds(10));
                this->patience -= 50;
                                //cout << this->patience << endl;

                if(this->patience < 400)
                {
cout << "\033[1;31mCustomer " << this->myIn->cID << " is now unhappy\033[0m" << endl;                    this->myIn->s = moodSwing();
                }
            } })
        .detach();
}
Medium::~Medium()
{
}

Satisfaction *Medium::moodSwing()
{

    Low *l = new Low(this->patience);
    l->myIn = this->myIn;
    return l;
}

int Medium::tip()
{
    return 20;
}
