#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Forward declarations
class Order;

// Strategy Interface
class PreparationStrategy {
public:
    virtual ~PreparationStrategy() = default;
    virtual void prepare(const Order& order) const = 0;
};

// Concrete Strategies
// For the sake of brevity, we'll use only two strategies
class GrillStrategy : public PreparationStrategy {
public:
    void prepare(const Order& order) const override {
        std::cout << "Grilling components of the order." << std::endl;
        // Implement grilling logic based on the order
    }
};

class BakeStrategy : public PreparationStrategy {
public:
    void prepare(const Order& order) const override {
        std::cout << "Baking components of the order." << std::endl;
        // Implement baking logic based on the order
    }
};

// Order class
class Order {
public:
    std::vector<std::string> components;  // Details of the order, e.g., ["pizza dough", "cheese", "tomato sauce"]
    // ... Other details and methods for an order
};

// Chef Interface (Handler in CoR)
class Chef {
protected:
    std::unique_ptr<PreparationStrategy> preparationStrategy;
    Chef* nextChef;

public:
    Chef() : nextChef(nullptr) {}
    virtual ~Chef() {}

    void setNextChef(Chef* chef) {
        nextChef = chef;
    }

    void setPreparationStrategy(std::unique_ptr<PreparationStrategy> strategy) {
        preparationStrategy = std::move(strategy);
    }

    virtual void handleOrder(const Order& order) {
        if (preparationStrategy) {
            preparationStrategy->prepare(order);
        }
        // Pass the order to the next chef in the chain if there's one
        if (nextChef) {
            nextChef->handleOrder(order);
        }
    }
};

// Concrete Handlers
class GrillChef : public Chef {
public:
    GrillChef() {
        setPreparationStrategy(std::make_unique<GrillStrategy>());
    }
};

class BakeChef : public Chef {
public:
    BakeChef() {
        setPreparationStrategy(std::make_unique<BakeStrategy>());
    }
};

// Main function to test the CoR with Strategy
int main() {
    // Setup the chain of chefs
    GrillChef grillChef;
    BakeChef bakeChef;

    grillChef.setNextChef(&bakeChef);

    // Create an order
    Order order;
    order.components = {"pizza dough", "steak", "chicken"};

    // Process the order
    grillChef.handleOrder(order);

    return 0;
}
