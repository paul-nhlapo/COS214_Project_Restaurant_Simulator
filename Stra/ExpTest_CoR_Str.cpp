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
// Concrete Strategy for Fry
class FryStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming that the frying logic applies to certain main courses
        if (order->getItemType() == "fried main") {
            std::cout << "Frying the " << order->getItemName() << ", ensuring a crispy texture..." << std::endl;
        }
    }
};

// Concrete Strategy for Salad
class SaladStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming that the salad logic applies to starters
        if (order->getItemType() == "salad starter") {
            std::cout << "Combining fresh ingredients to prepare the " << order->getItemName() << " salad..." << std::endl;
        }
    }
};

// Concrete Strategy for Bake
class BakeStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming that the baking logic applies to baked goods, including desserts
        if (order->getItemType() == "baked dessert" || order->getItemType() == "baked main") {
            std::cout << "Baking the " << order->getItemName() << ", bringing out a homely aroma..." << std::endl;
        }
    }
};

// Concrete Strategy for Boil
class BoilStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming that boiling is required for some main courses
        if (order->getItemType() == "boiled main") {
            std::cout << "Boiling the " << order->getItemName() << ", preserving flavors and nutrients..." << std::endl;
        }
    }
};

// Concrete Strategy for Grill
class GrillStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming that grilling is primarily for main courses
        if (order->getItemType() == "grilled main") {
            std::cout << "Grilling the " << order->getItemName() << ", adding those coveted char lines..." << std::endl;
        }
    }
};

// Concrete Strategy for Sushi
class SushiStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming sushi is a specialized category of mains
        if (order->getItemType() == "sushi main") {
            std::cout << "Crafting the " << order->getItemName() << " with precision and tradition..." << std::endl;
        }
    }
};

// Concrete Strategy for Simmer
class SimmerStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming simmering applies to certain main courses like stews
        if (order->getItemType() == "simmered main") {
            std::cout << "Gently simmering the " << order->getItemName() << " to infuse flavors and tenderize..." << std::endl;
        }
    }
};

// Concrete Strategy for Cold Dessert
class ColdDessertStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming cold dessert preparation for items like ice cream or chilled pies
        if (order->getItemType() == "cold dessert") {
            std::cout << "Chilling the " << order->getItemName() << " to set, for a refreshing finale..." << std::endl;
        }
    }
};

// Concrete Strategy for Hot Dessert
class HotDessertStrategy : public PreparationStrategy {
public:
    void prepare(const Order* order) const override {
        // Assuming hot dessert preparation for items like warm puddings or pies
        if (order->getItemType() == "hot dessert") {
            std::cout << "Preparing the warm " << order->getItemName() << ", perfect for a cozy ending..." << std::endl;
        }
    }
};



// Order class
class Order {
public:
    std::vector<std::string> components;  // Details of the order, e.g., ["pizza dough", "cheese", "tomato sauce"]
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
