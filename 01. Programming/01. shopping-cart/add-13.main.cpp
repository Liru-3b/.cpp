/*
Improvement:
    Using std::format for clear string formating
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string_view>

struct ShippingConfig {
    static constexpr double RATE_UNDER_2KG  = 7.0;
    static constexpr double RATE_UNDER_4KG  = 6.0;
    static constexpr double RATE_UNDER_8KG  = 5.0;
    static constexpr double RATE_UNDER_16KG = 4.0;
    static constexpr double RATE_UNDER_32KG = 3.0;
    static constexpr double RATE_UNDER_64KG = 2.0;
    static constexpr double DEFAULT_RATE = 7.0; };

struct Receipt {
    double itemPrice, itemWeight, itemTax, shippingCost, totalCost; };

double getInput(std::string_view prompt);
double shippingfee(double weight);
void PrintReceipt(const Receipt& r);

int main() {
    Receipt r;
    r.itemPrice = getInput("...");
    r.itemWeight = getInput("...");

    constexpr double TAX_RATE = 0.34344;
    r.itemTax = TAX_RATE * r.itemPrice;
    r.shippingCost = shippingfee(r.itemWeight);
    r.totalCost = r.itemPrice + r.itemTax + r.shippingCost;

    PrintReceipt(r);
}

double getInput(std::string_view prompt) {
    std::string input;
    
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) return -1;

        try {
            size_t pos; double val = std::stod(input, &pos);

            bool isTrash = false;
            for (size_t i = pos; i < input.length(); ++i) {
                if (!std::isspace(static_cast<unsigned char>(input[i]))
                    ) {isTrash = true; break;}
            } if (!isTrash && val > 0) return val;
        } catch (...) {}

        std::puts("\033[A\033[2K"/**/"Error! msg");
    }
}

double shippingfee(double weight) {
    if (weight < 2) return weight * ShippingConfig::RATE_UNDER_2KG;
    if (weight < 4) return weight * ShippingConfig::RATE_UNDER_4KG;
    if (weight < 8) return weight * ShippingConfig::RATE_UNDER_8KG;
    if (weight < 16) return weight * ShippingConfig::RATE_UNDER_16KG;
    if (weight < 32) return weight * ShippingConfig::RATE_UNDER_32KG;

    return weight * ShippingConfig::DEFAULT_RATE;
}

void PrintReceipt(const Receipt& r) {
    std::cout << std::format(
        "\n--- Invoice Summary ---"
        "\n  Subtotal:  ${:.2f}"
        "\n  Tax:       ${:.2f}"
        "\n  Shipping:  ${:.2f}"
        "\n  ------------------"
        "\n  Total:    ${:.2f}",
        r.itemPrice, r.itemTax, r.shippingCost, r.totalCost);
}