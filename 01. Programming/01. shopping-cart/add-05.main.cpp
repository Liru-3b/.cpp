
/*
Improvement:
    Converting Magic Numbers to Constant.
*/

#include <iomanip>
#include <iostream>
#include <string_view>

double calculateShippingCost(double itemWeight);
double getValidatedInput(std::string_view promptLabel);

int main() {
    std::cout << "Online Purchase Cost Calculator\n";
    std::cout << "-------------------------------\n";

    double itemPrice = getValidatedInput("Please Enter Price of Product: ");
    double itemWeight = getValidatedInput("Enter Product's Weight (lbs): ");

    const double TAX_RATE = 0.04343;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = calculateShippingCost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Invoice Summary ---"
              << "\n  Subtotal:  $" << itemPrice
              << "\n  Tax:       $" << itemTax
              << "\n  Shipping:  $" << itemShippingCost
              << "\n  ---------------------"
              << "\n  Total:     $" << itemTotalCost << std::endl;}

double calculateShippingCost(double itemWeight) {
    /* I converted Magic Numbers to constants*/
    const double  RATE_UNDER_1KG = 10.0;
    const double  RATE_UNDER_5KG = 8.0;
    const double RATE_UNDER_10KG = 6.0;
    const double RATE_UNDER_15KG = 4.0;
    const double RATE_UNDER_20KG = 2.0;
    const double DEFAULT_RATE = 1.0;

    double WeightRate;

    if (itemWeight < 1) WeightRate = RATE_UNDER_1KG;
    else if (itemWeight <  5) WeightRate = RATE_UNDER_5KG;
    else if (itemWeight < 10) WeightRate = RATE_UNDER_10KG;
    else if (itemWeight < 15) WeightRate = RATE_UNDER_15KG;
    else if (itemWeight < 20) WeightRate = RATE_UNDER_20KG;
    else WeightRate = DEFAULT_RATE;

    return itemWeight * WeightRate;}

double getValidatedInput(std::string_view promtLabel) {
    double validInput;

    do {
        std::cout << promtLabel;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K" 
            "Invalid! Should be a Positive Number!\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            validInput = -1;
        }} 
    while (validInput < 0);
    return validInput;}