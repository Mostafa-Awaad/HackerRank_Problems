# HackerRank_Problems
## Permutation of Strings

### Objective
Compute the next lexicographical permutation of an array of strings.

### Algorithm

1. **Find Decreasing Element**:  
   Traverse the array from right to left to find the first pair of strings where `s[i-1] < s[i]`. This identifies the rightmost element that can be swapped to form the next permutation.

2. **Check for Last Permutation**:  
   If no such pair exists, it means the array is sorted in descending order, and there are no more permutations left. Return `0` to indicate this.

3. **Find Next Lexicographical String**:  
   Find the smallest lexicographically larger string than `s[i-1]` from the right of the array.

4. **Swap Elements**:  
   Swap `s[i-1]` with the smallest larger string identified in the previous step.

5. **Reverse Suffix**:  
   Reverse the order of the strings from `i` onward to get the smallest possible permutation greater than the current one.
