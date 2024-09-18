#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) 
{ 
    return (*(*(*(document + n-1) + m-1 ) + k-1));
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) 
{ 
    return (*(*(document + m-1)) + k-1);
}

char*** kth_paragraph(char**** document, int k) 
{
    return (*(document + k-1));
}


/**
 * @brief   Make Tokenization to your document and reach until 4-d array to have paragraphs that consists of sentences which
 *          consists of words that consists of characters.
 *          Learning Pointers is Fun :|
 * 
 * @param   text  the whole document as a string
 * 
 * @retval  Quad-Pointer to the multi-splitted document
 */
char**** get_document(char* text) 
{
    int Iter = 0;
    int Iter2 = 0;
    int parag_no = 0;  // To store number of paragraphs in the whole document
    int senten_no = 0; // To store number of sentences in each paragraph
    int word_no = 0;   // To store number of words in each sentence
    int *sent_arr = (int *)malloc(sizeof(int));
    /* Memory allocation for the document to store number of paragraphs */
    char **document = (char **)malloc(sizeof(char *));
    /* Tokenization the whole document into paragraphs */
    char *paragraph_token = strtok(text, "\n");
    while (paragraph_token != NULL)
    {
        parag_no++;
        document[parag_no-1] = paragraph_token;
        document = realloc(document, parag_no*sizeof(char *));
        paragraph_token = strtok(NULL, "\n");
        
    }
    /* Memory allocation for the paragraphs to store number of sentences in each one */
    char ***paragraphs = (char ***)malloc(parag_no * sizeof(char **));
    for (Iter = 0 ; Iter < parag_no ; Iter++)
    {
        senten_no = 0;
        char *sentence_token = strtok(document[Iter],".");
        /** Memory allocation for the ith paragraph to store number of sentences */
        paragraphs[Iter] = (char **)malloc(sizeof(char *));
        /* Tokenization the each paragraph into number of sentences */
        sent_arr = realloc(sent_arr, (parag_no+1)*sizeof(int));
        while (sentence_token != NULL)
        {
            senten_no++;
            paragraphs[Iter] = realloc(paragraphs[Iter], senten_no * sizeof(char *));
            paragraphs[Iter][senten_no-1] = sentence_token;
            
            sentence_token = strtok(NULL, ".");
        } 
        sent_arr[Iter] = senten_no; 
    }
    /* Memory allocation for quad pointers */
    char ****sentences = (char ****)malloc(sizeof(char ***));
    for (Iter = 0 ; Iter < parag_no ; Iter++)
    {
        /* Memory allocation for each sentence in Iterth paragraph*/
        sentences[Iter] = (char ***)malloc((sent_arr[Iter]) * sizeof(char **));
        /* Tokenization of the string into words*/
        for(Iter2 = 0 ; Iter2 < sent_arr[Iter] ; Iter2++)
        {
            word_no = 0;
            char *word_token = strtok(paragraphs[Iter][Iter2], " ");
            sentences[Iter][Iter2] = (char **)malloc(sizeof(char *));
            while (word_token != NULL)
            {
                word_no++;
                sentences[Iter][Iter2] = realloc(sentences[Iter][Iter2], word_no * sizeof(char *));
                sentences[Iter][Iter2][word_no-1] = word_token;

                word_token = strtok(NULL, " ");
            }
            
        }
    }
    return sentences;
}