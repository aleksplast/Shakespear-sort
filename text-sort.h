#ifndef TEXTSORT_H
#define TEXTSORT_H

//!--------------------------------
//! @brief Used for determining file size
//! @param[in] fp Coefficient for input
//! @return Size of the file in bytes
//!--------------------------------
long file_size(FILE *fp);

//!--------------------------------
//! @brief Used for determining number of lines in text
//! @param[in] text Text for counting
//! @param[in] size Size of the text in bytes
//! @return Number of lines in text
//!--------------------------------
int line_counter(char* text, long size);

//!--------------------------------
//! @brief Separates strings in text into different structures
//! @param[in] text Text for separation
//! @param[in] size Size of text in bytes
//! @param[in] nlines Number of lines in text
//! @param[out] Strings Pointer to the array of structures, where strings contains
//! @return Number of error, if it happened
//!--------------------------------
int Strings_Separator(char* text, long size, int nlines, struct line** Strings);

//!--------------------------------
//! @brief Compares two structures from left to right
//! @param[out] struct1ptr Pointer to a first structure to compare
//! @param[out] struct1ptr Pointer to a second structure to compare
//! @return Negative value if struct2ptr appears before str1 in lexicographical order, Zero if struct1ptr and struct2ptr compare equal, Positive value if struct1ptr appears after struct2ptr in lexicographical order.
//!--------------------------------
int cmp(const void* struct1ptr, const void* struct2ptr);

//!--------------------------------
//! @brief Compares two structures from right to left
//! @param[out] struct1ptr Pointer to a first structure to compare
//! @param[out] struct1ptr Pointer to a second structure to compare
//! @return Negative value if struct2ptr appears before str1 in lexicographical order, Zero if struct1ptr and struct2ptr compare equal, Positive value if struct1ptr appears after struct2ptr in lexicographical order.
//!--------------------------------
int reverse_cmp(const void* struct1ptr, const void* struct2ptr);

//!--------------------------------
//! @brief Writes a sorted text into file
//! @param[in] file File to write into
//! @param[in] Strings Array to write from
//! @param[in] nlines Number of lines in text
//! @return Number of error, if it happened
//!--------------------------------
int FileWrite (const char* file, struct line Strings[], int nlines);

//!--------------------------------
//! @brief Writes an original text into file
//! @param[in] file File to write into
//! @param[in] Strings Array to write from
//! @param[in] nlines Number of lines in text
//! @return Number of error, if it happened
//!--------------------------------
int OriginWrite(const char* file, char* text, long size);

//!--------------------------------
//! @brief Reads a text from file, fills corresponding structure
//! @param[in] file File to read from
//! @param[in] text Structure to fill
//! @return Number of error, if it happened
//!--------------------------------
int TextReader (const char* file, struct poem* text);

//!--------------------------------
//! @brief Sorts an array of any type
//! @param[in] base Array to sort
//! @param[in] nmemb Number of members in the array
//! @param[in] size Size of the type of the array
//! @param[out] CompFunc Comparing function
//!--------------------------------
void my_qsort(void* base, int nmemb, size_t size, int (*CompFunc)(const void*, const void*));

//!--------------------------------
//! @brief Handling of the arguments of command line
//! @param[in] argc Number of command line arguments
//! @param[in] argv Array of command line arguments
//! @param[out] input Name of the input file
//! @param[out] output Name of the output file
//!--------------------------------
void Arguments(int argc, char** argv, char** input, char** output);

//!--------------------------------
//! @brief Swaps two elements in the array
//! @param[in] elem1ptr Pointer to the first element to swap
//! @param[in] elem2ptr Pointer to the second element to swap
//!--------------------------------
void swap(void* i, void* j, size_t size);

//!--------------------------------
//! @brief Structure to contain information about line
//!--------------------------------
struct line
{
    int length; ///<Lenght of the line
    char* ptr;  ///<Pointer to the start of the line
};

//!--------------------------------
//! @brief Structure to contain information about text
//!--------------------------------
struct poem
{
    char* ptr;  ///<Pointer to the start of the text
    long size;  ///<Size of the text in bytes
    int nlines; ///<Number of lines in text
};

//!--------------------------------
//! @brief Used for indicating of appeared error
//!--------------------------------
enum Errors
{
    NOERR = 0,      ///<No errors occured
    INPUTERR,       ///<Error with input file
    INPUTMEMERR,    ///<Error with memory for input text
    SEPARMEMERR,    ///<Error with memory for separated text
    OUTPUTERR,      ///<Error with output file
    OUTPUTORERR,    ///<Error with output of origin file
};

#endif //TEXTSORT_H
