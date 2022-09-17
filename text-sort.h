#ifndef TEXTSORT_H
#define TEXTSORT_H

//!--------------------------------
//! @brief Used for determining file size
//! @param[in] fp Coefficient for input
//! @return Size of the file in bytes
//!--------------------------------
long FileSize(FILE *fp);

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
int Strings_Separator(struct poem* text, const char);

//!--------------------------------
//! @brief Compares two structures from left to right
//! @param[out] struct1ptr Pointer to a first structure to compare
//! @param[out] struct1ptr Pointer to a second structure to compare
//! @return Negative value if struct2ptr appears before str1 in lexicographical order, Zero if struct1ptr and struct2ptr compare equal, Positive value if struct1ptr appears after struct2ptr in lexicographical order.
//!--------------------------------
int cmp(const void* struct1ptr, const void* struct2ptr, void* arg);

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
int TextReader (const char* file, struct poem* text, const char* mode);

//!--------------------------------
//! @brief Sorts an array of any type
//! @param[in] base Array to sort
//! @param[in] nmemb Number of members in the array
//! @param[in] size Size of the type of the array
//! @param[out] CompFunc Comparing function
//!--------------------------------
void my_qsort_r(void* base, int nmemb, size_t size, int (*CompFunc)(const void*, const void*, void*), void* arg);

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
    char* ptr;              ///<Pointer to the start of the text
    long size;              ///<Size of the text in bytes
    int nlines;             ///<Number of lines in text
    struct line* Strings;   ///<Array of structures, containing strings
};

//!--------------------------------
//! @brief Used for indicating of appeared error
//!--------------------------------
enum Errors
{
    NOERR = 0,      ///<No errors occured
    INPUTERROR,     ///<Error with input file
    MEMERROR,       ///<Error with memory
    FILERROR        ///<Error with file
};

//!--------------------------------
//! @brief Used for preparation of step for compare
//!--------------------------------
void ChangeStep();

#endif //TEXTSORT_H
