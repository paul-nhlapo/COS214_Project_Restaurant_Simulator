#include <iostream>
#include <string>
#include <memory>
#include <vector>
#include <algorithm>

// Forward declaration for Mediator
class HeadChefMediator;

// Dish product
class Dish {
public:
    void addPart(const std::string& part) {
        std::cout << "Adding: " << part << std::endl;
    }
    void setApproval(bool status) {
        std::cout << "Dish " << (status ? "approved" : "not approved") << " by Head Chef." << std::endl;
    }
};

// CookingStrategy Interface (Builder)
class CookingStrategy {
public:
    virtual ~CookingStrategy() = default;
    virtual void cook(Dish& dish) = 0;
};

// Concrete Cooking Strategies (ConcreteBuilders)
class GrillingStrategy : public CookingStrategy {
public:
    void cook(Dish& dish) override {
        dish.addPart("Grilled component");
    }
};

class FryingStrategy : public CookingStrategy {
public:
    void cook(Dish& dish) override {
        dish.addPart("Fried component");
    }
};

// ... Other strategies like BoilingStrategy, BakingStrategy, etc., can be added here ...

// Handler in Chain of Responsibility
class KitchenStaff {
protected:
    std::shared_ptr<KitchenStaff> nextStaff;
public:
    virtual ~KitchenStaff() = default;
    void setNext(std::shared_ptr<KitchenStaff> staff) {
        nextStaff = staff;
    }
    virtual void handleRequest(const std::string& request, Dish& dish) {
        if (nextStaff) {
            nextStaff->handleRequest(request, dish);
        } else {
            std::cerr << "No staff member to handle the request: " << request << std::endl;
        }
    }
};

// Concrete Handlers (Chefs)
class Chef : public KitchenStaff {
private:
    std::string specialization;
    std::unique_ptr<CookingStrategy> strategy;
    HeadChefMediator* mediator;

public:
    Chef(const std::string& spec, std::unique_ptr<CookingStrategy> strat, HeadChefMediator* med)
        : specialization(spec), strategy(std::move(strat)), mediator(med) {}

    void handleRequest(const std::string& request, Dish& dish) override;
    // ... other members ...
};

// Mediator Interface
class Mediator {
public:
    virtual void registerChef(Chef* chef) = 0;
    virtual void dishPrepared(Dish& dish, Chef* chef) = 0;
};

// Concrete Mediator
class HeadChefMediator : public Mediator {
private:
    std::vector<Chef*> chefs;
public:
    void registerChef(Chef* chef) override {
        chefs.push_back(chef);
    }

    void dishPrepared(Dish& dish, Chef* chef) override {
        // Here we could have some complex logic to decide if the dish is ready.
        // For example, checking if all parts are cooked or if some other chef needs to work on it.
        // For now, we'll just approve all dishes for simplicity.
        dish.setApproval(true);
    }
};

void Chef::handleRequest(const std::string& request, Dish& dish) {
    if (request == specialization) {
        strategy->cook(dish);
        mediator->dishPrepared(dish, this);
    } else {
        std::cout << specialization << " chef passes on the " << request << std::endl;
        KitchenStaff::handleRequest(request, dish);
    }
}

// Main function
int main() {
    HeadChefMediator mediator;
    Dish myDish;

    // Create chefs with their respective strategies
    auto grillingChef = std::shared_ptr<Chef>( new Chef("Grilling", std::unique_ptr<GrillingStrategy>(new GrillingStrategy()), &mediator));
    auto fryingChef = std::shared_ptr<Chef>(new Chef("Frying", std::unique_ptr<FryingStrategy>(new FryingStrategy()), &mediator));

    // Register chefs with the mediator
    mediator.registerChef(grillingChef.get());
    mediator.registerChef(fryingChef.get());

    // Setup chain of responsibility
    grillingChef->setNext(fryingChef);

    // Start the request chain
    grillingChef->handleRequest("Grilling", myDish);
    fryingChef->handleRequest("Frying", myDish);

    return 0;
}

