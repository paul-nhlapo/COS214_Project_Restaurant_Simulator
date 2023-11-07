/**
 * @brief pay function that implements the payment method using a Cash
 *
 * @param amount the amount to be paid
 */
#ifndef CASH_H
#define CASH_H

#include "PaymentMethod.h"

// A 'ConcreteStrategy' class
class Cash : public PaymentMethod
{
public:
    void pay(int amount);
};

#endif // CASH_H
