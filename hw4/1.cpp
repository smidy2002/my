#include <iostream>
#include <string>
#include <cmath>
#include <stdio.h>
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main()
{
    char a = '1';
    char b = '2';
    char c = '3';
    printf(("%p %p %p"), a, b, c);// char'ы занимают 1 байт поэтому ожидаем что эта строка выведет 3 числа отличающихся на 1.
    // и действительо выводит 0000000000000031 0000000000000032 0000000000000033
    return 0;
}

