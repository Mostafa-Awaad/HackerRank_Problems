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
    /* While Loop for check if the array of strings accepting next permutation or not
       if the Iter1 reaches to Zero, this indicates reaching our end and the array of strings are arranged in descending order
    */
    while (Iter1 > 0 && (strcmp(s[Iter1-1], s[Iter1]) >= 0))
    {
        Iter1--;
    }
    if (Iter1 <= 0)
        return 0;
    
    int Iter2 = n-1;
    /* While Loop to find the next largest Index to use it in the next permutation */
    while ((strcmp(s[Iter1-1], s[Iter2]) >= 0))
    {
        Iter2--;
    }
    /* Make Swapping to move Smallest lexigraphically larger element to the correct position */
    char *temp = s[Iter1-1];
    s[Iter1-1] = s[Iter2];
    s[Iter2] = temp;

    Iter2 = n-1;
    /* While loop to ensure the array of strings in the correct order */
    while (Iter1 < Iter2)
    {
        temp = s[Iter1];
        s[Iter1] = s[Iter2];
        s[Iter2] = temp;
        Iter1++;
        Iter2--;
    }
    return 1;
}

int main()
{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)
	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}
	do
	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));
	for (int i = 0; i < n; i++)
		free(s[i]);
	free(s);
	return 0;
}