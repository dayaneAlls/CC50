// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>
#include <ctype.h>
#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int total=0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int i=hash(word);
    for (node *aux=table[i];aux!=NULL;aux=aux->next){
        if(strcasecmp(aux->word,word)==0)
            return true;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned long sum=0;
    for (int j=0;j<strlen(word);j++){
        sum+=toupper(word[j]);
    }
    return sum%N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    FILE *file = fopen(dictionary,"r");
    if (file == NULL){
        printf("Could not open dictionary\n");
        return false;
    }
    char word[LENGTH+1];

    while(fscanf(file,"%s",word)!=EOF){
        node *top = malloc(sizeof(node));

        if(top != NULL){
            strcpy(top->word,word);
            int i = hash(word);
            top->next=table[i];
            table[i]=top;
            total++;
        }
        else{
            return false;
        }
    }
    fclose(file);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return total;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    for (int i=0;i<N;i++){
        while(table[i]!=NULL){
            node *aux=table[i]->next;
            free(table[i]);
            table[i]=aux;
        }
    }
    return true;
}
