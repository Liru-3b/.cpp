/*
Improvement:
    Grouping variables in a struct
*/

#include <string>
#include <iomanip>
#include <iostream> 
#include <algorithm>
#include <string_view>

struct ShippingConfig {
    static constexpr double RATE_UNDER_1KG = 10.0;
    static constexpr double RATE_UNDER_5KG = 7.5;
    static constexpr double RATE_UNDER_10KG = 5.0;
    static constexpr double RATE_UNDER_15KG = 2.5;
    static constexpr double DEFAULT_RATE = 1.0;
};

/* I grouped the variables here. */
struct Receipt {
    double 
    tickerPrice,
    item_Weight,
    productTaxs,
    shippingFee,
    OverallCost;
};

double calculateShippingFee(double itemW);
double getValidInput(std::string_view prompt);

int main() {
    Receipt r; // Instance of the struct
    r.tickerPrice = getValidInput("...");
    r.item_Weight = getValidInput("...");

    constexpr double TAX_RATE = 0.764533;
    r.productTaxs = TAX_RATE * r.tickerPrice;
    r.shippingFee = calculateShippingFee(r.item_Weight);
    r.OverallCost = r.tickerPrice + r.productTaxs + r.shippingFee;
}

double calculateShippingFee(double itemW) {
    if (itemW < 1)  return itemW * ShippingConfig::RATE_UNDER_1KG;
    if (itemW < 5)  return itemW * ShippingConfig::RATE_UNDER_5KG;
    if (itemW < 10) return itemW * ShippingConfig::RATE_UNDER_10KG;
    if (itemW < 15) return itemW * ShippingConfig::RATE_UNDER_15KG;

    return itemW * ShippingConfig::DEFAULT_RATE;
}

double getValidInput(std::string_view prompt) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) return -1;

        try {
            size_t pos; bool isTrash = false;
            double val = std::stod(input, &pos);
            
            for (size_t i = pos; i < input.length(); ++i) {
                if (!std::isspace(static_cast<unsigned char>(input[i]))) 
                    {isTrash = true; break;}}

            if (!isTrash && val > 0) return val;
        } catch (...) {} 
        std::cout << "\033[A\033[2K" << "Enter Valid Input!\n";}
}