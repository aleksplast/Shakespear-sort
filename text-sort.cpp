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

int line_counter(char* text, long size)
{
    int number_of_lines = 0;

    for(int i = 0; i < size; i++)
    {
        if (*(text + i) == '\n')
        {
            if (*(text + i - 1) != '\0')
                number_of_lines++;
            *(text + i) = '\0';
        }
    }

    return number_of_lines;
}

void Strings_Separator(char* text, long size, int nlines, struct string* Strings)
{
    if (Strings == NULL)
    {
        fprintf(stderr, "Not enought memory\n");
        exit(EXIT_FAILURE);
    }

    int counter = 1;
    char* prev = text;

    for (int i = 0; i < size; i++)
    {
        if (*(text + i) == '\0')
        {
            if (*(text + i - 1) != '\0')
            {
                if (counter >= nlines)
                    realloc(Strings, counter * sizeof(struct string));
                        if (Strings == NULL)
                        {
                            fprintf(stderr, "Not enought memory\n");
                            exit(EXIT_FAILURE);
                        }
                Strings[counter-1].length = text + i - prev;
                Strings[counter-1].ptr = prev + 1;
                prev = text + i;
                counter++;
            }
            else
                prev = text + i;
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

void FileWrite (const char* file, struct string Strings[], int nlines)
{
    FILE* f = fopen(file, "w");

    if (f == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < nlines; i++)
        fprintf(f, "%s\n", Strings[i].ptr);

    fclose(f);
}

void OriginWrite(const char* file, char* text, long size)
{
    FILE* f = fopen(file, "w");

    if (f == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", file);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++)
    {
        if (*(text + i) == '\0')
            putc('\n', f);
        else
            putc(*(text + i), f);
    }

    fclose(f);
}

struct poem TextReader (const char* file)
{
    FILE* fp = fopen(file, "r");

    if (fp == NULL)
    {
        fprintf(stderr, "Cannot open %s\n", file);
        exit(EXIT_FAILURE);
    }

    struct poem text = {NULL, 0, 0};

    text.size = file_size(fp);
    text.ptr = (char*) malloc(sizeof(char) * text.size);

    if (text.ptr == NULL)
    {
        fprintf(stderr, "Not enought memory\n");
        exit(EXIT_FAILURE);
    }

    fread(text.ptr, 1, text.size, fp);

    text.nlines = line_counter(text.ptr, text.size);

    fclose(fp);

    return text;
}
