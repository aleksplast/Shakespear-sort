void sort(char* array[], int lenght);

long file_size(FILE *fp);

char* Input(struct poem text, long size, FILE *fp);

int line_counter(char* text, long size);

void  Strings_Separator(char* text, long size, int nlines, struct string* Strings);

int cmp(const void* struct1ptr, const void* struct2ptr);

int reverse_cmp(const void* struct1ptr, const void* struct2ptr);

void FileWrite (const char* file, struct string Strings[], int nlines);

void OriginWrite(const char* file, char* text, long size);

struct poem TextReader (const char* file);

struct string {
    int length;
    char* ptr;
};

struct poem {
    char* ptr;
    long size;
    int nlines;
};

