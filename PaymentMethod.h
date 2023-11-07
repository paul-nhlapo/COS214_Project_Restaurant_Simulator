#ifndef PAYMENTMETHOD_H
#define PAYMENTMETHOD_H

// The 'Strategy' abstract class
class PaymentMethod
{
public:
    virtual void pay(int amount) = 0;
};

#endif // PAYMENTMETHOD_H
