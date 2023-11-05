#include "Cash.h"
#include <iostream>

void Cash::pay(int amount)
{
    if (amount == 0 || amount < 0)
    {
        std::cout << "Invalid amount.\n";
    }
    else if (amount > 0)
        std::cout << "Paid " << amount << " using cash.\n";
        else
            std::cout << "Try using another payment method.\n";
}
