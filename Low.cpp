#include "Low.h"
#include <chrono>
#include <thread>
#include "Individual.h"
using namespace std;

Low::Low(int patience) : Satisfaction(patience)
{
    this->type = 'l';
    std::thread([this]()
                {
            while (this->patience > 0) {
                std::this_thread::sleep_for(std::chrono::seconds(10));
                this->patience -= 10;
              //  cout << this->patience << endl;
            } })
        .detach();
}

Low::~Low()
{
}

Satisfaction *Low::moodSwing()
{
    if (patience <= 0)
    {
        Low *l = new Low(this->patience);
        l->myIn = this->myIn;
        return l;
    }
}

int Low::tip()
{
    return 5;
}
