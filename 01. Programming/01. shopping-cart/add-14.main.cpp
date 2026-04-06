/*
Improvement:
    Input Validation with Lambdas
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <optional>
#include <algorithm>
#include <functional>
#include <string_view>

/* Created a Template to Validate the Input */
template <typename T, typename Predicate>
T getValidatedInput(std::string_view prompt, Predicate isValid) {
    std::string input;

    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {exit(1);}

        try {
            T val; size_t pos;

            if constexpr (std::is_same_v<T, double>) val = std::stod(input, &pos);
            else if constexpr (std::is_same_v<T, int>) val = std::stoi(input, &pos);
            
            bool isTrash = false;
            for (size_t i = pos; i < input.length(); ++i) {
                if (!std::isspace(static_cast<unsigned char>(input[i]))
                    ) {isTrash = true; break;}}

            if (!isTrash && isValid(val)) return val;
        } catch (...) {}
        std::cout << "\033[A\033[2K" << "Error! msg\n";}
}

struct ShippingConfig {
    static constexpr double RATE_UNDER_2KG = 7.0;
    static constexpr double RATE_UNDER_4KG = 6.0;
    static constexpr double RATE_UNDER_8KG = 5.0;
    static constexpr double RATE_UNDER_16KG = 4.0;
    static constexpr double RATE_UNDER_32KG = 3.0;
    static constexpr double RATE_UNDER_64KG = 2.0;
    static constexpr double DEFAULT_RATE = 7.0;};

struct Receipt {
    double itemPrice, itemWeight, itemTax, shippingCost, totalCost;
};

void PrintReceipt(const Receipt& r) {
    std::cout << std::format(
        "\n--- Invoice Summary ---"
        "\n  Subtotal:  ${:.2f}"
        "\n  Tax:       ${:.2f}"
        "\n  Shipping:  ${:.2f}"
        "\n  ------------------"
        "\n  Subtoal:   ${:.2f}\n",
        r.itemPrice, r.itemTax, r.shippingCost, r.totalCost);
}

double shippingfee(double weight) {
    if (weight < 2) return weight * ShippingConfig::RATE_UNDER_2KG;
    if (weight < 4) return weight * ShippingConfig::RATE_UNDER_4KG;
    if (weight < 8) return weight * ShippingConfig::RATE_UNDER_8KG;
    if (weight < 16) return weight * ShippingConfig::RATE_UNDER_16KG;
    if (weight < 32) return weight * ShippingConfig::RATE_UNDER_32KG;

    return weight * ShippingConfig::DEFAULT_RATE;
}

int main() {
    auto priceRule = [](double v) {return v > 0.0;};
    auto weightRule = [](double v) {return v > 0.0 && v <= 100.0;};

    Receipt r; /* You can Validate the Input with Lambdas Here */
    r.itemPrice = getValidatedInput<double>("Enter Price: ", priceRule);
    r.itemWeight = getValidatedInput<double>("Enter Weight: ", weightRule);
    int qty = getValidatedInput<int>("Enter Quantity: ", [](int v) {return v > 0;});

    constexpr double TAX_RATE = 0.34344;
    r.itemTax = TAX_RATE * r.itemPrice;
    r.shippingCost = shippingfee(r.itemWeight);
    r.totalCost = (r.itemPrice + r.itemTax + r.shippingCost) * qty;

    PrintReceipt(r);
}