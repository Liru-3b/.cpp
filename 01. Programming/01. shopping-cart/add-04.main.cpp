/*
Improvement: 
    Removing the exit function (return 0).
    The Main body automatically returns 0.
*/

#include <string>
#include <iomanip>
#include <iostream>
#include <string_view>

double getValidatedInput(std::string_view promptLabel);
double calculateShippingCost(double itemWeight);

int main() {
    double itemPrice = getValidatedInput("...");
    double itemWeight = getValidatedInput("...");

    const double TAX_RATE = 0.0454;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = calculateShippingCost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;

    /* I removed return 0 Here*/
}

double getValidatedInput(std::string_view promptLabel) {
    double validInput;
    do {
        std::cout << promptLabel;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K" << "Error! msg\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            validInput = -1;}
    } while (validInput < 0);

    return validInput;
}

double calculateShippingCost(double itemWeight) {
    double rate;

    if (itemWeight < 1) rate = 10.0;
    else if (itemWeight < 4) rate = 8.0;
    else if (itemWeight < 8) rate = 6.0;
    else if (itemWeight < 12) rate = 4.5;
    else if (itemWeight < 16) rate = 3.0;
    else if (itemWeight < 20) rate = 2.0;
    else rate = 1.0;

    return itemWeight * rate;
}