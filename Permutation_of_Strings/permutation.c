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
    int Iter1 = n-1;
    while (Iter1 > 0 && strcmp(s[Iter1-1], s[Iter1]))
    {
        Iter1--;
    }
    if (Iter1 <= 0)
        return 0;
    
    

}

int main()
{

    return 0;
}