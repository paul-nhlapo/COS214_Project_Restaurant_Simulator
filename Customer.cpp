#include "Customer.h"

// Constructor that initializes the payment method of the customer
Customer::Customer(PaymentMethod *paymentMethod) : paymentMethod(paymentMethod) {}

// Setter method to set the payment method of the customer
void Customer::setPaymentMethod(PaymentMethod *paymentMethod)
{
    this->paymentMethod = paymentMethod;
}

// Method that makes a payment using the customer's payment method
void Customer::makePayment(int amount)
{
    
    paymentMethod->pay(amount);
}

// Destructor that deletes the payment method of the customer
// Customer::~Customer()
// {
//     delete paymentMethod;
// }