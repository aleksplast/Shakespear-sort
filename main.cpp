#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

int main()
{
    FILE* fp = fopen("hamlet.txt", "r");

    if (fp == NULL)
    {
        printf("Error when reading a file");
        exit(1);
    }

    long size = file_size(fp);
    char* text = (char*) malloc(sizeof(char) * size);

    if (text == NULL)
    {
        printf("Error with memory");
        exit(2);
    }

    Input(text, size, fp);

    int nlines = line_counter(text, size);

    struct string Strings[nlines];

    char** LinesPtr = pointers_array(text, nlines, size);

    qsort(LinesPtr, nlines, sizeof(LinesPtr[0]), &cmp);

    for (int i = 0; i < nlines; i++)
    {
        printf("%s\n", LinesPtr[i]);
    }
    return 0;
}
