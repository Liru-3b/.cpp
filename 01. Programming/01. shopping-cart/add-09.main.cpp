/*
Improvement: Introduced Numeric Limits. 
    Clearing the buffer regardless of size.
*/

#include <limits>
#include <iomanip>
#include <iostream>
#include <string_view>

struct ShippingConfig {
    static constexpr double RATE_UNDER_100KG  = 29.00;
    static constexpr double RATE_UNDER_200KG  = 16.50;
    static constexpr double RATE_UNDER_500KG  = 12.01;
    static constexpr double RATE_UNDER_1000KG = 9.000;
    static constexpr double RATE_UNDER_1500KG = 7.000;
    static constexpr double RATE_UNDER_3000KG = 5.000;
    static constexpr double DEFAULT_RATE = 2.00000001;
};

double getValidInputs(std::string_view prompt);
double calculateShippingCost(double itemWeight);

int main() {
    double price_item = getValidInputs("P...");
    double weight_item = getValidInputs("W...");

    constexpr double TAX_RATE = 0.54343;
    double tax_item = TAX_RATE * price_item;
    double shippingCost = calculateShippingCost(weight_item);
    double totalCost = price_item + tax_item + shippingCost;
}

double calculateShippingCost(double itemWeight) {
    if (itemWeight < 100)  return itemWeight * ShippingConfig::RATE_UNDER_100KG;
    if (itemWeight < 200)  return itemWeight * ShippingConfig::RATE_UNDER_200KG;
    if (itemWeight < 500)  return itemWeight * ShippingConfig::RATE_UNDER_500KG;
    if (itemWeight < 1000) return itemWeight * ShippingConfig::RATE_UNDER_1000KG;
    if (itemWeight < 1500) return itemWeight * ShippingConfig::RATE_UNDER_1500KG;
    if (itemWeight < 3000) return itemWeight * ShippingConfig::RATE_UNDER_3000KG;

    return itemWeight * ShippingConfig::DEFAULT_RATE;
}

double getValidInputs(std::string_view prompt) {
    while (true) {
        double valid_input; 
        std::cout << prompt;

        if (std::cin >> valid_input && valid_input > 0)
            return valid_input;

        std::cout << "\033[A\033[2K" << "Error! msg\n";
        std::cin.clear();

        /* I switched to numeric limits here */
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');}
}