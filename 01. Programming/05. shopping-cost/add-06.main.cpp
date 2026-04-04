
/*
Improvement:
    Switched to constexpr: This tells the compiler 
    the value is known at compile-time, 
    allowing for better optimization.
*/

#include <iomanip>
#include <iostream>
#include <string_view>

double calculateShippingCost(double itemWeight);
double getValidInputs(std::string_view promptLabel);

int main() {
    double itemP = getValidInputs("...");
    double itemW = getValidInputs("...");

    /*I Switched to constexpr Here*/
    constexpr double TAX_RATE = 0.8985;
    double ItemT = TAX_RATE * itemP;
    double ItemS = calculateShippingCost(itemW);
    double itemC = itemP + ItemT + ItemS;}

double calculateShippingCost(double itemWeight) {
    double WeightRate;

    /*I Switched to constexpr Here as Well*/
    constexpr double  RATE_UNDER_1KG = 10.0;
    constexpr double  RATE_UNDER_5KG = 8.0;
    constexpr double RATE_UNDER_10KG = 6.0;
    constexpr double RATE_UNDER_15KG = 4.0;
    constexpr double RATE_UNDER_20KG = 2.0;
    constexpr double DEFAULT_RATE = 1.0;

    if (itemWeight < 1) WeightRate = RATE_UNDER_1KG;
    else if (itemWeight <  5) WeightRate = RATE_UNDER_5KG;
    else if (itemWeight < 10) WeightRate = RATE_UNDER_10KG;
    else if (itemWeight < 15) WeightRate = RATE_UNDER_15KG;
    else if (itemWeight < 20) WeightRate = RATE_UNDER_20KG;
    else WeightRate = DEFAULT_RATE;

    return itemWeight * WeightRate;}

double getValidInputs(std::string_view promptLabel) {
    double validInput;
    
    do {
        std::cout << promptLabel;
        if (!(std::cin >> validInput) || validInput < 0) {
            std::cout << "\033[A\033[2K" "msg\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            validInput = -1;
        }
    } while (validInput < 0);
    return validInput;
}
