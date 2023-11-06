/*  
    Chef Interface class
    - All chefs inherit from this class
    - Is the:
        - ChefHandler in CoR
        - Context in State and Strategy
        - Product in Factory
*/
#ifndef CHEF_H
#define CHEF_H

#include <iostream>
#include "SimpleOrder.h"
#include "Staff.h"
class ChefState;
class Kitchen;
class CookingStrategy;
class Order_;

class Chef : public Staff
{
    public:
        Chef(std::string name, Kitchen* kitchen);
        virtual ~Chef() {};

        virtual std::string getChefType() = 0;                          //Return ChefType (Head, Starter, Main, Dessert)
        virtual void receiveOrder() = 0;                                //Set STATE to FREE to indicate they are able to receive a new order
        virtual void sendOrder() = 0;                                   //Send order to Head Chef to plate IF Head Chef's STATE is FREE

        //virtual void prepareMeal(std::string mealType);               //CoR HANDLE method
        virtual void prepareMeal(Order_* order);
        virtual void setNextChef(Chef* nextChef) = 0;                   //CoR setNext method
        virtual Chef* getNextChef() = 0; 

        virtual void setChefState(ChefState* chefState);                //Set new Chef State
        virtual void changeChefState();                                 //Change Chef State
        virtual std::string getCurrentState();                          //Get Current State

        virtual void receiveNotification(Staff* senderChef) = 0;         //Recieve Notification that another Chef has changed its STATE                   
                                                                        //Each Chef must implement it differently

        virtual void addOrderToQueue(Order_* order) {};

        virtual void process(Table *t) {};


    protected:
        std::string name;
        std::string chefType;
        Chef* nextChef;                                                //CoR
        ChefState* currentState;                                       //State
        Kitchen* kitchen;                                              //Mediator
        CookingStrategy* cookingStrategy;                                         //Strategy
};

#endif