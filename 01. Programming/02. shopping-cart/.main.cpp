
#include <string>
#include <format>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>
#include <string_view>

namespace Store {

    struct ShoppingReceipt {
        double itemPrice, itemWeight, itemCount, ItemLevy, shippingCost, totalCost;};

    struct ShippingConfig {
        static constexpr double  RATE_UNDER_1KG = 10.0;
        static constexpr double  RATE_UNDER_2KG = 8.00;
        static constexpr double  RATE_UNDER_5KG = 7.50;
        static constexpr double RATE_UNDER_10KG = 5.00;
        static constexpr double RATE_UNDER_15KG = 3.50;
        static constexpr double RATE_UNDER_20KG = 1.75;
        static constexpr double DEFAULT_RATE = 1.15;};

    double GetShippingCost(double itemWeight) {
        if (itemWeight <  1) return itemWeight * ShippingConfig::RATE_UNDER_1KG;
        if (itemWeight <  2) return itemWeight * ShippingConfig::RATE_UNDER_2KG;
        if (itemWeight <  5) return itemWeight * ShippingConfig::RATE_UNDER_5KG;
        if (itemWeight < 10) return itemWeight * ShippingConfig::RATE_UNDER_10KG;
        if (itemWeight < 15) return itemWeight * ShippingConfig::RATE_UNDER_15KG;
        if (itemWeight < 20) return itemWeight * ShippingConfig::RATE_UNDER_20KG;

            return itemWeight * ShippingConfig::DEFAULT_RATE; }

    void PrintReceipt(const ShoppingReceipt& r) {
        std::cout << std::format(
            "\n--- Invoice Summary ---"
            "\n  Item Price:     ${:.2f}"
            "\n  Item Count:     ${:.2f}"
            "\n  Item's Tax:     ${:.2f}"
            "\n  Shipping Cost:  ${:.2f}"
            "\n  ------------------"
            "\n  Total Cost:     ${:.2f}\n",
            r.itemPrice, r.itemCount, r.ItemLevy, r.shippingCost, r.totalCost);}

    template <typename Template, typename Predicate>
    Template ValidateInput(std::string_view prompt, Predicate isValid) {
        std::string input;

        while (true) {/*Do Something*/
            std::cout << prompt;
            
            if (!std::getline(std::cin, input)) exit(1);

            try {/*Something*/
                Template value; size_t position;

                if constexpr(std::is_same_v<Template, double>
                    ) {value = std::stod(input, &position);}

                    else if constexpr(std::is_same_v<Template, int>
                        ) {value = std::stoi(input, &position);}

                bool isTrash = false;
                for (size_t i = position; i < input.length(); ++i) {
                    if (!std::isspace(static_cast<unsigned char>(input[i]))
                        ) {isTrash = true; 
                        /**/        break;}
                        /* End For Loop */} 

                    if (!isTrash && isValid(value)) return value;
            
            /*Exit Try*/} 
            catch (...) {}

            std::cout << "\033[A\033[2K";
            std::cout << "Invalid Input!\n";

        /*End While Loop*/}   
    /*End of Template*/}
/*End of Namespace*/}

int main() {
    using namespace Store;

    auto priceRule = [](double v) {return v > 0.0; };
    auto countRule = [](int    v) {return v > 0;   };
    auto weightRule = [](double v) {return v > 0.0 && v <= 100.0;};
    
    ShoppingReceipt r;
    r.itemPrice = ValidateInput<double>("Price: ", priceRule);
    r.itemCount = ValidateInput<double>("Count: ", countRule);
    r.itemWeight = ValidateInput<double>("Weight: ", weightRule);

    constexpr double TAX_RATE = 0.04235;
    r.ItemLevy = TAX_RATE * r.itemPrice;
    r.shippingCost = GetShippingCost(r.itemWeight);
    r.totalCost = (r.itemPrice + r.ItemLevy + r.shippingCost) * r.itemCount;

    PrintReceipt(r); 
}