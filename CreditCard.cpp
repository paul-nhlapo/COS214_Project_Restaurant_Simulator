#include "CreditCard.h"
#include <iostream>

void CreditCard::pay(int amount)
{
    if (amount == 0 || amount < 0)
    {
        std::cout << "Card declined.\n";
        return;
    }
    else if (amount > 0)
        std::cout << "Paid " << amount << " using credit card.\n";
    else
        std::cout << "Try another card or try another payment method.\n";
}
