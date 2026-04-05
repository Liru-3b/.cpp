
/*
Improvement: 
    Removing the exit  function (return 0).
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
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;}

double getValidatedInput(std::string_view promptLabel) {
    double validInput;
    
    do {
        std::cout << promptLabel;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K"  "msg\n";
            std::cin.clear();
            std::cin.ignore();
            validInput = -1;
        }
    } while (validInput < 0);
    return validInput;}

double calculateShippingCost(double itemWeight) {
    double itemWeightRate;

    if (itemWeight < 1) itemWeightRate = 10.0;
    else if (itemWeight < 5) itemWeightRate = 7.0;
    // ...
    else itemWeightRate = 1.0;
    return itemWeight * itemWeightRate;
}