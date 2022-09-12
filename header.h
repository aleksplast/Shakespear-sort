void sort(char* array[], int lenght);

long file_size(FILE *fp);

char* Input(char* buffer, long size, FILE *fp);

int line_counter(char* buffer, long size);

char**  pointers_array(char* buffer, int nlines, long size);

int cmp(const void* str1ptr, const void* str2ptr);

struct string {
    int length;
    char* ptr;
};
