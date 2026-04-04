//*****************************************************************************************************
//      This program demonstrates the use of function templates and function overloading 
//      which is used when the operations need to be different for different types of data.
//*****************************************************************************************************

#include <iostream>
#include <string>
#include <algorithm>
#include <typeinfo>

// Function Templates
template <typename T>
void getData(T &a, T &b);

template <typename T>
T findMax(const T &a, const T &b);

template <typename T>
void displayMax(const T &a, const T &b, const T &maxVal);

// Specialization/Overload for strings to handle input prompts specifically
void getData(std::string &a, std::string &b);

int main() {
    int i1, i2;
    double d1, d2;
    char c1, c2;
    std::string s1, s2;

    // Logic: Get Data
    getData(i1, i2);
    getData(d1, d2);
    getData(c1, c2);
    getData(s1, s2);

    // Logic: Find and Display Max
    displayMax(i1, i2, findMax(i1, i2));
    displayMax(d1, d2, findMax(d1, d2));
    displayMax(c1, c2, findMax(c1, c2));
    displayMax(s1, s2, findMax(s1, s2));

    return 0;}

// --- Implementation ---

template <typename T>
void getData(T &a, T &b) {
    std::cout << "\nEnter two " << typeid(T).name() << " values:\n";
    std::cout << "  First:  "; std::cin >> a;
    std::cout << "  Second: "; std::cin >> b;}

// Overload for strings to handle multi-word input properly
void getData(std::string &a, std::string &b) {
    std::cout << "\nEnter two strings:\n";
    std::cout << "  First:  "; 
    std::cin.ignore( // Clear buffer
        std::numeric_limits
        <std::streamsize>::max(), '\n'); 
   
    std::getline(std::cin, a);
    std::cout << "  Second: "; 
    std::getline(std::cin, b);}

template <typename T>
T findMax(const T &a, const T &b) {
    return std::max(a, b);}

template <typename T>
void displayMax(const T &a, const T &b, const T &maxVal) {
    std::cout
        << "\n--- Result (" << typeid(T).name() << ") ---"
        << "\n  A:   " << a
        << "\n  B:   " << b
        << "\n  Max: " << maxVal << std::endl;}

//*****************************************************************************************************