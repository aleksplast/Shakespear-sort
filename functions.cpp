#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

#define MAXLINES 4459
#define MAXLENGHT 100

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

char* Gets(FILE *fp)
{
    char str[MAXLENGHT] = "";
    fgets(str, MAXLENGHT - 1, fp);
    return strdup(str);
}
