#include <stdlib.h>
#include <stdio.h>

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

void printlist(int n)
{
    struct node*temp;
    int i;
    temp=head;
    do
    {
        printf("Data: %d\n",temp->data);
        temp=temp->next;
    } while (temp!=head);
    
}

int main()
{
    int n;
    printf("Enter the number of nodes:\n");
    scanf("%d", &n);
    createlist(n);
    printf("Before insertion the elements are:\n");
    printlist(n);
    return 0;
}