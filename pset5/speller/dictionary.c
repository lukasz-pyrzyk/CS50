#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

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
    int len = strlen(word);
    char *copy = malloc(len+1);
    for (int i = 0; i < len; i++)
    {
        copy[i] = tolower(word[i]);
    }
    copy[len] = '\0';

    Node* current = head;
    while (current != NULL)
    {
        if (strcmp(copy, current->word) == 0)
        {
            free(copy);
            return true;
        }
        current = current->next;
    }

    free(copy);
    return false;
}

bool load(const char *dictionary)
{
    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
        return false;

    char word[LENGTH+1];

    Node* current = NULL;
    while (fscanf(file, "%s", word) != EOF)
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