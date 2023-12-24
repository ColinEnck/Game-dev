typedef struct
{
    int x;
    int y;
} Point;

struct node 
{
    Point point;
    struct node* next;
};

void addEnd(struct node* head, Point data)
{
    struct node* lk = (struct node*) malloc(sizeof(struct node));
    struct node* current = head;
    lk->point = data;
    while (current->next != NULL) current = current->next;
    current->next = lk;

}

int search(struct node* head, Point key)
{
    struct node* current = head;
    for (; current != NULL; current = current->next)
        if (current->point.x == key.x && current->point.y == key.y)
            return 1;
    return 0;
}

// only for debugging
void printList(struct node* head)
{
    struct node* current = head;
    for (; current != NULL; current = current->next)
    {
        printf("%d, %d\n", current->point.x, current->point.y);
    }
    putchar('\n');
}

void clearList(struct node* head)
{
    head->next = NULL;
}
