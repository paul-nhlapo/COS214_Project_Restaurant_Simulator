#include "High.h"
#include "Medium.h"
#include "Individual.h"
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

High::High(int patience) : Satisfaction(patience)
{
    this->type = 'h';
    std::thread([this]()
                {
            while (this->patience >= 700) {
                std::this_thread::sleep_for(std::chrono::seconds(10));
                this->patience -= 60;
                //cout << this->patience << endl;;
                if(this->patience < 700)
                {
cout << "\033[1;33mCustomer " << this->myIn->cID << " is now moderately happy\033[0m" << endl;                    this->myIn->s = moodSwing();
                }
            } })
        .detach();
}

High::~High()
{
}

Satisfaction *High::moodSwing()
{
    Medium *ns = new Medium(this->patience);
    ns->myIn = this->myIn;
    return ns;
}

int High::tip()
{
    return 50;
}
