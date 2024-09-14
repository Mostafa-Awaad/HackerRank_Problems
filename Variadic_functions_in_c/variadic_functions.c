#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_ELEMENT 1
#define MAX_ELEMENT 1000000

/**
 * Variadic functions are functions that accept a varying number of arguments. 
 * In C programming, they provide added flexibility by allowing the function 
 * to take one fixed argument followed by any number of additional arguments.
 */

/**
 * @brief:         Function to return the sum of the passed integer elements
 * 
 * @param  count:  Number of passed variadic function parameters that until now is unkown until the user enter them
 * 
 * @retval:        Integer value that equals the sum of the variadic function parameters
 * 
 */
int  sum (int count,...) 
{
    int Sum = 0;

    /* Initializing a pointer that point to the last fixed argument */
    va_list ptr;

    /**
     * To access the arguments of the variadic function 
     * First parameter is the pointer to the last fixed argument 
     * Second parameter is the variable name of the last fixed argument 
    */
    va_start(ptr, count);

    /* Looping through the variable number of arguments */
    for (int Iter = 0 ; Iter < count ; Iter++)
    {
        /* Accessing the next variadic function argument and increment it 
           to the sum 
        */
        Sum += va_arg(ptr, int);
    }
    /* To end the traversal of the variadic function arguments. */
    va_end(ptr);
    return Sum;
}

int min(int count,...) 
{
    int Iter = 0;
    int Temp = 0;
    /* Initializing a pointer that point to the last fixed argument */
    va_list ptr;
    /* To access the arguments of the variadic function 
       First parameter is the pointer to the last fixed argument 
       Second parameter is the variable name of the last fixed argument 
    */
    va_start(ptr, count);
    /* Assign the Minimum value to the next variadic function argument */ 
    int Min = va_arg(ptr, int);
    for (Iter = 0 ; Iter < count - 1 ; Iter ++)
    {
        /*Assign the Temp value to the after next variadic function argument*/
        Temp = va_arg(ptr, int);
        if (Temp < Min) {Min = Temp;}
        else{/* Nothing */}
    }
    va_end(ptr);
    return Min;
}

int max(int count,...) 
{
    int Iter = 0;
    int Temp = 0;
    /* Initializing a pointer that point to the last fixed argument */
    va_list ptr;
    /* To access the arguments of the variadic function 
       First parameter is the pointer to the last fixed argument 
       Second parameter is the variable name of the last fixed argument 
    */
    va_start(ptr, count);
    /* Assign the Minimum value to the next variadic function argument */ 
    int Max = va_arg(ptr, int);
    for (Iter = 0 ; Iter <= count - 1 ; Iter ++)
    {
        /*Assign the Temp value to the after next variadic function argument*/
        Temp = va_arg(ptr, int);
        if (Temp > Max) {Max = Temp;}
        else {/* Nothing */}
        
    }
    va_end(ptr);
    return Max;

}