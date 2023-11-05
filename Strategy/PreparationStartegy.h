#ifndef PREPARATIONSTRATEGY_H
#define PREPARATIONSTRATEGY_H


class Order;
// Strategy Interface
class PreparationStrategy {
    public:
        virtual ~PreparationStrategy() = default;
        virtual void prepare(const Order& order) const = 0;
};

// Concrete Strategies
// Concrete Strategy for Fry
class FryStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Salad
class SaladStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Bake
class BakeStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Boil
class BoilStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Grill
class GrillStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Sushi
class SushiStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Simmer
class SimmerStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Cold Dessert
class ColdDessertStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

// Concrete Strategy for Hot Dessert
class HotDessertStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const;
};

#endif