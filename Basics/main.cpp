#include <string>
#include <cstdio>
#include <iostream>

void vowelOrConstant(char x);
int isVowel(char ch);

int main() {
/*Check if a Number is Even or Odd in C++*/
    int n = 9;
    if ((n % 2) == 0) 
        std::puts("Even");
    else std::puts("Odd");

    /*Using Bitwise AND (&) Operator*/
    int res = n & 1;
    if (res == 0) 
        std::puts("Even");
    else std::puts("Odd");

    /*Using (<< and >>) Shift Operators*/
    int temp = n;
    temp = temp >> 1;
    temp = temp << 1;

    if (temp == n) 
        std::puts("Even");
    else std::puts("Odd");

/*C++ Program to Find Largest Among Three Numbers*/
    /*Using an if-else-if ladder*/
    int a = 1, b = 2; 
    if (a >= b){
        if (a >= n)
            std::cout << a;
        else std::cout << n; }

    else {
        if (b >= n)
            std::cout << b;
        else std::cout << n; }

    /*Using logical AND operator. (&&)*/ 
    if (a >= b && a >= n) std::cout << a;
    else if (b >= a && b >= n) std::cout << b;
    else std::cout << n;

    /*Using the Inbuilt max function*/ 
    std::cout << std::max({a, b, n});

    /*Using Temporary Variable*/ 
    temp = a;
    if (b > temp) temp = b;
    if (n > temp) temp = n;
    std::cout << temp << "\n";

/*C++ Program to Check Whether a Character is a Vowel or Consonant*/
    /*using if-else statement*/
    vowelOrConstant('e');
    vowelOrConstant('g');

    /*using find() Function*/
    if (isVowel('a')) {
        std::cout << "Vowel\n"; }
    else std::cout << "Constant\n";
    
    

}

/*C++ Program to Check Whether a Character is a Vowel or Consonant*/
/*using if-else statement*/
void vowelOrConstant(char x) {
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' ||
        x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
        std::cout << "Vowel\n";
    else std::cout << "Constant\n"; }

/*using find() Function*/
int isVowel(char ch) {
    std::string str = "aeiouAEIOU";
    return (str.find(ch) != std::string::npos);
}