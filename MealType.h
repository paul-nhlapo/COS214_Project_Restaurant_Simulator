#ifndef MEALTYPE_H
#define MEALTYPE_H

#include <iostream>

class MealType
{
    public:
        MealType();
        virtual ~MealType();

        virtual std::string getMealType() = 0;    
    
    protected:
        std::string mealType;
};

#endif