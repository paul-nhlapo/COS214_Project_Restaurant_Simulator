/**
    * @brief pay function that implements the payment method using a credit card
    * 
    * @param amount the amount to be paid
    */
#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "PaymentMethod.h"

// A 'ConcreteStrategy' class
class CreditCard : public PaymentMethod
{
public:
    void pay(int amount);
};

#endif // CREDITCARD_H
