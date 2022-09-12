void sort(char* array[], int lenght);

long file_size(FILE *fp);

char* Input(char* buffer, long size, FILE *fp);

int line_counter(char* buffer, long size);

void  Strings_Separator(char* buffer, int nlines, long size, struct string Strings[]);

int cmp(const void* struct1ptr, const void* struct2ptr);

int reverse_cmp(const void* struct1ptr, const void* struct2ptr);

struct string {
    int length;
    char* ptr;
};
