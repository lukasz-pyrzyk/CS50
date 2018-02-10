#include <stdbool.h>
#include "dictionary.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[LENGTH + 1];
    struct node* next;
}
node;

node* head;
unsigned int lines = 0;

bool check(const char *word)
{
    node* current = head;
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

    node* current = head;
    while (!feof(file))
    {
        node* node = malloc(sizeof(node));
        if(node == NULL)
        {
            printf("Cannot allocate more memory for node with line %i\n", lines);
            return false;
        }
        
        fscanf(file, "%s", node->word);

        if (current != NULL)
        {
            current->next = node;
            current = current->next;
        }
        else
        {
            current = node;
        }
        lines++;
    }

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
    while (head != NULL)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return true;
}