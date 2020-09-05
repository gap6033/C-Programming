// Implements a dictionary's functionality
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
int wordcount = 0;
// Number of buckets in hash table
const unsigned int N = 65536;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    node *p;
    p = table[hash(word)];
    while(p != NULL)
    {
        if(strcasecmp(p->word, word) == 0)
        {
            return true;
        }
        else
        {
            p = p->next;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int value = 0 ;
    for (int i = 0 ; word[i] != '\0' ; i++)
    {
        value += tolower(word[i]) ;
    }
    return value % N ;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
    return false;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            table[i] = NULL;
        }
        char letters[LENGTH + 1];
        while(fscanf(dict, "%s", letters) != EOF)
        {
            node *temp = (node *)malloc(sizeof(node));
            strcpy(temp->word, letters);
            int index = hash(letters);
            if (table[index] == NULL)
            {
                table[index] = temp;
                strcpy(temp->word, letters);
                temp->next = NULL;
            }
            else
            {
                temp->next = table[index];
                table[index] = temp;
            }
            wordcount++;
        }
        fclose(dict);
        return true;
    }
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    node* temp;
    for(int i = 0; i < N; i++)
    {
        temp = table[i];
        while(temp != NULL)
        {
            node *p = temp;
            temp = temp->next;
            free(p);
        }
    }
    return true;
}
