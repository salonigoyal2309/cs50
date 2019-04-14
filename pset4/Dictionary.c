#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "dictionary.h"

// The root node of the trie
node* root;

// Counter for the number of words in the dictionary
unsigned int words;

// Prototype to allow recursion
void clear(node* ptr);

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    int length = strlen(word);

    // Points to current node as the program descends through the trie
    node* ptr = root;

    for (int i=0; i < length; i++)
    {
        char c = tolower(word[i]);

        // Check if character is apostrophe
        if (c == '\'')
        {
            // 123 - 97 = 26 (apostrophes go at nodes[26])
            c = 123;
        }

        // Try to get the adress of the next node in the trie
        struct node* nextNode = ptr->nodes[c-97];

        if (nextNode == NULL)
        {
            return false;
        }
        else
        {
            ptr = nextNode;
        }
    }

    // Check if the words is really in the dict (not just part of a word)
    if (ptr->word == true)
    {
        return true;
    }

    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    // Open the dictionary file
    FILE* dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    // Allocate space for the first root node
    root = calloc(1, sizeof(node));

    // Points to current node as the program descends through the trie
    node* ptr = root;

    // Read the dictionary one character at a time
    for (char c = tolower(fgetc(dict)); c != EOF; c = fgetc(dict))
    {
        // If the word is finished
        if (c == '\n')
        {
            // Check that the word is at least one letter long
            if (ptr != root)
            {
                words++;

                ptr->word = true;

                // Reset the pointer back to the top of the trie
                ptr = root;
            }
        }
        // If the word is still in progress
        else
        {
            // Check if character is apostrophe
            if (c == '\'')
            {
                // 123 - 97 = 26 (apostrophes go at nodes[26])
                c = 123;
            }

            // Try to get the address of the next node in the trie
            struct node* nextNode = ptr->nodes[c-97];
            if (nextNode == NULL)
            {
                // Allocate space if it is not yet there
                ptr->nodes[c-97] = calloc(1, sizeof(node));

                ptr = ptr->nodes[c-97];
            }
            else
            {
                ptr = nextNode;
            }

        }
    }

    fclose(dict);

    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return words;
}

/**
 * Recursive function that frees a trie from memory
 */
void clear(node* ptr)
{
    for (int i = 0; i < 27; i++)
    {
        if (ptr->nodes[i] != NULL)
        {
            clear(ptr->nodes[i]);
        }
    }

    free(ptr);
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    clear(root);
    return true;
}
