#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
} node;

node* first;
unsigned int lines = 0;

bool check(const char *word)
{
    node* current = first;
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
    if (dictionary == NULL)
    {
        printf("Cannot open the file, file name is null");
        return false;
    }

    FILE* file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("Cannot open file, fopen returns null pointer\n");
        return false;
    }

    node* current = first;
    char* line = malloc(LENGTH);
    if (line == NULL)
    {
        printf("Cannot allocate memory for temp line");
        return false;
    }
    while (fgets(line, LENGTH, file) != NULL)
    {
        node* row = malloc(sizeof(node));
        if(row != NULL)
        {
            printf("Cannot allocate more memory for node with line %i\n", lines);
            return false;
        }
        
        strcpy(row->word, line);

        if (current != NULL)
        {
            current->next = row;
            current = current->next;
        }
        else
        {
            current = row;
        }
        lines++;
    }

    free(line);
    fclose(file);
    return true;
}

unsigned int size(void)
{
    return lines;
}

bool unload(void)
{
    node* tmp;
    while (first != NULL)
    {
        tmp = first;
        first = first->next;
        free(tmp);
    }
    return true;
}