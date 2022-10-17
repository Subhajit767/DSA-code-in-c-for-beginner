#include <stdlib.h>
#include <stdio.h>

struct node
{
    int data;
    struct node *next;
} * head;

int createlist(int n)
{
    int i, item;
    struct node *temp, *newnode;
    head = (struct node *)malloc(sizeof(struct node));
    if (head == NULL)
    {
        printf("Memory not allocated.\n");
        exit(0);
    }
    printf("Enter the element 1:\n");
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
        printf("Enter the element %d:\n",i);
        scanf("%d",&item);
        newnode->data=item;
        newnode->next=NULL;
        temp->next=newnode;
        temp=temp->next;
    }
}

void printlist(int n)
{
    struct node *temp;
    if(temp==NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("Data :%d\n", temp->data);
        temp = temp->next;
    }
}

struct node* deletefirst()
{
    struct node*ptr;
    ptr=head;
    head=head->next;
    free(ptr);
    return head;
}

struct node* deleteatindex(int index)
{
    struct node *p,*q;
    p=head;
    q=head->next;
    for(int i=1;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node* deleteatlast()
{
    struct node *p,*q;
    p=head;
    q=head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
}

struct node* deleteatdata(int info)
{
    struct node *p,*q;
    p=head;
    while(p!=NULL)
    {
        if(p->next->data==info)
        {
            q=p->next;
            p->next=q->next;
            free(q);
        }
        p=p->next;
    }
    return head;
}

int main()
{
    int n;
    printf("Enter the no of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    printf("The elements are:\n");
    printlist(n);
    printf("After deletion the elements are:\n");
    // deletefirst();
    // deleteatindex(1);
    // deleteatlast();
    deleteatdata(25);
    printlist(n);
    return 0;
}