#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include <algorithm>
#include "functions.h"
using std::cout;
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
    int i = -1;
    if (from != 0 && to != 0)
    {

        do
        {
            i++;
            if (*(to + i) - *(from + i) != 0)
            {
                return *(to + i) - *(from + i);
            }
        } while ((*(to + i) != 0) && (*(from + i) != 0));
    }
    else
    {
        cout << "strcompare get NULLPTR";
        return 0;
    }
    return 0;
    cout << "strcompare something went wrong";
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
