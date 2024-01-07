#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int num;
    struct node *nxt;
} node;
void show_nodes(node *n);
void free_nodes(node *n);

int main(int argc, char **argv)
{
    node *nodes = NULL;
    for (int i = 1; i < argc; i++)
    {
        int num = atoi(*(argv + i));
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            if (i > 1)
                free_nodes(nodes);
            return 1;
        }
        (*n).num = num;
        (*n).nxt = nodes;
        nodes = n;
    }
    show_nodes(nodes);
    free_nodes(nodes);
    return 0;
}
void show_nodes(node *n)
{
    while (n != NULL)
    {
        printf("%i\t", (*n).num);
        n = (*n).nxt;
    }
    putchar('\n');
}
void free_nodes(node *n)
{
    node *next = n;
    while (n != NULL)
    {
        next = (*n).nxt;
        free(n);
        n = next;
    }
}