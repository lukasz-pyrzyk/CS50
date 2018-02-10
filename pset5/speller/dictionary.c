#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char word[LENGTH];
    struct Node* next;
}
Node;

Node* head;
unsigned int dictionarySize = 0;

bool check(const char *word)
{
    Node* current = head;
    while (current != NULL)
    {
        if (strcmp(current->word, word) == 0)
        {
            return true;
        }
        current = current->next;
    }

    return false;
}

bool load(const char *dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;
    
    char word[LENGTH+1];
    
    Node* current;
    while (fscanf(file, "%s\n", word)!= EOF)
    {
        dictionarySize++;
        
        Node* newNode = malloc(sizeof(Node));
        strcpy(newNode->word, word);

        if (current == NULL)
        {
            head = newNode;
            current = head;
        }
        else
        {
            current->next = newNode;
            current = current->next;
        }
    }
    
    fclose(file);
    return true;
}

unsigned int size(void)
{
    return dictionarySize;
}

bool unload(void)
{
    Node* tmp;
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return true;
}