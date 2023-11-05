#include <iostream>
#include <string>

#include "PreparationStartegy.h"

class PreparationStrategy::~PreparationStrategy();

// Concrete Strategy for Fry
void FryStrategy::prepare(const Order* order) const override {
    // Assuming that the frying logic applies to certain main courses
    if (order->getItemType() == "fried main") {
        std::cout << "Frying the " << order->getItemName() << ", ensuring a crispy texture..." << std::endl;
    }
}

// Concrete Strategy for Salad
void SaladStrategy::prepare(const Order* order) const override {
    // Assuming that the salad logic applies to starters
    if (order->getItemType() == "salad starter") {
        std::cout << "Combining fresh ingredients to prepare the " << order->getItemName() << " salad..." << std::endl;
    }
}

// Concrete Strategy for Bake

void BakeStrategy::prepare(const Order* order) const override {
    // Assuming that the baking logic applies to baked goods, including desserts
    if (order->getItemType() == "baked dessert" || order->getItemType() == "baked main") {
        std::cout << "Baking the " << order->getItemName() << ", bringing out a homely aroma..." << std::endl;
    }
}

// Concrete Strategy for Boil
void BoilStrategy::prepare(const Order* order) const override {
    // Assuming that boiling is required for some main courses
    if (order->getItemType() == "boiled main") {
        std::cout << "Boiling the " << order->getItemName() << ", preserving flavors and nutrients..." << std::endl;
    }
}

// Concrete Strategy for Grill
void GrillStrategy::prepare(const Order* order) const override {
    // Assuming that grilling is primarily for main courses
    if (order->getItemType() == "grilled main") {
        std::cout << "Grilling the " << order->getItemName() << ", adding those coveted char lines..." << std::endl;
    }
}


// Concrete Strategy for Sushi
void SushiStrategy::prepare(const Order* order) const override {
    // Assuming sushi is a specialized category of mains
    if (order->getItemType() == "sushi main") {
        std::cout << "Crafting the " << order->getItemName() << " with precision and tradition..." << std::endl;
    }
}

// Concrete Strategy for Simmer
void SimmerStrategy::prepare(const Order* order) const override {
    // Assuming simmering applies to certain main courses like stews
    if (order->getItemType() == "simmered main") {
        std::cout << "Gently simmering the " << order->getItemName() << " to infuse flavors and tenderize..." << std::endl;
    }
}

// Concrete Strategy for Cold Dessert
void ColdDessertStrategy::prepare(const Order* order) const override {
    // Assuming cold dessert preparation for items like ice cream or chilled pies
    if (order->getItemType() == "cold dessert") {
        std::cout << "Chilling the " << order->getItemName() << " to set, for a refreshing finale..." << std::endl;
    }
}

// Concrete Strategy for Hot Dessert
void HotDessertStrategy::prepare(const Order* order) const override {
    // Assuming hot dessert preparation for items like warm puddings or pies
    if (order->getItemType() == "hot dessert") {
        std::cout << "Preparing the warm " << order->getItemName() << ", perfect for a cozy ending..." << std::endl;
    }
}