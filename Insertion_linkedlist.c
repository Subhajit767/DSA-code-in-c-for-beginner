#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} * head;

int createarray(int n)
{
    int i, item;
    struct node *temp, *newnode;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("Enter the 1st element:\n");
    scanf("%d", &item);
    head->data = item;
    head->next = NULL;
    temp = head;
    for (i = 2; i <= n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        if (newnode == NULL)
        {
            printf("Memory not allocated.\n");
            break;
        }
        printf("Enter the %d element:\n", i);
        scanf("%d", &item);
        newnode->data = item;
        newnode->next = NULL;
        temp->next = newnode;
        temp = temp->next;
    }
}

void displayarray(int n)
{
    struct node *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf("Data :%d\n", temp->data);
        temp = temp->next;
    }
}

struct node *insertatfirst(int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    ptr->next = head;
    head = ptr;
    return ptr;
}

struct node *insertatindex(int index, int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    for (int i = 1; i <= index - 1; i++)
        p = p->next;
    ptr->data = d;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct node *insertatlast(int d)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = d;
    struct node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct node *addAfterNode(struct node *ptr, int data, int item)
{
    struct node *p = ptr;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    while (p->next != NULL)
    {
        if (p->data == item)
        {
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
        }
        p = p->next;
    }
}

struct node *addBeforeNode(struct node *head, int data, int item)
{
    struct node *p = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    while (p->next != NULL)
    {
        if (p->next->data == item)
        {
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            return head;
        }
        p = p->next;
    }
    return head;
}

int main()
{
    int n;
    printf("Enter the no of elements:\n");
    scanf("%d", &n);
    createarray(n);
    printf("\nThe elements are:\n");
    displayarray(n);
    // insertatfirst(20);
    // insertatindex(3,20);
    // insertatlast(20);
    // addAfterNode(head,100,20);
    addBeforeNode(head, 5, 2);
    printf("After insertion:\n");
    displayarray(n + 1);
    return 0;
}