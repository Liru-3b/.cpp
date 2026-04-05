
/*
Implementation Plan:
Imports: string, iomanip, iostream
Stuff Needed:
    . Inputs (d): Price, Weight
    . Taxes (d): Price * RATE
    . Shipping (d): Weight * rate

Main Body: 
    . cout Presentation
    . get inputs (price, weight)
    . get values (tax, shipping)
    . cost = price + tax + shipping
    . cout Transaction Receipt

Validate Input: (s)prompt, (d)value
    . If not present OR positive. 
    . cout msg. clear cin inputs.
    . Force continue (value = -1)
    
Get Shipping Cost (d): Weight, rate
    . if-chain over range [1, 20]
*/

#include <string>
#include <iomanip>
#include <iostream>

double shippingCost(double weight);
double validInputs(const std::string& prompt);

int main() {
    // cout Presentation
    std::cout << "Presentation\n";

    // Get Inputs
    double  price = validInputs("...");
    double weight = validInputs("...");

    // Get Values
    const double TAX_RATE = 0.0435;
    double taxs = TAX_RATE * price;
    double ship = shippingCost(weight);
    double cost = price + taxs + ship;

    // cout Transaction Receipt
    std::cout << "Transaction Receipt\n";

    return 0;
}

// Validate Inputs
double validInputs(const std::string& prompt) {
    double value;
    do {
        std::cout << prompt;
        // If not Present OR Positive
        if (!(std::cin >> value) || value < 0) {
            /*cout msg (clearing previous line)*/
            std::cout << "\033[A\033[2K"  "msg\n";
            // Clear cin inputs
            std::cin.clear(); 
            std::cin.ignore(1000, '\n');
            /*Force Continue*/value = -1;}
    } while (value < 0);
    return value;}

// Calculate Shipping Cost
double shippingCost(double weight) {
    double rate;

    // if-chain over range[1, 20]
    if (weight < 1) rate = 10.0;
    else if (weight <  5) rate = 7.0;
    /*.............................*/         
    else if (weight < 20) rate = 2.0;
    else rate = 1.0; return rate * weight;}