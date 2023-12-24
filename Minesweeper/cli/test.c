#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char *argv[])
{
    struct node* HEAD = (struct node*) malloc(sizeof(struct node));
    HEAD->point.x = -2;
    HEAD->point.y = -3;
    HEAD->next = NULL;
    Point test;
    test.x = 4;
    test.y = 4;
    addEnd(HEAD, test);
    test.x = 8;
    test.y = 10;
    addEnd(HEAD, test);
    printList(HEAD);
    test.x = 5;
    test.y = 5;
    printf("search returns: %d\n", search(HEAD, test));
}
