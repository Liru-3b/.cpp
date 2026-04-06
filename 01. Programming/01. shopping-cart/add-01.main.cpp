/*
Improvement: 
    Initialize Variables Immediately to Prevent Garbage Values.
*/

#include <string>
#include <iostream>
#include <iomanip>

double getShippingcost(double weight);
double validateInput(const std::string& prompt);

int main() {
    std::cout << "Presentation: " << '\n';

    /* I Initialized Values Imediately! 
    Instead of double price, weight, taxs etc., */

    double price = validateInput("...");
    double weight = validateInput("...");
    
    const double TAX_RATE = 0.045;
    double taxs = TAX_RATE * price;
    double ship = getShippingcost(weight);
    double cost = price + taxs + ship;

    std::cout << "Transaction Receipt: " << std::endl;

    return 0;
}

double validateInput(const std::string& prompt) {
    double value;
    do {
        std::cout << prompt;
        if (!(std::cin >> value) || value < 0) {
            std::cout // Clear the Previous Line
                << "\033[A\033[2K"; 

            std::cout << "Error! msg\n";
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');
            value = -1;}
    } while (value < 0);
    
    return value;
}

double getShippingcost(double weight) {
    double rate;

    if (weight < 1) rate = 10.0;
    else if (weight <  5) rate = 7.0;
    else if (weight <  8) rate = 5.0;
    else if (weight < 10) rate = 3.0;
    else if (weight < 20) rate = 2.0;
    else rate = 1.0; 

    return rate * weight;
}