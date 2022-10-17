#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void createlist(int n)
{
    struct node *newnode, *temp;
    head==NULL;
    for(int i=1;i<=n;i++)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data for element %d :\n",i);
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            temp=newnode;
        }
        else
        {
            temp->next=newnode;
            temp=newnode;
        }
        temp->next=head;
    }
}

void printlist()
{
    struct node *ptr = head;
    do
    {
        printf("Data: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
}

struct node *insertAtFirst(int item)
{
    struct node *ptr = (struct Node *)malloc(sizeof(struct node));
    ptr->data = item;

    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;
}

struct node *insertAtLast(int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    struct node *p = head->next;
    while (p->next != head)
        p = p->next;
    p->next = ptr;
    ptr->next = head;
}

struct node *insertAtIndex(int index, int item)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = item;
    struct node *p = head;
    for (int i = 1; i < index - 1; i++)
        p = p->next;
    ptr->next = p->next;
    p->next = ptr;
}

int main()
{
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    printf("Before insertion the elements are:\n");
    printlist(n);
    printf("After insertion the elements are:\n");
    insertAtFirst(20);
    insertAtIndex(2,30);
    insertAtLast(100);
    printlist();
    return 0;
}