PATTERNS IN THESE FILES:
    -Factory (To create chefs)
    -Mediator (To allow chefs to share their state) -- KITCHEN
    -State (Chef's current state)
    -CoR (To pass an order object along chain of chefs)


NEED TO ADD:
    -Strategy Pattern
    -Builder Pattern (To create Meal Object)
    -Meal Class (An object of meal class will be passed to waiter once order is prepared)

    -Need to aggregate CHEF class with STAFF class (Chef inherits from Staff)
    
    
    -More thorough testing



CoR:
    - An Order Object comes in to the Head Chef
    - He will check the Order Type and then push it to the relevant queue (starter, main, dessert)
    - The secondary chefs will then notify the Head Chef via the KITCHEN MEDIATOR that their state is FREE and can receieve an order
    - When seeing this notification the Head Chef will pop the latest order from that Chef's queue and start the CoR
    - If the Order Type does not match the Chef Type it gets passed along the Chain
    
    NEEDS TO BE IMPLEMENTED:
        - When the correct chefs receieves the order his State will change to BUSY
        - He will then create a Meal Object
        - He will check the Head Chef's State via Mediator
        - If Head Chef is FREE he will pass the Meal Object to him to plate.
        - Head Chef plates and then passes Meal Object to waiter

    __END