#ifndef MEALPRODUCT_H
#define MEALPRODUCT_H

#include <iostream>
#include "Order.h"

class Meal
{
    public:
        Meal();
        virtual ~Meal() {};
        
        // virtual std::string getMainElement();
        // virtual std::string getCookingStrategy();
        // virtual std::string getSide();
        // virtual std::string getSauce();
        // virtual std::string printMeal();
        // virtual int getTableNumber();
        // virtual std::string getMealType();

        virtual void setMealType(std::string);
        virtual void setMainElement(std::string mainElement);
        virtual void setMainPrepStrategy(std::string mainPrepStrategy);
        virtual void setSideChoice(std::string sideChoice);
        virtual void setSideElement(std::string side);
        virtual void setSauceChoice(std::string sauceChoice);
        virtual void setSauceElement(std::string sauce);

        std::string getMealType();
        std::string getMainElement();
        std::string getMainPrepStrategy();
        char getSideChoice();
        std::string getSidePrepStrategy();
        std::string getSidesElement();
        char getSauceChoice();
        std::string getSauceElement();

    protected:
        // std::string mainElement;
        // std::string side;
        // std::string sauce;
        // std::string cookingStrategy;
        // int tableNumber;
        // std::string mealType;

        std::string mealType;
        std::string mainElement;
        std::string mainPrepStrategy;
        std::string sidePrepStrategy;
        char sidesChoice;
        std::string sidesElement;
        char sauceChoice;
        std::string sauceElement;
};
#endif