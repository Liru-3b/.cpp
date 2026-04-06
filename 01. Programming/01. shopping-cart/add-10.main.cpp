/*
Improvement:
    Fixed an error where "9dcdk3" is seen as a valid input.
    Previously, it would grab the 9, and leave the trash 
    in the input buffer for the next cin to deal with. 
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string_view>

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

    const double TAX_RATE = 0.06565;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = calculateShippingCost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;
}

double calculateShippingCost(double itemWeight) {
    if (itemWeight < 1)  return itemWeight * ShippingConfig::RATE_UNDER_1KG;
    if (itemWeight < 5)  return itemWeight * ShippingConfig::RATE_UNDER_5KG;
    if (itemWeight < 10) return itemWeight * ShippingConfig::RATE_UNDER_10KG;
    if (itemWeight < 15) return itemWeight * ShippingConfig::RATE_UNDER_15KG;
    if (itemWeight < 20) return itemWeight * ShippingConfig::RATE_UNDER_20KG;

    return itemWeight * ShippingConfig::DEFAULT_RATE;
}

/* I Fixed the Error Here (also trims any whitespace) */
double getValidatedInput(std::string_view promptLabel) {
    std::string input;

    while (true) {
        std::cout << promptLabel;
        if(!std::getline(std::cin, input)) return -1; 
        
        try {
            size_t pos; bool isTrash = false;
            double val = std::stod(input, &pos);
            
            for (size_t i = pos; i < input.length(); ++i) {
                if (!std::isspace(static_cast<unsigned char>(input[i]))
                    ) {isTrash = true; break;}} 
                    
            if (!isTrash && val > 0) return val;
        } catch(...) {} 
        std::cout << "\033[A\033[2K" "msg\n";}
}