#ifndef COOKINGSTRATEGY_H
#define COOKINGSTRATEGY_H

#include <iostream>

class CookingStrategy
{
public:
    virtual std::string cookMeal(std::string prepMethod) = 0;
    virtual ~CookingStrategy(){};
};

class Fry : public CookingStrategy
{
public:
    Fry();
    virtual std::string cookMeal(std::string prepMethod);
    ~Fry();
};

class Grill : public CookingStrategy
{
public:
    Grill();
    virtual std::string cookMeal(std::string prepMethod);
    ~Grill();
};

class Bake : public CookingStrategy
{
public:
    Bake();
    virtual std::string cookMeal(std::string prepMethod);
    ~Bake();
};

class Boil : public CookingStrategy
{
public:
    Boil();
    virtual std::string cookMeal(std::string prepMethod);
    ~Boil();
};

class Sushi : public CookingStrategy
{
public:
    Sushi();
    virtual std::string cookMeal(std::string prepMethod);
    ~Sushi();
};

class Saute : public CookingStrategy
{
public:
    Saute();
    virtual std::string cookMeal(std::string prepMethod);
    ~Saute();
};

class Simmer : public CookingStrategy
{
public:
    Simmer();
    virtual std::string cookMeal(std::string prepMethod);
    ~Simmer();
};

class NoCook : public CookingStrategy
{
public:
    NoCook();
    virtual std::string cookMeal(std::string prepMethod);
    ~NoCook();
};

class Salad : public CookingStrategy
{
public:
    Salad();
    virtual std::string cookMeal(std::string prepMethod);
    ~Salad();
};

class ColdDessert : public CookingStrategy
{
public:
    ColdDessert();
    virtual std::string cookMeal(std::string prepMethod);
    ~ColdDessert();
};

class HotDessert : public CookingStrategy
{
public:
    HotDessert();
    virtual std::string cookMeal(std::string prepMethod);
    ~HotDessert();
};

#endif