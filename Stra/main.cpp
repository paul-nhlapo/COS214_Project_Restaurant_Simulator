#include <iostream>
#include <memory>
#include <string>

// Strategy Interface
class PreparationStrategy {
public:
    virtual ~PreparationStrategy() = default;
    virtual void prepare() const = 0;
};

// Concrete Strategies
class FryStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Frying the food, ensuring a crispy texture..." << std::endl;
    }
};

class SaladStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Combining fresh ingredients to prepare a salad..." << std::endl;
    }
};

class BakeStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Baking the food, bringing out a homely aroma..." << std::endl;
    }
};

class BoilStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Boiling the food, preserving flavors and nutrients..." << std::endl;
    }
};

class GrillStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Grilling to perfection, adding those coveted char lines..." << std::endl;
    }
};

class SushiStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Crafting sushi with precision and tradition..." << std::endl;
    }
};

class SimmerStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Gently simmering to infuse flavors and tenderize..." << std::endl;
    }
};

class ColdDessertStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Chilling dessert to set, for a refreshing finale..." << std::endl;
    }
};

class HotDessertStrategy : public PreparationStrategy {
public:
    void prepare() const override {
        std::cout << "Preparing a warm dessert, perfect for a cozy ending..." << std::endl;
    }
};

// Context Class
class Chef {
private:
    std::unique_ptr<PreparationStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<PreparationStrategy> newStrategy) {
        strategy = std::move(newStrategy);
    }

    void prepareDish() const {
        if (strategy) {
            strategy->prepare();
        } else {
            std::cout << "No preparation strategy set!" << std::endl;
        }
    }
};

// Main function for testing the strategies
int main() {
    Chef chef;
    
    // Test frying strategy
    chef.setStrategy(std::unique_ptr<PreparationStrategy>(new FryStrategy()));
    chef.prepareDish();
    
    // Switch to salad strategy
    chef.setStrategy(std::unique_ptr<PreparationStrategy>(new SaladStrategy()));
    chef.prepareDish();

    // ... More tests with other strategies

    return 0;
}
