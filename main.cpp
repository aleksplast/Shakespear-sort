#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "text-sort.h"
#include "my_qsort.h"

int main(int argc, char* argv[])
{
    const char* rhymes = "Rhymes.txt";
    const char* alphabet = "Alphabet.txt";
    const char* origin = "Origin.txt";

    char* output = NULL;
    char* input = NULL;

    int status = 0;

    Arguments(argc, argv, &input, &output);

    struct poem text = {NULL, 0, 0};

    TextReader(input, &text);

    struct line* Strings = NULL;

    Strings_Separator(text.ptr, text.size, text.nlines, &Strings);

    qsort(Strings, text.nlines, sizeof(Strings[0]), &cmp);

    FileWrite(output, Strings, text.nlines);

    my_qsort(Strings, text.nlines, sizeof(Strings[0]), &reverse_cmp);

    FileWrite(output, Strings, text.nlines);

    OriginWrite(output, text.ptr, text.size);

    free(text.ptr);
    free(Strings);

    return 0;
}
