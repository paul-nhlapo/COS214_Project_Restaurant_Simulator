#include <iostream>
#include <string>

// Forward declarations to avoid circular dependencies
class Order;
class Kitchen;

class ChefState;

class Chef {
public:
    Chef(std::string name, Kitchen* kitchen) : name(std::move(name)), kitchen(kitchen), nextChef(nullptr), preparationStrategy(nullptr) {}
    virtual ~Chef() = default;

    virtual std::string getChefType() const = 0;
    virtual void prepareMeal(Order* order) = 0;
    virtual void setNextChef(Chef* nextChef) { this->nextChef = nextChef; }

    // CoR method to handle the order or pass it to the next chef in the chain
    void handleOrder(Order* order) {
        if (canHandleOrder(order)) {
            prepareMeal(order);
        } else if (nextChef) {
            nextChef->handleOrder(order);
        } else {
            std::cerr << "Order could not be handled by any chef!" << std::endl;
        }
    }

    // Method to assign a strategy to the chef
    void setPreparationStrategy(std::unique_ptr<PreparationStrategy> strategy) {
        preparationStrategy = std::move(strategy);
    }

    // Each Chef will implement this to determine if it can handle the order based on its type
    virtual bool canHandleOrder(Order* order) const = 0;

protected:
    std::string name;
    Chef* nextChef;
    ChefState* currentState;
    Kitchen* kitchen;
};

// Assume Order has a member function called `getType()` that returns the type of meal
// and other necessary details about the meal that needs to be prepared.

// MainChef as an example:
class MainChef : public Chef {
public:
    MainChef(std::string name, Kitchen* kitchen) : Chef(std::move(name), kitchen) {
        // Assign the strategy appropriate for the MainChef during construction
        setPreparationStrategy(std::make_unique<GrillStrategy>());
    }

    std::string getChefType() const override {
        return "MainChef";
    }

    void prepareMeal(Order* order) override {
        // Logic to prepare the main course
        std::cout << "MainChef " << name << " is preparing a main course." << std::endl;
    }

    bool canHandleOrder(Order* order) const override {
        return order->getType() == "MainCourse"; // assuming Order has a getType method
    }
};

// Similarly, you would implement other chef types like DessertChef, StarterChef, etc.
