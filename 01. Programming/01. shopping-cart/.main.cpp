
/*Online Purchase Cost Calculator*/
// Calculates total cost based on price and weight 

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
    . Cout msg. clear cin inputs.
    . Force continue (value = -1)
    
Get Shipping Cost (d): Weight, rate
    . If-chain over range [1, 20]
*/

#include <string>
#include <iomanip>
#include <iostream>

double calcShipping(double weight);
double getInput(const std::string& prompt);

int main() {
    std::cout << "Online Purchase Cost Calculator\n";
    std::cout << "-------------------------------\n";

    const double TAX_RATE = 0.04225;
    double price, weight, taxes, shipping, totalCost;
    
    price = getInput("Please Enter Price of Product: ");
    weight = getInput("Enter Product's Weight (lbs): ");

    taxes = price * TAX_RATE;
    shipping = calcShipping(weight);
    totalCost = price + taxes + shipping;

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Invoice Summary ---"
              << "\n  Subtotal:  $" << price
              << "\n  Tax:       $" << taxes
              << "\n  Shipping:  $" << shipping
              << "\n  ---------------------"
              << "\n  Total:     $" << totalCost << std::endl;

    return 0;}

double calcShipping(double weight) {
    double rate;

    if (weight < 1) rate = 10.0;
    else if (weight <  5) rate = 7.0;
    else if (weight <  8) rate = 5.0;
    else if (weight < 10) rate = 3.0;
    else if (weight < 20) rate = 2.0;
    else rate = 1.0; return weight * rate;}

double getInput(const std::string& prompt) {
    double value;

    do {
        std::cout << prompt;
        if (!(std::cin >> value) || value < 0) {
            std::cout << 
            "Invalid! Should be a Positive Number!\n";
            std::cin.clear(); std::cin.ignore(1000, '\n');
            value = -1;}
    } while (value < 0); 
    return value;}