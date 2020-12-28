// Made by siraponte

// Implements a dictionary's functionality

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
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
const unsigned int N = 65000;

// Hash table
node *table[N];

//Words counter
int words = 0;

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    //Take hash index of the word
    int index = hash(word);
    
    //Create a cursor that point to first word of the link
    node *cursor = table[index];
    
    //Loop through link's words until the end
    while (cursor != NULL)
    {
        //Check if input word is equal to link's word
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        //If not , point to next word
        else
        {
            cursor = cursor->next;
        }
    }
    //If is not equal to any link's word, return false
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int wlen = strlen(word);
    int letters = 0;
    
    //Loop through word's letters
    for (int i = 0; i < wlen; i++)
    {
        //Math using all letters
        letters += tolower(word[i]);
    }
    
    //Return letters' values sum
    return (letters % N);
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    //Open dictionary
    FILE *file = fopen(dictionary, "r");
    
    //Check if it's null
    if (file == NULL)
    {
        return false;
    }
    
    char word[LENGTH + 1];

    //Scan each word until end of dictionary
    while (fscanf(file, "%s", word) != EOF)
    {
        //Alloc a new node for each word
        node *new_node = malloc(sizeof(node));
        
        //Check if new node is null
        if (new_node == NULL)
        {
            return false;
        }
        
        //Copy word into the node
        strcpy(new_node->word, word);
        new_node->next = NULL;
        
        //Make a hash index for each word
        int index = hash(new_node->word);
        
        //Create a node for the first linked word
        node *first = table[index];
        
        //Sets new node at the beginning of list
        if (first == NULL)
        {
            table[index] = new_node;
        }
        else
        {
            new_node->next = table[index];
            table[index] = new_node;
        }
        //Increments word count
        words++;
    }
    //Close file
    fclose(file);
    return true;    
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    //Return words' number
    return words;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    //Loop through buckets
    for (int i = 0; i < N; i++)
    {
        //Create a cursor and a temporary node that point to first linked word
        node *cursor = table[i];
        node *tmp = table[i];
        
        //Free all words of a link
        while (cursor != NULL)
        {
            cursor = cursor->next;
            free(tmp);
            tmp = cursor;
        }
    }
    return true;
}
