/*
Improvement:
    Naming Clarity: Making the code self-documenting.
*/

#include <string>
#include <iomanip>
#include <iostream>

double calculateShippingCost(double itemWeight);
double getValidatedInput(const std::string& prompt);

int main() {
    std::cout << "..." << '\n';

    double itemPrice = getValidatedInput("...");
    double itemWeight = getValidatedInput("...");

    const double TAX_RATE = 0.0434;
    double taxes = TAX_RATE * itemPrice;
    double shippingCost = calculateShippingCost(itemWeight);
    double totalCost = itemPrice + taxes + shippingCost;

    std::cout << "..." << std::endl;

    return 0;
}

double getValidatedInput(const std::string& prompt) {
    double validInput;
    do {
        std::cout << prompt;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K" << "Error! msg\n";
            std::cin.clear(); std::cin.ignore(1000, '\n');
            validInput = -1;}
    } while (validInput < 0);

    return validInput;
}

double calculateShippingCost(double itemWeight) {
    double rate;

    if (itemWeight < 1) rate = 10.0;
    else if (itemWeight <  5) rate = 7.0;
    else if (itemWeight <  8) rate = 5.0;
    else if (itemWeight < 10) rate = 3.0;
    else if (itemWeight < 20) rate = 2.0;
    else rate = 1.0; 

    return itemWeight * rate;
}