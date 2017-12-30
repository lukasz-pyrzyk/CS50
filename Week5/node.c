typedef struct node 
{
    int n;
    struct node *next;
}
node;

bool seach(int n, node* list)
{
    node* ptr = list;
    while(ptr != NULL)
    {
        if(ptr->n == n) return true;
        ptr = list->next;
    }
    
    return false;
}