#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

int main()
{
    FILE* fp = fopen("hamlet.txt", "r");

    long size = file_size(fp);
    char* text = (char*) malloc(sizeof(char) * size);

    fread(text, 1, size, fp);

    fclose(fp);

    int nlines = line_counter(text, size);

    struct string Strings[nlines];

    Strings_Separator(text, size, Strings);

    FileWrite(text, Strings, nlines, size);

    return 0;
}
