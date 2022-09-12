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

void sort(char* array[], int lenght)
{
    for (int i = 0; i < lenght; i++)
    {
        for (int j = 0; j < lenght - i - 1; j++)
        {
            if (strcmp(array[j], array[j+1]) > 0)
            {
                char* temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
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

char**  pointers_array(char* buffer, int nlines, long size)
{
    char** array = (char**) malloc(sizeof(char*) * nlines);
    bool flag_in = false;
    int counter = 0;

    for (int i = 0; i < size; i++)
    {
        if (flag_in == false)
        {
            flag_in = true;
            array[counter] = buffer + i;
            counter++;
        }
        if (*(buffer + i) == '\0')
        {
            flag_in = false;
        }
    }

    return array;
}

int cmp(const void* str1ptr, const void* str2ptr)
{
    const char* str1 = *(const char**) str1ptr;
    const char* str2 = *(const char**) str2ptr;

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
