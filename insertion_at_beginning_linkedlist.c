#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;

int insert(int item)
{
    struct node *ptr;
    ptr=(struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)
    {
        printf("Overflow memory.\n");
    }
    else
    {
        ptr->data=item;
        ptr->next=head;
        head=ptr;
        printf("Node Inserted\n");
    }
}

void print()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("List is empty.");
        return;
    }
    temp=head;
    while(temp!=NULL)
    {
        printf("Data: %d\n",temp->data);
        temp=temp->next;
    }
}

int main()
{
int item,choice;
while(choice==0)
{
    printf("Enter the data to insert at beginning of the linkedlist:\n");
    scanf("%d",&item);
    insert(item);
    printf("If want to insert data at beginning press 0 otherwise 1");
    scanf("%d",&choice);
    print();
}
return 0;
}