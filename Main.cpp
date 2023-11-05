#include "Cash.h"
#include "CreditCard.h"
#include "Customer.h"

int main()
{
    // Create payment method objects
    Cash cash;
    CreditCard creditCard;

    // Create a Customer object with initial payment method as 'Cash'
    Customer customer(&cash);

    // Test the current payment method
    customer.makePayment(200);

    // Change payment method to 'CreditCard'
    customer.setPaymentMethod(&creditCard);
    customer.makePayment(100);

    return 0;
}
