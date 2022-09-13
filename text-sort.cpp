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

int line_counter(char* buffer, long size)
{
    int number_of_lines = 0;

    for(int i = 0; i < size; i++)
    {
        if (*(buffer + i) == '\n')
        {
            if (*(buffer + i - 1) != '\0')
                number_of_lines++;
            *(buffer + i) = '\0';
        }
    }

    return number_of_lines;
}

void Strings_Separator(char* buffer, long size, struct string Strings[])
{
    bool flag_in = false;
    int counter = 1;
    char* prev = buffer;

    for (int i = 0; i < size; i++)
    {
        if (*(buffer + i) == '\0')
        {
            if (*(buffer + i - 1) != '\0')
            {
                Strings[counter-1].length = buffer + i - prev;
                Strings[counter-1].ptr = prev + 1;
                prev = buffer + i;
                counter++;
            }
            else if (*(buffer + i - 1) == '\0')
                prev = buffer + i;
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

void FileWrite (char* text, struct string Strings[], int nlines, long size)
{
    FILE* f1 = fopen("Alphabet.txt", "w");

    qsort(Strings, nlines, sizeof(Strings[0]), &cmp);

    for (int i = 0; i < nlines; i++)
        fprintf(f1, "%s\n", Strings[i].ptr);

    fclose(f1);

    FILE* f2 = fopen("Rhymes.txt", "w");

    qsort(Strings, nlines, sizeof(Strings[0]), &reverse_cmp);

    for (int i = 0; i < nlines; i++)
        fprintf(f1, "%s\n", Strings[i].ptr);

    fclose(f2);

    FILE* f3 = fopen("Origin.txt", "w");

    for (int i = 0; i < size; i++)
    {
        if (*(text + i) == '\0')
            putc('\n', f3);
        else
            putc(*(text+i), f3);
    }

    fclose(f3);
}


