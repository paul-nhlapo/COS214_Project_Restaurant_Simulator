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

class ChefState;                                                        //Forward declaration of ChefState for STATE DP

class Chef
{
    public:
        Chef(std::string name);
        virtual ~Chef() {};

        virtual std::string getChefType() = 0;                          //Return ChefType (Head, Starter, Main, Dessert)
        virtual void receiveOrder() = 0;                                //Set STATE to FREE to indicate they are able to receive a new order
        virtual void sendOrder() = 0;                                   //Send order to Head Chef to plate IF Head Chef's STATE is FREE

        virtual void prepareMeal(std::string mealType);                 //CoR HANDLE method
        virtual void setNextChef(Chef* nextChef) = 0;                   //CoR setNext method

        //virtual void setChefState(ChefState* chefState) = 0;


    protected:
        std::string name;
        std::string chefType;
        Chef* nextChef;                                                //CoR
        ChefState* currentState;                                       //State
};

#endif