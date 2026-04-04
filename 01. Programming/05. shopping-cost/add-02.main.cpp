
/*
Improvement:
    Naming Clarity, making the code self-documenting.
*/

#include <string>
#include <iomanip>
#include <iostream>

double getValidatedInput(const std::string& prompt);
double calculateShippingCost(double itemWeight);

int main() {
    double itemPrice = getValidatedInput("...");
    double itemWeight = getValidatedInput("...");

    const double TAX_RATE = 0.0434;
    double taxes = TAX_RATE * itemPrice;
    double shippingCost = calculateShippingCost(itemWeight);
    double totalCost = itemPrice + taxes + shippingCost;

    return 0;}

double getValidatedInput(const std::string& prompt) {
    double validInput;
    do
    {
        std::cout << prompt;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K"  "msg";
            std::cin.clear(); std::cin.ignore(1000, '\n');
            validInput = -1;}
    } while (validInput < 0);
    return validInput;}

double calculateShippingCost(double itemWeight) {
    double weight_rate;

    if (itemWeight < 1) weight_rate = 10.0;
    // ...
    else weight_rate = 1.0;
    return itemWeight * weight_rate;}