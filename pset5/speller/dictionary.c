#include <cs50.h>
#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

const int CHARACTERS = 27; // alphabet + "`"

typedef struct Node
{
    struct Node* childrens[CHARACTERS];
    bool lastWord;
}
Node;

unsigned int dictionarySize = 0;
Node* head = NULL;

char* ToLower(char* word, int len)
{
    char* copy = malloc(len+1);
    for (int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[len] = '\0';
    return copy;
}

int RoundIndex(int index)
{
    if (index == 39) // ASCII of '
    {
        return CHARACTERS - 1;
    }
    
    return index - 'a';
}

Node* CreateNode()
{
    Node* node = malloc(sizeof(Node));
    node->lastWord = false;

    for (int i = 0; i < CHARACTERS; i++)
    {
        node->childrens[i] = NULL;
    }
    return node;
}

void Insert(Node* root, string word)
{
    int len = strlen(word);
    
    Node* current = root;
    for (int i = 0; i < len; i++)
    {
        int index = RoundIndex(word[i]);
        
        if (current->childrens[index] == NULL)
        {
            current->childrens[index] = CreateNode();
        }

        current = current->childrens[index];
    }

    current->lastWord = true;
}

bool Contains(Node* root, string word)
{
    int len = strlen(word);
    char* copy = ToLower(word, len);

    Node* current = root;
    for (int i = 0; i < len; i++)
    {
        int index = RoundIndex(copy[i]);

        if (current->childrens[index] == NULL)
        {
            free(copy);
            return false;
        }

        current = current->childrens[index];
    }

    free(copy);
    return (current != NULL && current->lastWord);
}

bool check(const char *word)
{
    int len = strlen(word);
    char *copy = malloc(len+1);
    for (int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[len] = '\0';

    Node* current = head;
    bool result = Contains(current, copy);
    free(copy);
    return result;
}

bool load(const char *dictionary)
{
    head = CreateNode();
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    char word[LENGTH+1];

    while (fscanf(file, "%s", word) != EOF)
    {
        dictionarySize++;
        Insert(head, word);
    }

    fclose(file);
    return true;
}

unsigned int size(void)
{
    return dictionarySize;
}

void freeNodes(Node* node)
{
    if (node == NULL) return;

    for (int i = 0; i < CHARACTERS; i++)
    {
        freeNodes(node->childrens[i]);
    }

    free(node);
}

bool unload(void)
{
    freeNodes(head);
    return true;
}