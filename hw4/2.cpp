#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
//#include "Source.cpp"
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::min;

size_t lena(char* str)// типо  length
{
    if (str == 0)
    {
        return -1;
    }
    else
    {
        size_t i = 0;
        while (*(str + i) != 0)
        {
            i++;
        }
        return i;
    }
}
int strcompare(char* from, char* to)
{
    int i = 0;
    if (from != 0 && to != 0)
    {

        do
        {
            if (*(to + i) - *(from + i) != 0)
            {
                return *(to + i) - *(from + i);
            }
            i++;
        } while ((*(to + i) != 0) && (*(from + i) != 0));
    }
    else
    {
        cout << "strcompare get NULLPTR";
        return 0;
    }
}
size_t preprocess(char* text) {
    if (text != 0)
    {
        bool is_newline = false;
        char* first_ptr = text;
        size_t lineCount = 0;
        for (first_ptr = text; *first_ptr != '\0'; ++first_ptr) {
            if (*first_ptr == '\r') {
                *first_ptr = '\n';
            }
        }
        first_ptr = text;
        for (char* second_ptr = text; *second_ptr != '\0'; ++second_ptr) {
            if (*second_ptr == '\n') {
                if (!is_newline) {
                    *first_ptr++ = '\n';
                    is_newline = true;
                }
            }
            else {
                *first_ptr++ = *second_ptr;
                is_newline = false;
            }
        }
        *first_ptr = '\0';
        for (first_ptr = text; *first_ptr != '\0'; ++first_ptr) {
            if (*first_ptr == '\n') {
                *first_ptr = '\0';
                lineCount++;
            }
        }
        return lineCount;
    }
    else
    {
        cout << "preprocess get NULLPTR";
        return 0;
    }
}
void fill_string_array(char* text_buf, size_t str_count, char** text)
{
    if (text_buf != 0 && text != 0)
    {
        text[0] = text_buf;
        for (int i = 1; i < str_count; i++)
        {
            int j = 0;
            while ((*(text[i - 1] + j)) != '\0') { j++; }
            text[i] = text[i - 1] + j + 1;
        }
    }
    else
    {
        cout << "fill_string_array get NULLPTR";
    }
}

int main()
{
    std::ifstream in("onegin.txt");
    size_t file_size = 0;
    in.seekg(0, std::ios::end);
    file_size = in.tellg();// 1) прочитали размер файла в байтах
    in.close();
    char* text_buf = (char*)calloc(1, file_size);// 2) выделяем память под буфер
    FILE* input = fopen("Onegin.txt", "r");
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