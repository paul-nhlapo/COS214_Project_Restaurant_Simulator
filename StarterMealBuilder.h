#ifndef STARTERMEALBUILDER_H
#define STARTERMEALBUILDER_H

#include "MealBuilder.h"

class StarterMealBuilder : public MealBuilder
{
    public:
        StarterMealBuilder();
        // ~StarterMealBuilder();
        
        void setMainElement(std::string mainElement);
        void setMainElementPrepStrategy(std::string mainElementPrepStrategy);

        void setSideElement(std::string side);
        void setSidePrepStrategy(std::string sidePrepStrategy);

        void setSauceElement(std::string sauce);

        Meal* getMeal();
};

#endif