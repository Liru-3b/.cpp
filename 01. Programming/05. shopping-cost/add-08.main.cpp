
/*
Improvement: Introduced Early Returns (Exits). 
    Exit the function the moment you have your answer.
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <string_view>

struct ShippingConfig {
    static constexpr double  RATE_UNDER_1KG = 10.0;
    static constexpr double  RATE_UNDER_5KG = 7.5;
    static constexpr double RATE_UNDER_10KG = 5.5;
    static constexpr double RATE_UNDER_15KG = 3.75;
    static constexpr double RATE_UNDER_20KG = 2.125;
    static constexpr double DEFAULT_RATE = 1.5;};

double calculateShippingCost(double itemWeight);
double getValidInputs(std::string_view prompt);

int main() {
    double itemPrice = getValidInputs("Price: ");
    double itemWeight = getValidInputs("Weight: ");

    constexpr double TAX_RATE = 0.4343;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = calculateShippingCost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;}

double calculateShippingCost(double itemWeight) {
    /* I Implemented Early Returns Here: */
    if (itemWeight < 1)  return itemWeight * ShippingConfig::RATE_UNDER_1KG;
    if (itemWeight < 5)  return itemWeight * ShippingConfig::RATE_UNDER_5KG;
    if (itemWeight < 10) return itemWeight * ShippingConfig::RATE_UNDER_10KG;
    if (itemWeight < 15) return itemWeight * ShippingConfig::RATE_UNDER_15KG;
    if (itemWeight < 20) return itemWeight * ShippingConfig::RATE_UNDER_20KG;

    return itemWeight * ShippingConfig::DEFAULT_RATE;}

double getValidInputs(std::string_view prompt) {
    /* I also Implemented Early Returns Here: */
    while (true) {
        double validInput; std::cout << prompt;
        
        if (std::cin >> validInput && validInput > 0)
            return validInput; /*Early Exit*/

        std::cout << "\033[A\033[2K"  "msg\n";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }}