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


char**** get_document(char* text) {

}