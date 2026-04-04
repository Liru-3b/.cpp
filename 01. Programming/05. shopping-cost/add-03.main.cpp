
/* 
Improvement:
    Using std::string_view instead of std::string&.
    Faster for literal strings, as it avoids making string objects.
*/

#include <string>
#include <string_view>
#include <iomanip>
#include <iostream>

double gsc(double w);
double gvi(std::string_view l);

int main() {
    double p = gvi("Price: ");
    double w = gvi("Weight: ");

    const double TR = 0.0343;
    double t = TR * p;
    double s = gsc(w);
    double c = p + t + s;

    return 0;}

double gsc(double w) {
    double r;

    if (w < 1) r = 10.0;
    //   ...
    else r = 1.0;
    return w * r;}

double gvi(std::string_view l) {
    double v;
    do {
        std::cout << l;
        if (!(std::cin >> v) || v < 0) {
            std::cout << "\033[A\033[2K" "msg\n";
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            v = -1;}
    } while (v < 0);
    return v;}