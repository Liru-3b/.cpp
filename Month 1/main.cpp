#include <iostream> // Header File
#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>

void Hello_World() {
    // (comment) This statement prints "Hello World"
    std::cout << "Hello World\n\n"; /* This is a statement*/}

void My_Name() {
    std::cout << "1. Brian\n";

    /* Other Ways to Print: */
    std::printf("2. Brian\n");
    std::puts("3. Brian");
    std::wcout << "4. Brian\n\n"; /*Inserts '\n' at the start*/

    /* Taking Input*/
    std::string str;
    std::cout << "Input string: "; std::cin >> str;
    std::cout << "Output string: " << str << "\n\n";}

void Input() {
    /* 1. Using cin (Standard Input Stream)*/
    int i; 
    std::cout << "Input Number: "; std::cin >> i; 
    std::cout << "Output Number: " << i << "\n\n";

    /*2. Multiple Inputs with cin*/
    std::string name; int age;
    std::cout << "Enter Name and Age: ";
    std::cin >> name >> age;
    /*To handle inputs with spaces, use:
    std::getline(std::cin, name)*/ 
    // std::getline(std::cin, name); 
    
    std::cout << "Name: " << name 
    << " | Age: " << age << "\n";
   
    /*Alternatively: */
    std::printf("Name: %s |", name.c_str()); 
    std::printf(" Age: %d \n\n", age);}

void Adding_Numbers() {
    /*Using Addition Operator*/
    int a = 11, b = 9;
    std::printf("Using Addition Operator: %d \n", (a+b));
    /*Time/Space complexity: O(1)*/

    /*Using the Increment Operator*/
    for (int i=0; i<b/*Positive*/; i++) {a++;}
    for (int i=0; i>b/*Negative*/; i--) {a--;}
    std::printf("Using (++/--) Operators: %d \n", a);
    /*Time Complexity: O(b), Space Complexity: O(1)*/

    /*Using Bitwise Operators*/
    int c/*Carry*/; 
    a = 11; b = 9;

    while (b) {
        c = a&b;
        a = a^b;
        b = c << 1;}

    std::printf("Using Bitwise Operators: %d \n\n", a);
    /*Time Complexity: O(log b), Space Complexity: O(1)*/}

void Swap_Numbers() {
    /*Using a Temporary Variable*/
    int a = 2, b = 3;
    std::printf("Before Swapping a = %d, b = %d \n", a, b);

    int temp; 
    temp = a;
    a = b; 
    b = temp;
    std::printf("After Swapping a = %d, b = %d \n\n", a, b);

    /*Without Using a Temporary Variable*/
    a = 2; b = 3;
    std::printf("Before Swapping a = %d, b = %d \n", a, b);

    b = a + b;
    a = b - a;
    b = b - a;
    std::printf("After Swapping a = %d, b = %d \n\n", a, b);

    /*Using the In-built Function, swap(a, b)*/
    a = 5, b = 10;
    std::printf("Before Swapping a = %d, b = %d \n", a, b);
    std::swap(a, b);
    std::printf("After Swapping a = %d, b = %d \n\n", a, b);}

void Find_Size() {
    /*Finding the size of Data Types*/
    int integerType;
    char charType;
    float floatType;
    double doubleType;

    std::cout << "Size of int is: " 
    << sizeof(integerType) << " Bytes\n";
    
    std::cout << "Size of char is: " 
    << sizeof(charType) << " Bytes\n";
    
    std::cout << "Size of float is: " 
    << sizeof(floatType) << " Bytes\n";
    
    std::cout << "Size of double is: " 
    << sizeof(doubleType) << " Bytes\n\n";}

float mul_floats(float a, float b) {
    return a * b;}

void Mult_Floats() {
    float A = 1.2, B = 3.0, product;
    product = mul_floats(A, B);
    std::cout << product;
    /*Time/Space Complexity: O(1)*/}

void Ascii_Values() {
    /*Using Format Specifier*/
    char c = 'k';
    std::printf("The ASCII value of %c is %d \n", c, c);
    /*Time/Space Complexity: O(1)*/

    /*Using Explicit Typecasting*/
    char ch = 'A';
    int asciiValue = (int)ch;
    std::printf("ASCII value of %c is %d \n\n", ch, asciiValue);
    /*Time/Space Complexity: O(1)*/}

float Conversion(float n) {
    return (n - 32.0) * 5.0 / 9.0;}

void Temp_Conversion() {
    float n = 40;
    std::printf("40 To Fahrenheit: %f \n\n", Conversion(n));
    /*Time/Space Complexity: O(1)*/}

void Simple_Interest() {
    float principal = 1, rate = 1, time = 1;
    float simpleInterest = (principal * time * rate) / 100;
    std::cout << "Simple Interest = " << simpleInterest << "\n";
    // std::printf("Simple Interest = %f", SI);
    /*Time/Space Complexity: O(1)*/}

void Compound_Interest() {
    double principal = 10000, rate = 5, time = 2;
    double amount = principal * (std::pow((1 + rate / 100), time));
    double compoundInterest = amount - principal;

    std::cout << "Compound Interest is " << compoundInterest << "\n\n";
    /*Time Complexity: O(n), Space Complexity: O(1)*/}

int areaRect(int a, int b) {
    int area = a * b; 
    return area;}

int perimeterRect(int a, int b) {
    int perimeter = 2 * (a + b);
    return perimeter;}

void Area_Perimeter() {
    int a = 5, b = 6;

    std::printf("Area = %d \n", areaRect(a, b));
    std::printf("Perimeter = %d \n\n", perimeterRect(a, b));
    /*Time/Space Complexity: O(1)*/}

int main() { // Execution begins at Main
    Hello_World();
    My_Name();
    Input();
    Adding_Numbers();
    Swap_Numbers();
    Find_Size();
    Ascii_Values();
    Temp_Conversion();
    Simple_Interest();
    Compound_Interest();
    Area_Perimeter();
    return 0;}