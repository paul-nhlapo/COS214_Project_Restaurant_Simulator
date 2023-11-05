#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "PaymentMethod.h"

// The 'Context' class
class Customer
{
private:
    PaymentMethod *paymentMethod; // pointer to hold the current payment method
public:
    Customer(PaymentMethod *paymentMethod);
    void setPaymentMethod(PaymentMethod *paymentMethod); // Function to change the payment method
    void makePayment(int amount);                        // Function to make a payment using the current payment method
};

#endif // CUSTOMER_H
