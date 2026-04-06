/*
Improvement:
    Input Customization, ValidateInput now accepts a third parameter
*/


#include <string>
#include <format>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string_view>

namespace Store {

    struct Receipt {double price, weight, amount, tax, shipping, total;};

    
    struct ShippingConfig {
        static constexpr double RATE_LESS_01KG = 10.0;
        static constexpr double RATE_LESS_03KG = 8.00;
        static constexpr double RATE_LESS_05KG = 6.00;
        static constexpr double RATE_LESS_07KG = 5.00;
        static constexpr double RATE_LESS_10KG = 3.00;
        static constexpr double RATE_LESS_12KG = 2.00;
        static constexpr double STANDARD__RATE = 1.00;};


    double GetShippingCost(double weight) {
        if (weight < 1) return weight * ShippingConfig::RATE_LESS_01KG;
        if (weight < 3) return weight * ShippingConfig::RATE_LESS_03KG;
        if (weight < 5) return weight * ShippingConfig::RATE_LESS_05KG;
        if (weight < 7) return weight * ShippingConfig::RATE_LESS_07KG;
        if (weight < 10) return weight * ShippingConfig::RATE_LESS_10KG;
        if (weight < 12) return weight * ShippingConfig::RATE_LESS_12KG;

        return weight * ShippingConfig::STANDARD__RATE;}


    void PrintReceipt(const Receipt& r) {
        std::cout << "Printing Receipt ... ";
        /*...*/
    }


    template <typename Template, typename Predicate>
    Template ValidateInput(std::string_view prompt, Predicate isValid, std::string_view msg) {
        std::string input;

        while (true) {/*Do Something*/
            std::cout << prompt;

            if (!std::getline(std::cin, input)) exit(1);

            try {/*Something*/
                Template value;
                size_t position;

                if constexpr (std::is_same_v<Template, double>
                    ) {value = std::stod(input, &position);}

                    else if constexpr(std::is_same_v<Template, int>
                        ) {value = std::stoi(input, &position);}

                bool isTrash = false;
                for (size_t i = position; i < input.length(); ++i) {
                    if (!std::isspace(static_cast<unsigned char>(input[i]))
                        ) {isTrash = true;
                        /**/        break;}
                }
                if (!isTrash && isValid(value))
                    return value;
                
            /*Exit Try*/}
            catch /*Something*/ (...) {}

            std::cout << "\033[A\033[2K";
            std::cout << msg << '\n';
        }
    }
}


int main() {
    using namespace Store;

    std::cout << "Print Something!\n";

    auto priceRule = [](double v) {return v > 0.0;};
    auto weightRule = [](double v) {return v > 0.0 && v <= 100.0;};
    auto amountRule = [](int v) {return v > 0;};

    Receipt r;
    r.price = ValidateInput<double>  ("Price: ", priceRule, "Price Error");
    r.weight = ValidateInput<double> ("Weight: ", weightRule, "Weight Error");
    r.amount = ValidateInput<int>    ("Amount: ", amountRule, "Amount Error");

    constexpr double TAX_RATE = 0.06454;
    r.tax = TAX_RATE * r.price;
    r.shipping = GetShippingCost(r.weight);
    r.total = (r.price + r.tax + r.shipping) * r.amount;

    PrintReceipt(r);
}