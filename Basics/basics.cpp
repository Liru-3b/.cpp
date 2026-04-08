
#include <string> /*std::getline*/
#include <vector>
#include <format>
#include <cstdio>
#include <iostream>

/*Function Prototypes
... Operator Overloading*/

int add(int a, int b);
int add(int a, int b, int c);
double add(double a, double b);

int main() {

/* Methods of Printing to the Console */
    std::cout <<"Hello, World!    std::cout\n";
    std::puts(  "Hello, World!    std::puts");
    std::printf("Hello, World!    std::printf \n");
    std::cout << std::format("Hello, World!"
            "    std::cout << std::format\n");

/* Getting Multiple Inputs with std::getline */
    std::string line;
    std::vector<std::string> inputs;

    do {
        std::cout << "Inputs: ";
        inputs.push_back(line) ;
                               }
        while (
            std::getline(std::cin, line) 
            && !line.empty()
    );

/* Using Addition Operator */
    int a = 11, b = 9;
    int c = add(a, b);
    int d = add(a, b, c);

    double m = 1.3, n = 0.7;
    double o = add(m, n);

    std::cout 
    <<  "\na = 11, b = 9"
        "\nadd(a, b) = "    << c 

    <<  "\n\na = 11, b = 9, c = 20"
        "\nadd(a, b, c) = " << d

    <<  "\n\nm = 1.345, n = 0.655"
        "\nadd(m, n) = "    << o;
}

/*Operator Overloading*/
int add(int a, int b) { return a + b; }

int add(int a, int b, int c) { return a + b + c; }

double add(double a, double b) { return a + b; }            


/*
Programming Language: C++
1. What's inside the <iostream> Header File?
2. What are the various Methods of Printing to the conscole, and why would one use one over the other?
3. What is the arguemnt list for std::geline (and it's various overloads)
4. Is it possible to take multiple inputs using std::getline?
5. How to create a function and overload it?

0. What is the purpose of Swapping values. Real-World use-case.
1. When swapping, is there an instance where using a temporary value is better that using std::swap?
2. What is typecasting (and various methods to implement it) 
3. What are the various sizes of data types?
4. What are the various operators used?
*/