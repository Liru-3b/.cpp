/*
Improvement:
    Moved Magic Numbers to a configuration struct
*/

#include <iomanip>
#include <iostream>
#include <string_view>

/* I Moved Magic Numbers to a configuration struct */
struct ShippingConfig {
    static constexpr double  RATE_UNDER_1KG = 10.0;
    static constexpr double  RATE_UNDER_5KG = 8.0;
    static constexpr double RATE_UNDER_10KG = 6.0;
    static constexpr double RATE_UNDER_15KG = 4.0;
    static constexpr double RATE_UNDER_20KG = 2.0;
    static constexpr double DEFAULT_RATE = 1.0;
};

double calculateShippingCost(double itemWeight);
double getValidatedInput(std::string_view promptLabel);

int main() {
    double itemPrice = getValidatedInput("...");
    double itemWeight = getValidatedInput("...");

    constexpr double TAX_RATE = 0.06565;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = calculateShippingCost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;
}

double getValidatedInput(std::string_view promptLabel) {
    double validInput;
    do {
        std::cout << promptLabel;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K" << "Error! msg\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            validInput = -1;}
    } while (validInput < 0);

    return validInput;
}

double calculateShippingCost(double itemWeight) {
    double rate;

    if (itemWeight < 1) rate = ShippingConfig::RATE_UNDER_1KG;
    else if (itemWeight <  5) rate = ShippingConfig::RATE_UNDER_5KG;
    else if (itemWeight < 10) rate = ShippingConfig::RATE_UNDER_10KG;
    else if (itemWeight < 15) rate = ShippingConfig::RATE_UNDER_15KG;
    else if (itemWeight < 20) rate = ShippingConfig::RATE_UNDER_20KG;
    else rate = ShippingConfig::DEFAULT_RATE;

    return itemWeight * rate;
}