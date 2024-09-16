#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief     Swapping the content of two strings
 * 
 * @param  a  First string 
 * @param  b  Second string
 */
void Swap_Two_Strings (char **a, char **b)
{
    char *temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief     Strings are arranged from "smallest" to "largest" based on their lexicographical comparison
 * 
 * @param  a  First string 
 * @param  b  Second string
 * 
 * @retval    -1 if a is lexicographically smaller than b
 *            0 if two strings are equal
 *            1 if a is lexicographically greater than b
 */
int lexicographic_sort(const char* a, const char* b) 
{
    return strcmp(a, b);
}

/**
 * @brief     Strings are arranged from "smallest" to "largest" based on their lexicographical comparison
 * 
 * @param  a  First string 
 * @param  b  Second string
 * 
 * @retval    -1 if b is lexicographically smaller than a
 *            0 if two strings are equal
 *            1 if b is lexicographically greater than a
 */
int lexicographic_sort_reverse(const char* a, const char* b) 
{
    return strcmp(b, a);
}

/**
 * @brief    Compare two strings based on their number of distinct elements and sort them in non-decreasing order.
 * 
 * @param a  A pointer to the first string to be compared.
 * @param b  A pointer to the second string to be compared.
 * 
 * @retval   An integer less than, equal to, or greater than zero if the first string is found,
 *           respectively, to have less distinct chars, same number of distinct chars, or have more distinct chars than the second string. 
 *           If the number of distinct chars are equal, the result of `strcmp(a, b)` is returned.
 */
int sort_by_number_of_distinct_characters(const char* a, const char* b) 
{
    int Iter = 0;

    int Distinct1 = 0;  /*Variable to hold the number of distinct chars in str a*/
    int Distinct2 = 0;  /*Variable to hold the number of distinct chars in str b*/

    int s1[2500] = {0}; /*To hold position of distinct characters for str a */
    int s2[2500] = {0}; /*To hold position of distinct characters for str b */

    for (Iter = 0 ; a[Iter] != '\0' ; Iter++)
    {
        /* Assign 1 in the new int array in the position of last occurence of current character*/
        s1[(strchr(a,a[Iter]) - a)] = 1;
    
    }
    /* Calculate the number of distinct element in str a */
    for (Iter = 0 ; Iter < 2500 ; Iter++)
    {
        if (s1[Iter] == 1)
        {
            Distinct1++;
        }
    }

    for (Iter = 0 ; b[Iter] != '\0' ; Iter++)
    {
        /* Assign 1 in the new int array in the position of last occurence of current character*/
        s2[(strchr(b,b[Iter]) - b)] = 1;
    
    }
    /* Calculate the number of distinct element in str a */
    for (Iter = 0 ; Iter < 2500 ; Iter++)
    {
        if (s2[Iter] == 1)
        {
            Distinct2++;
        }
    }

    if (Distinct1 != Distinct2)
    {
        return (Distinct1 - Distinct2);
    }
    return strcmp(a,b);   
}

/**
 * @brief    Compare two strings based on their length and sort them in non-decreasing order.
 * 
 * @param a  A pointer to the first string to be compared.
 * @param b  A pointer to the second string to be compared.
 * 
 * @retval   An integer less than, equal to, or greater than zero if the first string is found,
 *           respectively, to be shorter, of the same length, or longer than the second string. 
 *           If the lengths are equal, the result of `strcmp(a, b)` is returned.
 */
int sort_by_length(const char* a, const char* b) 
{
    int Str_Len1 = strlen(a);
    int Str_Len2 = strlen(b);

    if (Str_Len1 != Str_Len2)
        return (Str_Len1 - Str_Len2);
    else
        return strcmp(a, b);
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))
{
    unsigned int Sort_Iter = 0;
    unsigned int Adjacent_Iter = 0;
    /* In case of sorting in non decreasing order */
    if (cmp_func == lexicographic_sort)
    {
        /* For loop for the sorting */
        for (Sort_Iter = 0 ; Sort_Iter < len-1 ; Sort_Iter++)
        {
            for (Adjacent_Iter = 0 ; Adjacent_Iter < len-1 ; Adjacent_Iter++)
            {
                if (lexicographic_sort(arr[Adjacent_Iter], arr[Adjacent_Iter+1]) > 0)
                {
                    Swap_Two_Strings (&(arr[Adjacent_Iter]), &(arr[Adjacent_Iter+1]));
                }
                else{/* Nothing */}
            }
        }
    }

    /* In case of sorting in non increasing order */
    else if (cmp_func == lexicographic_sort_reverse)
    {
        /* For loop for the sorting */
        for (Sort_Iter = 0 ; Sort_Iter < len-1 ; Sort_Iter++)
        {
            for (Adjacent_Iter = 0 ; Adjacent_Iter < len-1 ; Adjacent_Iter++)
            {
                if (lexicographic_sort_reverse(arr[Adjacent_Iter], arr[Adjacent_Iter+1]) > 0)
                {
                    Swap_Two_Strings (&(arr[Adjacent_Iter]), &(arr[Adjacent_Iter+1]));
                }
                else{/* Nothing */}
            }
        }
    }

    /* In case of sorting according to the number of distinct elements in non decreasing order */
    else if (cmp_func == sort_by_number_of_distinct_characters)
    {
        /* For loop for the sorting */
        for (Sort_Iter = 0 ; Sort_Iter < len-1 ; Sort_Iter++)
        {
            for (Adjacent_Iter = 0 ; Adjacent_Iter < len-1 ; Adjacent_Iter++)
            {
                if (sort_by_number_of_distinct_characters(arr[Adjacent_Iter], arr[Adjacent_Iter+1]) > 0)
                {
                    Swap_Two_Strings (&(arr[Adjacent_Iter]), &(arr[Adjacent_Iter+1]));
                }
                else{/* Nothing */}
            }
        }
    }

    /* In case of sorting according to the string length in non decreasing order */
    else if (cmp_func == sort_by_length)
    {
        /* For loop for the sorting */
        for (Sort_Iter = 0 ; Sort_Iter < len-1 ; Sort_Iter++)
        {
            for (Adjacent_Iter = 0 ; Adjacent_Iter < len-1 ; Adjacent_Iter++)
            {
                if (sort_by_length(arr[Adjacent_Iter], arr[Adjacent_Iter+1]) > 0)
                {
                    Swap_Two_Strings (&(arr[Adjacent_Iter]), &(arr[Adjacent_Iter+1]));
                }
                else{/* Nothing */}
            }
        }
    }
    else {printf("Enter a valid sorting method\n");}
}
