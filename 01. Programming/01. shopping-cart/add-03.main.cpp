/* 
Improvement:
    Using std::string_view instead of std::string&.
    Faster for literal strings, as it avoids making string objects.
*/

#include <string>
#include <string_view>
#include <iomanip>
#include <iostream>

double getshippingcost(double itemWeight);

/* I made the Improvement Here */
double getValidInput(std::string_view promptLabel);

int main() {
    double itemPrice = getValidInput("Price: ");
    double itemWeight = getValidInput("Weight: ");

    const double TAX_RATE = 0.0343;
    double itemTax = TAX_RATE * itemPrice;
    double itemShippingCost = getshippingcost(itemWeight);
    double itemTotalCost = itemPrice + itemTax + itemShippingCost;

    return 0;
}

/* I also made the Improvement Here */
double getValidInput(std::string_view promptLabel) {
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

double getshippingcost(double itemWeight) {
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