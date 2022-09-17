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

    const char* output = "Output.txt";
    const char* input = "hamlet.txt";

    const char* mode = "r";
    const char end = '\n';
    char step = 1;

    struct poem text = {NULL, 0, 0, NULL};

    TextReader(input, &text, mode);

    Strings_Separator(&text, end);

    my_qsort_r(text.Strings, text.nlines, sizeof(text.Strings[0]), &cmp, &step);

    FileWrite(output, text.Strings, text.nlines);

    //change direction

    step = -1;
    my_qsort_r(text.Strings, text.nlines, sizeof(text.Strings[0]), &cmp, &step);

    FileWrite(output, text.Strings, text.nlines);

    OriginWrite(output, text.ptr, text.size);

    free(text.ptr);
    free(text.Strings);

    return 0;
}
