/* Name: Liru-3b | Title: Shopping Cart
Description: Calculates Cost from std::cin

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
    . cout msg. clear input buffer.
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
    // cout Presentation
    std::cout << "Online Purchase Cost Calculator\n";
    std::cout << "-------------------------------\n";

    const double TAX_RATE = 0.04225;
    double price, weight, taxes, shipping, totalCost;
    
    // get inputs (price, weight)
    price = getInput("Please Enter Price of Product: ");
    weight = getInput("Enter Product's Weight (lbs): ");

    // get values (tax, shipping)
    taxes = price * TAX_RATE;
    shipping = calcShipping(weight);
    totalCost = price + taxes + shipping;

    // cout Transaction Receipt
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "\n--- Invoice Summary ---"
              << "\n  Subtotal:  $" << price
              << "\n  Tax:       $" << taxes
              << "\n  Shipping:  $" << shipping
              << "\n  ---------------------"
              << "\n  Total:     $" << totalCost << std::endl;

    return 0;
}

// Validate Input: (s)prompt
double getInput(const std::string& prompt) {
    double value; // (d)value

    do { /*while (value < 0)*/
        std::cout << prompt;

        // If not present OR positive. 
        if (!(std::cin >> value) || value < 0) {

            // cout msg. 
            std::cout << "Invalid! Should be a Positive Number!\n";

            // clear input buffer.
            std::cin.clear(); std::cin.ignore(1000, '\n');

            /*Force continue*/ value = -1;
        }

    } while (value < 0); 

    return value;
}

// Get Shipping Cost: (d) Weight
double calcShipping(double weight) {
    double rate; // (d) rate

    // If-chain over range [1, 20]
    if (weight < 1) rate = 10.0;
    else if (weight <  5) rate = 7.0;
    else if (weight <  8) rate = 5.0;
    else if (weight < 10) rate = 3.0;
    else if (weight < 20) rate = 2.0;
    else rate = 1.0; 

    return weight * rate;
}