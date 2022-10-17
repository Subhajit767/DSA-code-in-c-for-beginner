#include <stdio.h>
#include <stdlib.h>
#define N 10
int queue[N];
int front = -1, rear = -1;

void enqueue()
{
    int item;
    printf("Enter the no:\n");
    scanf("%d", &item);  
    if ((rear + 1) % N == front)
        printf("Queue is Full..\n");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = item;
    }
    else
    {
        rear = (rear + 1) % N;
        queue[rear] = item;
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
        printf("Queue is Empty...\n");
    else
    {
        for ( i = front; i != rear; i = (i + 1) % N)
            printf(" %d ", queue[i]);
        printf(" %d ",queue[i]);
        printf("\n");
    }
}

void peek()
{
    if (front == -1 && rear == -1)
        printf("Queue is Empty...\n");
    else
        printf("The peek element is %d.\n", queue[front]);
}

void dequeue()
{
    if (front == -1 && rear == -1)
        printf("Queue is Empty!....\n");
    else if (front == rear)
        front = rear = -1;
    else
    {
        printf("The dequeued element is %d.\n", queue[front]);
        front = (front + 1) % N;
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