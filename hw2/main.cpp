#include <iostream>
int main()
{
    int i1 = 1;
    int i2 = 2;
    char c1 = 'a';// ASCII = 61
    char c2 = '=';// ASCII = 97
    double d1 = 3/2;
    double d2 = 1/3;
    std::cout<< "int + int - " << i1+i2 << '\n';
    std::cout<< "int + char - " << i1+c2 << '\n';
    std::cout<< "char + char - " << c1+c2 << '\n';
    std::cout<< "double + double - " << d1+d2 << '\n';
    std::cout<< "double + char - " << d1+c2 << '\n';
    std::cout<< "double + int - " << d1+i2 << '\n';
}