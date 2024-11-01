#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::min;

size_t lena(char* str)// типо  length
{
    size_t i = 0;
    while (*(str+i) != 0)
    {
        i++;
    }
    return i;
}

int amoreb(char* a, char* b) //типо  strcompare. возвращает числа больше нуля, если слово 'а' предшествует в лексографическом порядке слову 'b',
{// возвращает отрицательные в обратном случае, если возвращает ноль - то либо слова идентичны либо одна является продолжением другой
    
    for (int i = 0; i < min(lena(a), lena(b)); i++)
    {
        if (*(a + i) != *(b + i))
        {
            return *(b + i) - *(a + i);
        }
    }
    return 0;
}
void stringcopy(char* from, char* to)//  оно работает странно и я не понимаю почему
{
    size_t i = 0;
    while (*(from + i) != 0) {
        to[i] = from[i];
        i++;
    }
    to[i] = 0;
}
void swap(char* a, char* b)
{
    char* tmp = (char*)calloc(1, lena(a));
    stringcopy(a, &tmp[0]);
    stringcopy(b, a);
    stringcopy(&tmp[0], b);
}
int main()
{
    string slovo;
    std::vector<string> slovar;
    std::ifstream in("onegin.txt"); 
    if (in.is_open())
    {
        uint32_t i = 0;
        while (in >> slovo)
        {
            slovar.push_back(slovo);
            i++;
        }
    }
    in.close();  
    for (int i = 0; i < slovar.size(); i++) // пузырьковая сортировка (не бейте)
    { 
        for (int j = 0; j < slovar.size()-1; j++) 
        {
            if (amoreb(&slovar[j][0], &slovar[j + 1][0])<= 0)
            {
                if (amoreb(&slovar[j][0], &slovar[j+1][0]) == 0)
                {
                    if (lena(&slovar[j][0]) > lena(&slovar[j + 1][0])) //если первая строка является продолжением второй строки, то свапаем их
                    {
                        swap(&slovar[j][0], &slovar[j + 1][0]);
                    }
                }
                else 
                {
                    swap(&slovar[j][0], &slovar[j + 1][0]);
                }
            }
        }
    }



   for (uint32_t i = 0; i < slovar.size(); i++){cout << slovar[i] << endl;}
    /*string a = "rjaviy";
    string b = "odin";
    stringcopy(&a[0], &b[0]);
    cout << a << endl << b;*/
    return 0;
}

