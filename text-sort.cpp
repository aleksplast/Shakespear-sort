#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>

#include "text-sort.h"

long file_size(FILE *fp)
{
    assert(fp != NULL);

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);
    return size;
}

int line_counter(char* text, long size)
{
    assert(text != NULL);

    int number_of_lines = 0;

    for(int i = 0; i < size; i++)
    {
        if (*(text + i) == '\n')
        {
            if (*(text + i - 1) != '\n')
                number_of_lines++;
        }
    }

    return number_of_lines;
}

int Strings_Separator(char* text, long size, int nlines, struct line** Strings)
{
    *Strings = (struct line*) malloc(sizeof(struct line) * nlines);

    assert(text != NULL);
    assert(Strings != NULL);

    if (*Strings == NULL)
    {
        return SEPARMEMERR;
    }

    int counter = 1;
    char* prev = text;

    for (int i = 0; i < size && counter < nlines + 1; i++)
    {
        if (*(text + i) == '\n')
        {
            *(text + i) = '\0';
            if (*(text + i - 1) != '\0')
            {
                (*Strings)[counter-1].length = text + i - prev;
                (*Strings)[counter-1].ptr = prev + 1;
                prev = text + i;
                counter++;
            }
            else
                prev = text + i;
        }
    }

    return NOERR;
}

int cmp(const void* struct1ptr, const void* struct2ptr)
{
    assert(struct1ptr != NULL);
    assert(struct2ptr != NULL);

    const struct line struct1 = *(const struct line*) struct1ptr;
    const struct line struct2 = *(const struct line*) struct2ptr;

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
    assert(struct1ptr != NULL);
    assert(struct2ptr != NULL);

    const struct line struct1 = *(const struct line*) struct1ptr;
    const struct line struct2 = *(const struct line*) struct2ptr;

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

int FileWrite (const char* file, struct line Strings[], int nlines)
{
    FILE* f = fopen(file, "a");

    assert(f != NULL);
    assert(Strings != NULL);

    if (f == NULL)
    {
        return OUTPUTERR;
    }

    for (int i = 0; i < nlines; i++)
        fprintf(f, "%s\n", Strings[i].ptr);

    fclose(f);

    return NOERR;
}

int OriginWrite(const char* file, char* text, long size)
{
    FILE* f = fopen(file, "a");

    assert(f != NULL);
    assert(text != NULL);

    if (f == NULL)
    {
        return OUTPUTORERR;
    }

    for (int i = 0; i < size; i++)
    {
        if (*(text + i) == '\0')
            putc('\n', f);
        else
            putc(*(text + i), f);
    }

    fclose(f);

    return NOERR;
}

int TextReader (const char* file, struct poem* text)
{
    FILE* fp = fopen(file, "r");

    assert(fp != NULL);

    if (fp == NULL)
    {
        return INPUTERR;
    }

    (*text).size = file_size(fp);
    (*text).ptr = (char*) malloc(sizeof(char) * (*text).size);

    assert((*text).ptr != NULL);

    if ((*text).ptr == NULL)
    {
        return INPUTMEMERR;
    }

    fread((*text).ptr, 1, (*text).size, fp);

    (*text).nlines = line_counter((*text).ptr, (*text).size);

    fclose(fp);

    return NOERR;
}

void my_qsort(void* base, int nmemb, size_t size, int (*CompFunc)(const void*, const void*))
{
    assert(base != NULL);

    void* left = base;

    if (nmemb == 1 || nmemb == 0)
        return;

    swap(left, (left + size * (int)(nmemb/2)), size);

    void* current = left;
    int counter = 0;

    for (int i = 1; i < nmemb; i++)
    {
        if ((*CompFunc) (base + i * size, base) < 0)
        {
            current += size;
            swap(current, base + i * size, size);
            counter++;
        }
    }

    swap(left, current, size);

    current += size;

    my_qsort(base, counter, size, CompFunc);
    my_qsort(current, nmemb - counter - 1, size, CompFunc);
}

void swap(void* elem1ptr, void* elem2ptr, size_t size)
{
    assert(elem1ptr != NULL);
    assert(elem2ptr != NULL);

    char* elem1 = (char*) elem1ptr;
    char* elem2 = (char*) elem2ptr;

    for (int i = 0; i < size; i++)
    {
        char temp = *elem1;
        *elem1 = *elem2;
        *elem2 = temp;
        elem1++;
        elem2++;
    }
}

void Arguments(int argc, char** argv, char** input, char** output)
{
    if (argc == 1 || (argc != 3 && strcmp("--help", argv[1]) != 0))
    {
        printf("Enter --help to get info how the programm works");
        exit(2);
    }
    else if (strcmp("--help", argv[1]) == 0)
    {
        printf("Please, enter two file names:\nFirst name of original text, second name of file to write into");
        exit(1);
    }
    else
    {
        *input = argv[1];
        *output = argv[2];
    }
}
