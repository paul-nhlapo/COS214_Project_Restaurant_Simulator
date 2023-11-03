#include "High.h"
#include "Medium.h"
#include <chrono>
#include <thread>
using namespace std;

High::High(/* args */) : Satisfaction()
{
    // thread([this]()
    //        {
    //     while (true) {
    //         this_thread::sleep_for(chrono::seconds(10));
    //         patience -= 10;
    //     } })
    //     .detach();
    // moodSwing();
}

High::~High()
{
}

Satisfaction *High::moodSwing()
{
    if (patience < 70)
    {
        return new Medium();
    }
}

int High::tip()
{
    return 50;
}
