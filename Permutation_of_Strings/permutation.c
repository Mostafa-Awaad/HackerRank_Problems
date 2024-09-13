#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)
{
	/**
	* Complete this method
	* Return 0 when there is no next permutation and 1 otherwise
	* Modify array s to its next permutation
	*/
    int Iter = 0;
    int flag = 0;
    /* Adding the scenario where the function will stop if it reaches it
       if the first element in the array of strings is larger than the rest the function will return 0 */
    for (Iter = 0 ; Iter < n ; Iter++)
    {
        if (s[0] <= s[Iter]) {flag = 0;}
        else {flag = 1;}
    }
    if (flag == 1)
    {
        return 0;
    }
    else
    {

    }
}

int main()
{

    return 0;
}