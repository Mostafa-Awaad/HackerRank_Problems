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
    int Iter1 = 0, Iter2 = 0;
    /* Adding the scenario where the function will stop if it reaches it
       if the first element in the array of strings is larger than the rest the function will return 0 */
    for (Iter1 = 0, Iter2 = Iter1+1 ; Iter2 < n-1 ; Iter1++)
    {
        if ((s[Iter1] > s[Iter1+1]) && (s[Iter2] > s[Iter2+1])) return 0;
        else {break;}
    }
    
    if (s[n-1] < s[n-2])
    {

    }
    else
    {
        for (Iter1 = 0 ; Iter1 < n-1 ; Iter1 ++)
        {
            if ((strcmp(s[Iter1], s[0]) != 0))
            {
                char *temp = s[Iter1]; 
                s[Iter1] = s[Iter1+1]; 
                s[Iter1+1] = temp;
                return 1; 
            }
        }
       
       
    }

}

int main()
{

    return 0;
}