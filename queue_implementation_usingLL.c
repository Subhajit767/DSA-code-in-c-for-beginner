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
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
        printf("Queue Overflow!....");
    else
    {
        printf("Enter the value to insert:\n");
        scanf("%d", &item);
        ptr->data = item;
        ptr->next = NULL;
        if (front == NULL && rear == NULL)
            front = rear = ptr;
        else
        {
            rear->next = ptr;
            rear = ptr;
        }
    }
}

void dequeue()
{
    struct node *ptr;
    if (front == NULL)
        printf("Queued Underflow!....\n");
    else
    {
        ptr = front;
        front = front->next;
        printf("The dequeued item is %d\n", ptr->data);
        free(ptr);
    }
}

void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
        printf("Queue Underflow!...\n");
    else
    {
        printf("Queue is:\n");
        while (ptr != NULL)
        {
            printf(" %d ", ptr->data);
            ptr = ptr->next;
        }
    }
}

void peek()
{
    if (front == NULL)
        printf("Stack Underflow!....\n");
    else
        printf("The peek element is %d.\n", front->data);
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