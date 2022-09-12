#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

long file_size(FILE *fp)
{
    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    return size;
}

char* Input(char* buffer, long size, FILE *fp)
{
    fread(buffer, 1, size, fp);
}

int line_counter(char* buffer, long size)
{
    int number_of_lines = 0;

    for(int i = 0; i < size; i++)
    {
        if (*(buffer + i) == '\n')
        {
            number_of_lines++;
            *(buffer + i) = '\0';
        }
    }

    return number_of_lines;
}

void Strings_Separator(char* buffer, int nlines, long size, struct string Strings[])
{
    bool flag_in = false;
    int counter = 1;
    char* prev = buffer;

    Strings[0].ptr = buffer;

    for (int i = 0; i < size; i++)
    {
        if (*(buffer + i) == '\0')
        {
            Strings[counter-1].length = buffer + i - prev;
            Strings[counter].ptr = buffer + i + 1;
            prev = buffer + i;
            counter++;
        }
    }
}

int cmp(const void* struct1ptr, const void* struct2ptr)
{
    const struct string struct1 = *(const struct string*) struct1ptr;
    const struct string struct2 = *(const struct string*) struct2ptr;

    const char* str1 = struct1.ptr;
    const char* str2 = struct2.ptr;

    while(!(isalpha(*str1)))
        str1++;

    while(!(isalpha(*str2)))
        str2++;

    for( ; *str1 == *str2; str1++, str2++)
    {
        if (*str1 == '\0')
            return 0;
    }
    if (*str1 > *str2)
        return 1;
    else
        return -1;
}

int reverse_cmp(const void* struct1ptr, const void* struct2ptr)
{
    const struct string struct1 = *(const struct string*) struct1ptr;
    const struct string struct2 = *(const struct string*) struct2ptr;

    const char* str1 = struct1.ptr + struct1.length;
    const char* str2 = struct2.ptr + struct2.length;

    while(!(isalpha(*str1)))
        str1--;

    while(!(isalpha(*str2)))
        str2--;

    for( ; *str1 == *str2; str1--, str2--)
    {
        if (*str1 == '\0')
            return 0;
    }
    if (*str1 > *str2)
        return 1;
    else
        return -1;
}


