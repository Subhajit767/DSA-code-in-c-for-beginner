#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} * head;

void createlist(int n)
{
    head = NULL;
    struct node *temp, *newnode;
    for (int i = 1; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for element %d: \n", i);
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;
        if (head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
    temp->next = NULL;
}

void printlist(int n)
{
    struct node *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
    }
}

struct node *insertionAtFirst(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
}

struct node *insertionAtIndex(int index, int item)
{
    struct node *p, *q, *temp;
    p = head;
    q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    temp = (struct node *)malloc(sizeof(struct node));
    q->prev = temp;
    p->next = temp;
    temp->data = item;
    temp->next = q;
    temp->prev = p;
}

struct node *insertionAtLast(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;
    temp->data = item;
    temp->prev = p;
    temp->next = NULL;
    p->next = temp;
}

struct node *deleteAtFirst()
{
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}

struct node *deleteAtIndex(int index)
{
    struct node *p, *q;
    p = head;
    q = head->next;
    for (int i = 1; i < index - 1; i++)
    {
        q = q->next;
        p = p->next;
    }
    p->next = q->next;
    (q->next)->prev = p;
    free(q);
    return head;
}

struct node *deleteAtLast()
{
    struct node *p, *q;
    p = head;
    q = head->next;
    while (q->next != NULL)
    {
        q = q->next;
        p = p->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

int main()
{
    int n;
    printf("Enter the no of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    printf("The elements before insertion:\n");
    printlist(n);
    printf("The elements after insertion:\n");
    // insertionAtFirst(100);
    // insertionAtIndex(2,50);
    // insertionAtLast(200);
    // deleteAtFirst();
    // deleteAtIndex(2);
    deleteAtLast();
    printlist(n);
    return 0;
}