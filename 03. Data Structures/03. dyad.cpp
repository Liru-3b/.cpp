//*****************************************************************************************************
//      This program demonstrates the use of the Dyad class by instantiating 
//      objects of type int, double, and char and performing its methods.
//*****************************************************************************************************

#include <iostream>
#include <utility> // For std::swap
#include <string>

/*Class Template Definition*/
template <typename T>
class Dyad {
private:
    T val1;
    T val2;

public:
    // Uses member initializer list for better efficiency
    Dyad(T v1 = T(), T v2 = T()) : val1(v1), val2(v2) {}

    // Getters marked as const
    T getFirst() const { return val1; }
    T getSecond() const { return val2; }

    // Swaps the internal values using standard library utility
    void swapValues() {std::swap(val1, val2);}

    // Passes values back to the caller via references
    void get2Values(T &v1, T &v2) const {
        v1 = val1; v2 = val2;}

    // Helper method to reduce code duplication in main
    void print(const std::string& label) const {
        std::cout << label << " Values: [" 
            << val1 << ", " << val2 << "]\n";
    }};

int main() {
    // 1. Integers
    Dyad<int> dyadInt(1, 2);
    dyadInt.print("Initial Int");
    dyadInt.swapValues();
    
    int i1, i2;
    dyadInt.get2Values(i1, i2);
    std::cout << "After Swap: First = " 
    << i1 << ", Second = " << i2 << "\n\n";

    // 2. Doubles
    Dyad<double> dyadDouble(1.5, 2.5);
    dyadDouble.print("Initial Double");
    dyadDouble.swapValues();
    
    double d1, d2;
    dyadDouble.get2Values(d1, d2);
    std::cout << "After Swap: First = " 
    << d1  << ", Second = " << d2 << "\n\n";

    // 3. Chars
    Dyad<char> dyadChar('A', 'B');
    dyadChar.print("Initial Char");
    dyadChar.swapValues();
    
    char c1, c2;
    dyadChar.get2Values(c1, c2);
    std::cout << "After Swap: First = " 
    << c1  << ", Second = " << c2 << "\n";

    return 0;
}//*****************************************************************************************************
