#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

void createlist(int n)
{
    int i, data;
    struct node *temp, *newnode;
    head = (struct node *)malloc(sizeof(struct node));

    if (head == NULL)
    {
        printf("Unable to allocate memory......");
        exit(0);
    }
    printf("Enter the data for node 1:\n");
    scanf("%d", &data);

    head->data = data;
    head->next = NULL;

    temp = head;
    for (i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Unable to allocate memory");
            break;
        }
        printf("Enter the data for node %d:\n", i);
        scanf("%d", &data);

        newnode->data = data;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void printlist()
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("Data :%d\n", temp->data);
        temp = temp->next;
    }
}

struct node* reverselist()
{
    struct node *prev,*after,*ptr;
    prev=NULL;
    ptr=head;
    while(ptr!=NULL)
    {
        after=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=after;
    }
    head=prev;
    return head;
}

int main()
{
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    printf("\nData in the list are:\n");
    printlist();
    printf("Reverse of the list is:\n");
    reverselist();
    printlist();
    return 0;
}