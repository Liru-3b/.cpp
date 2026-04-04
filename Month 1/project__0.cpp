#include <iostream>
#include <cstdio>
#include <cmath>

// Concept: Function with return and arithmetic (from Area_Perimeter)
double CalculatePropertyScore(int area, int perimeter) {
    return (double)(area + perimeter) / 2.0;}

// Concept: Bitwise Addition logic (from Adding_Numbers)
int GenerateSecurityKey(int a, int b) {
    int carry;
    while (b) {
        carry = a & b;
            a = a ^ b;
        b = carry << 1;}
    return a;}

// Concept: Using Math library and Double precision (from Compound_Interest)
void WealthProjection(double principal, double rate, double years) {
    double total = principal * (std::pow((1 + rate / 100), years));
    double interest = total - principal;
    
    std::printf("--- Investment Forecast ---\n");
    std::printf("Initial Investment: $%.2f\n", principal);
    std::printf("Interest Earned: $%.2f\n", interest);
    std::printf("Total Value: $%.2f\n\n", total);}

int main() {
    // Concept: String and basic I/O (from My_Name and Input)
    std::string ownerName; int age;
    std::cout << "--- Digital Asset Manager ---\n";
    std::cout << "Enter Owner Name: "; std::cin >> ownerName;
    std::cout << "Enter Owner Age: "; std::cin >> age;

    // Concept: Complex arithmetic and input (from Area_Perimeter)
    int length, width;
    std::cout << "\n--- Property Dimensions ---\n";
    std::cout << "Enter Length and Width: ";
    std::cin >> length >> width;

    // Concept: Multiple Output styles (from My_Name and Ascii_Values)
    int area = length * width;
    int perimeter = 2 * (length + width);
    double score = CalculatePropertyScore(area, perimeter);

    std::printf("\nProperty Summary for %s:\n", ownerName.c_str());
    std::cout << "1. Area: " << area << " sq units\n";
    std::cout << "2. Perimeter: " << perimeter << " units\n";
    std::printf("3. Property Utility Score: %.2f\n\n", score);

    // Concept: Compound Interest Logic
    WealthProjection(5000.0, 7.5, 10.0);

    // Concept: Typecasting and Char manipulation (from Ascii_Values)
    char secretSeed = ownerName[0];
    int seedVal = (int)secretSeed;
    int securityKey = GenerateSecurityKey(seedVal, age);

    // Concept: Sizeof logic (from Find_Size)
    std::cout << "--- System Metadata ---\n";
    std::printf("Security Key Generated: %d\n", securityKey);
    std::cout << "Data Integrity Check: " << sizeof(securityKey) << " bytes processed.\n";
    
    return 0;
}