# HackerRank_Problems
## 1. Permutation of Strings

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

## 2. Querying the Document

### Objective
Process a document to tokenize it into paragraphs, sentences, and words, and allow efficient querying of specific parts of the document.

### Data Structure

- **Document**: Consists of multiple paragraphs.
- **Paragraph**: Contains multiple sentences.
- **Sentence**: Contains multiple words.
- **Word**: Made up of characters.

### Functions

1. **`kth_word_in_mth_sentence_of_nth_paragraph`**
   - Retrieves the k-th word from the m-th sentence in the n-th paragraph.
   ```c
   char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n);
2. **`kth_sentence_in_mth_paragraph`**
   - Retrieves the k-th sentence from the m-th paragraph.
   ```c
   char** kth_sentence_in_mth_paragraph(char**** document, int k, int m);
3. **`kth_paragraph`**
   - Retrieves the k-th paragraph.
   ```c
   char*** kth_paragraph(char**** document, int k);
4. **`get_document`**
   - Processes the input text, splitting it into a 4D array of pointers.
     ```c
     char**** get_document(char* text);
     Tokenization Steps
   #### Paragraph Tokenization:
   - The document is split into paragraphs based on newline (\n) characters.
   - Sentence Tokenization: Each paragraph is split into sentences based on periods (.).
   - Word Tokenization: Each sentence is split into words based on spaces ( ).
   
## 3. Sorting Array of Strings

### Objective
Sort an array of strings based on different criteria such as lexicographical order, reverse lexicographical order, number of distinct characters, and string length.

### Functions

1. **`Swap_Two_Strings`**
   - Swaps two string pointers to change the order of the strings in the array.
   ```c
   void Swap_Two_Strings (char **a, char **b);
2. **`lexicographic_sort`**
   - Compares two strings lexicographically (smallest to largest).
   ```c
   int lexicographic_sort(const char* a, const char* b);
3. **`lexicographic_sort_reverse`**
   - Compares two strings in reverse lexicographical order (largest to smallest).
   ```c
   int lexicographic_sort_reverse(const char* a, const char* b);
4. **`sort_by_number_of_distinct_characters`**
   - Sorts strings by the number of distinct characters in non-decreasing order. If two strings have the same number of distinct characters, lexicographical comparison is used as a tiebreaker.
   ```c
   int sort_by_number_of_distinct_characters(const char* a, const char* b);
5. **`sort_by_length`**
   - Sorts strings by length in non-decreasing order. If two strings have the same length, lexicographical comparison is used as a tiebreaker.
   ```c
   int sort_by_length(const char* a, const char* b);
6. **`string_sort`**
   - Sorts an array of strings based on a comparison function provided as a function pointer.
   ```c
   void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b));
### Sorting Methods
- **Lexicographic Sort:** Sorts the strings in lexicographic (dictionary) order.

- **Reverse Lexicographic Sort:** Sorts the strings in reverse lexicographic order.

- **Sort by Number of Distinct Characters**: Sorts the strings by the number of distinct characters, in non-decreasing order. If two strings have the same number of distinct characters, they are sorted lexicographically.

- **Sort by Length:** Sorts the strings by their length in non-decreasing order. If two strings have the same length, they are sorted lexicographically.
