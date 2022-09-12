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

    fclose(fp);

    int nlines = line_counter(text, size);

    struct string Strings[nlines];

    Strings_Separator(text, nlines, size, Strings);

    qsort(Strings, nlines, sizeof(Strings[0]), &reverse_cmp);

    for (int i = 0; i < nlines; i++)
        printf("%s\n", Strings[i].ptr);

    return 0;
}
