#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head, *first, *second, *third, *fourth;

void printlist()
{
    struct node *ptr = head;
    do
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *deletionAtFirst()
{
    struct node *ptr = head;
    struct node *p = head;
    while (ptr->next != head)
        ptr = ptr->next;
    ptr->next = p->next;
    head = p->next;
    free(p);
}

struct node *deletionAtLast()
{
    struct node *ptr = head->next;
    struct node *p = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
        p = p->next;
    }
    p->next = head;
    free(ptr);
}

struct node *deletionAtIndex(int index)
{
    struct node *ptr=head->next;
    struct node *p=head;
    for(int i=1;i<=index-1;i++)
    {
        ptr = ptr->next;
        p = p->next;
    }
    p->next=ptr->next;
    free(ptr);
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    first = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 4;
    head->next = first;

    first->data = 2;
    first->next = second;

    second->data = 12;
    second->next = third;

    third->data = 16;
    third->next = fourth;

    fourth->data = 20;
    fourth->next = head;

    printf("Elements before deletion:\n");
    printlist();
    printf("Elements after deletion:\n");
    // deletionAtFirst();
    // deletionAtLast();
    deletionAtIndex(3);
    printlist();
    return 0;
}