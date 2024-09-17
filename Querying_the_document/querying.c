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


char**** get_document(char* text) 
{
    /* Allocation of memory block for document and suppose at beginning has only one paragraph*/
    char ****document = (char ****)malloc(sizeof(char ***));
    int parag_no = 0; // for storing number of paragraphs
    
    /*Tokenization of our text into paragraphs*/
    char *paragraph_token = strtok(text, "\n");
    while (paragraph_token != NULL)
    {
        parag_no++;
        /*Reallocation and expanding our memory block based on number of paragraphs found*/
        document = realloc(document, parag_no * sizeof(char ***));
        
        /* Allocation of memory block for paragraph and suppose at beginning by one sentence*/
        char ***paragraph = (char ***)malloc(sizeof(char **));
        int sent_no = 0; // for storing number of sentences

        /* Tokenization of our paragraph into sentences*/
        char *sentence_token = strtok(paragraph_token,".");
        while (sentence_token != NULL)
        {
            sent_no++;
            /*Reallocation and expanding our memory block based on number of sentences found*/
            paragraph = realloc(paragraph, sent_no * sizeof(char **));
            /* Allocation of memory block for sentence */
            char **sentence = (char **)malloc(sizeof(char *));
            int word_no = 0;// for storing number of words in one sentence

            /*Tokenization of our sentence into words*/
            char *word_token = strtok(sentence_token, " ");
            while (word_token != NULL)
            {
                word_no++;
                /*Realloction of memory block of words*/
                sentence = realloc(sentence, word_no * sizeof(char *));
                sentence[word_no-1] = word_token;
                word_token = strtok(NULL, " ");
            }
            
            paragraph[sent_no-1] = sentence;
            sentence_token = strtok(NULL, ".");
        }
        document[parag_no-1] = paragraph;
        paragraph_token = strtok(NULL, "\n");
        
    }

    return document;
}