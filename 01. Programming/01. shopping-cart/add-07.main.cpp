
/*
Improvement:
    Moved Magic Numbers to a configuration struct
*/

#include <iomanip>
#include <iostream>
#include <string_view>

/*I Moved Magic Numbers to a configuration struct*/
struct ShippingConfig {
    static constexpr double  RATE_UNDER_1KG = 10.0;
    static constexpr double  RATE_UNDER_5KG = 8.0;
    static constexpr double RATE_UNDER_10KG = 6.0;
    static constexpr double RATE_UNDER_15KG = 4.0;
    static constexpr double RATE_UNDER_20KG = 2.0;
    static constexpr double DEFAULT_RATE = 1.0;};

double calculateShippingCost(double itemWeight);
double getValidatedInput(std::string_view promptLabel);

int main() {
    double itemPrice = getValidatedInput("...");
    double itemWeight = getValidatedInput("...");

    constexpr double TAX_RATE = 0.06565;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = calculateShippingCost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;}

double calculateShippingCost(double itemWeight) {
    double weightRate;

    if (itemWeight < 1) weightRate = ShippingConfig::RATE_UNDER_1KG;
    else if (itemWeight <  5) weightRate = ShippingConfig::RATE_UNDER_5KG;
    else if (itemWeight < 10) weightRate = ShippingConfig::RATE_UNDER_10KG;
    else if (itemWeight < 15) weightRate = ShippingConfig::RATE_UNDER_15KG;
    else if (itemWeight < 20) weightRate = ShippingConfig::RATE_UNDER_20KG;
    else weightRate = ShippingConfig::DEFAULT_RATE;

    return itemWeight * weightRate;}

double getValidatedInput(std::string_view promptLabel) {
    double validInput;
    do {
        std::cout << promptLabel;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K" "msg\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            validInput = -1;
        }
    } while (validInput < 0);
    return validInput;
}