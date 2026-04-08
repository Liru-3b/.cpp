/*
Improvement:
    Creating a dedicated function to handle the output
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <string_view>


struct Receipt {
    double itemTax, itemPrice, itemWeight, shippingCost, final_itemCost; };

struct ShippingConfig 
{   static constexpr double TAX_RATE_UNDER_2KG = 15.0;
    static constexpr double TAX_RATE_UNDER_4KG = 12.5;
    static constexpr double TAX_RATE_UNDER_8KG = 10.0;
    static constexpr double TAX_RATE_UNDER_16KG = 7.5;
    static constexpr double TAX_RATE_UNDER_32KG = 5.0;
    static constexpr double DEFAULT_RATE = 2.5; };


double getInput(std::string_view prompt);
double getShippinFee(double weight);
void printReceipt(const Receipt& r);

int main() {
    Receipt r;
    r.itemPrice = getInput("...");
    r.itemWeight = getInput("...");

    constexpr double TAX_RATE = 0.04343;
    r.itemTax = TAX_RATE * r.itemPrice;
    r.shippingCost = getShippinFee(r.itemWeight);
    r.final_itemCost = r.itemPrice + r.itemTax + r.shippingCost;
    
    printReceipt(r);
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

double getShippinFee(double weight) {
    if (weight < 2)  weight * ShippingConfig::TAX_RATE_UNDER_2KG;
    if (weight < 4)  weight * ShippingConfig::TAX_RATE_UNDER_4KG;
    if (weight < 8)  weight * ShippingConfig::TAX_RATE_UNDER_8KG;
    if (weight < 16) weight * ShippingConfig::TAX_RATE_UNDER_16KG;
    if (weight < 32) weight * ShippingConfig::TAX_RATE_UNDER_32KG;

    return weight * ShippingConfig::DEFAULT_RATE;
}

/* Created the dedicated function to handle the output Here */
void printReceipt(const Receipt& r) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Invoice Summary ---"
        << "\n  Subtotal:  $" << r.itemPrice
        << "\n  Tax:       $" << r.itemTax
        << "\n  Shipping:  $" << r.shippingCost
        << "\n  ---------------------"
        << "\n  Total:     $" << r.final_itemCost 
        << std::endl;
}