![Screenshot (226)](https://github.com/BananaFish45/COS214_Project/assets/86393854/a996b8ac-2619-43e8-b5ad-463783617fdd)

# Restaurant Simulator

A restaurant is a chaotic ensemble of various processes happening at the same time (Multithreading is not required)
to result in the production and sale of food to customers. These processes can be small, from being seated at a table,
to massive processes such as the cooking of food at various workstations and being passed between chefs.
For the purpose of this assignment we will be dealing primarily with two distinct areas, the floor and the kitchen,
of the restaurant and how they must communicate.

## 5.1 The floor
The floor will be where customers are seated and managed. Here we will have some system for a customer to
request to be seated and if available given a table, this system mimics a Maitre D showing you to the table.
Thereafter a waiter will come over and take your order. If the customer is not ready to order they may ask the
waiter to come back after a while. When a customer places an order the waiter must pass it to the kitchen and
then when the kitchen has prepared the order the waiter must return the order to the table.
At the end of the dinner a bill must be presented to the table and by request a bill may be split into sub-bills so
that more than one payment may be made from various parties at the table.
Tables will also be managed by floor staff as tables can combined or split to be able to fit various sized parties.
The restaurant may have a booking system or walk in based service. Every waiter will have tables assigned to
them that they will take responsibility for.
Importantly customer expectations need to be managed. If the customer is happy, they may tip more. However if
we make a customer unhappy they might make a complaint.
The restaurant is a ”Build-Your-Own-” restaurant meaning a customer will have the ability to create an order out
of a list of available options and may ask for specific methods of preparation (grilled vs fried for example).
Seeing as we want to present as a classy establishment we may allow a customer to start a Tab where they will
only pay for a bill at a later date.

## 5.2 The kitchen
The kitchen is where most of the chaos and inter operation comes into effect.
An order must be passed by a waiter to the kitchen who will then take orders as they come and start producing
them. Different chefs will be responsible for different parts of the preparation process, for example the head chef
finishes plates while the fry cook will always work at the fryer.
A dish may be passed between various stations before returning to the head chef to complete the plating before it
can be sent to a customer via the waiter.
Whenever an order is completed the kitchen will notify the waiter that they can come and collect the order to
take it to the table
