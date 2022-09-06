#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "header.h"

#define MAXLINES 4459
#define MAXLENGHT 100

int main()
{
    FILE* fp = fopen("hamlet.txt", "r");
    char text[MAXLINES][MAXLENGHT];
    char* array[MAXLINES] = {};

    for (int i = 0; fgets(text[i], MAXLENGHT, fp) != NULL; i++){}

    for (int i = 0; i < MAXLINES; i++)
    {
        array[i] = text[i];
    }

    sort(array, MAXLINES);

    for (int i = 0; i < MAXLINES; i++)
        printf("%s", array[i]);
}
