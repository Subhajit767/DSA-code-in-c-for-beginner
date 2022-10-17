#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *front = NULL, *rear = NULL;

void enqueue()
{
    int item;
    printf("Enter the data:\n");
    scanf("%d", &item);
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = item;
    newnode->next = NULL;
    if (rear == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    rear->next = front;
}

void dequeue()
{
    struct node *temp = front;
    if (front == NULL && rear == NULL)
        printf("Queue is empty.\n");
    else if (front == rear)
        {
            front = rear = NULL;
            free(temp);
        }
    else
    {
        printf("The dequeued element is %d.\n", front->data);
        front = front->next;
        rear->next=front;
        free(temp);
    }
}

void peek()
{
    if (front == NULL && rear == NULL)
        printf("Queue is empty.\n");
    else
        printf("The peek element is %d.\n", front->data);
}

void display()
{
    struct node* temp=front;
    if (front == NULL && rear == NULL)
        printf("Queue is empty.\n");
    else
    {
        while(temp!=front)
        {
            printf(" %d ",temp->data);
            temp=temp->next;
        }
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n1.Enqueue.\n2.Dequeue.\n3.Display.\n4.Peek.\n5.Exit");
        printf("\nEnter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("Wrong Input.\n");
            break;
        }
    }
    return 0;
}