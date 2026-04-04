//*****************************************************************************************************
//              This program demonstrates the use of default arguments in a function.
//*****************************************************************************************************

#include <iostream>
#include <functional>
#include <vector>
#include <string>

using namespace std;

void displayMsg(const char msg[] = "Decide. Commit. Succeed.", char symbol = ' ', int num = 10);

int main() {
    displayMsg("I will decide.", '&', 15);
    displayMsg("I will commit.", '@');
    displayMsg("I will succeed.");
    displayMsg();

    return 0;}

//*****************************************************************************************************

void displayMsg(const char msg[], char symbol, int num) {
    /*Using Standard Library: Highly Efficient*/
    std::string pad(num, symbol);
    std::cout << pad << msg << pad << "\n";
        /* 
        Using std::printf -> 
            std::printf("%s %s %s \n", pad.c_str(), msg, pad.c_str());
        */

//*****************************************************************************************************

    /*Previously: High Efficiency*/
    // Task 1
    for (int i = 0; i < num; ++i) cout << symbol;

    // Task 2
    cout << msg;

    // Task 3
    for (int i = 0; i < num; ++i) cout << symbol;

    // Task 4
    cout << endl;

//*****************************************************************************************************

    /*Using Task Lists: Moderately Efficient. Very Specific Use-case*/
    std::vector<std::function<void()>> tasks;
    tasks.push_back([&]() { for (int i = 0; i < num; ++i) std::cout << symbol; });
    tasks.push_back([&]() { std::cout << msg; });
    tasks.push_back([&]() { for (int i = 0; i < num; ++i) std::cout << symbol; });

    for (const auto& task : tasks) 
        task();
    std::cout << std::endl; 
}

//*****************************************************************************************************
/*

&&&&&&&&&&&&&&&I will decide.&&&&&&&&&&&&&&&
@@@@@@@@@@I will commit.@@@@@@@@@@
          I will succeed.
          Decide. Commit. Succeed.

*/