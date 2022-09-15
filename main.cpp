#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "header.h"

int main()
{
    const char* rhymes = "Rhymes.txt";
    const char* alphabet = "Alphabet.txt";
    const char* poem = "hamlet.txt";
    const char* origin = "Origin.txt";

    struct poem text = TextReader(poem);

    struct string* Strings = (struct string*) malloc(sizeof(struct string) * text.nlines);

    Strings_Separator(text.ptr, text.size, text.nlines, Strings);

    qsort(Strings, text.nlines, sizeof(Strings[0]), &cmp);

    FileWrite(alphabet, Strings, text.nlines);

    qsort(Strings, text.nlines, sizeof(Strings[0]), &reverse_cmp);

    FileWrite(rhymes, Strings, text.nlines);

    OriginWrite(origin, text.ptr, text.size);

    free(text.ptr);
    free(Strings);

    return 0;
}
