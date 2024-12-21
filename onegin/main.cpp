#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include "functions.h"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::min;


int main()
{
    std::ifstream in("onegin.txt");
    size_t file_size = 0;
    in.seekg(0, std::ios::end);
    file_size = in.tellg();// 1) прочитали размер файла в байтах
    in.close();
    char* text_buf = (char*)calloc(1, file_size);// 2) выделяем память под буфер
    FILE* input = fopen("Onegin.txt", "rb");
    fread(text_buf, file_size, 1, input);// 3) скопироваkb файл с диска в буффер в оперативной памяти
    fclose(input);
    size_t str_count = preprocess(text_buf); //4) препроцессинг 
    char** text = (char**)calloc(1, str_count); //5) завели массив
    fill_string_array(text_buf, str_count, text);//6) заполняем массив
    cout << "\nunsorted text: \n\n";
    for (int i = 0; i < str_count; i++)// выводим неотсортированный текст
    {
        cout << (text[i]) << endl;
    }
    //7) сортируем
    for (int i = 0; i < str_count; i++)
    {
        for (int j = 0; j < str_count - 1; j++)
        {
            if (strcompare(text[j], text[j + 1]) < 0)
            {
                char* tmp = text[j];
                text[j] = text[j + 1];
                text[j + 1] = tmp;
            }
        }
    }
    cout << "\nsorted text: \n\n";
    for (int i = 0; i < str_count; i++)// выводим отсортированный текст
    {
        cout << (text[i]) << endl;
    }
    return 0;
}