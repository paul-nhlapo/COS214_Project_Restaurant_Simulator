#ifndef MAINMEALBUILDER_H
#define MAINMEALBUILDER_H

#include "MealBuilder.h"

class MainMealBuilder : public MealBuilder
{
    public:
        MainMealBuilder();
        ~MainMealBuilder();
        
        void setMainElement(std::string mainElement);
        void setMainElementPrepStrategy(std::string mainElementPrepStrategy);

        void setSideElement(std::string side);
        void setSidePrepStrategy(std::string sidePrepStrategy);

        void setSauceElement(std::string sauce);

        Meal* getMeal();
};

#endif