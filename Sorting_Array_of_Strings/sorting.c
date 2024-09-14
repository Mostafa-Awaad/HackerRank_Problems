#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief   :   Strings are arranged from "smallest" to "largest" based on their lexicographical comparison
 * 
 * @param  a: First string 
 * @param  b: Second string
 * 
 * @retval  : -1 if a is lexicographically smaller than b
 *             0 if two strings are equal
 *             1 if a is lexicographically greater than b
 */
int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);
}

/**
 * @brief   :   Strings are arranged from "smallest" to "largest" based on their lexicographical comparison
 * 
 * @param  a: First string 
 * @param  b: Second string
 * 
 * @retval  : -1 if b is lexicographically smaller than a
 *             0 if two strings are equal
 *             1 if b is lexicographically greater than a
 */
int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    
}

int sort_by_length(const char* a, const char* b) 
{
    int Str_Len1 = strlen(a);
    int Str_Len2 = strlen(b);

    if (Str_Len1 != Str_Len2)
        return Str_Len1 - Str_Len2;
    else
        return strcmp(Str_Len1,Str_Len2);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b)){

}