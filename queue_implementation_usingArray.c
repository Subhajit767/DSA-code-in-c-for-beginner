#include <stdio.h>
#include<stdlib.h>
int queue[10];
int front=-1,rear=-1;

void enqueue()
{
    int item;
    if(rear==9)
    printf("Queue Overflow.\n");
    else
    {
        if(front==-1)
        front=0;
        printf("Enter the element to be inserted in queue:\n");
        scanf("%d",&item);
        rear++;
        queue[rear]=item; 
    }
}

void dequeue()
{
    if(front==-1 || front>rear)
    printf("Queue Underflow!.\n");
    else
    {
        printf("Element deleted from queue is : %d\n",queue[front]);
        front++;
    }
}

void display()
{
    int i;
    if(front==-1)
    printf("Queue is Empty.\n");
    else
    {
        printf("Queue is:\n");
        for(i=front;i<=rear;i++)
        printf(" %d ",queue[i]);
        printf("\n");
    }
}

void peek()
{
    if(front==-1)
    printf("Queue is Empty.\n");
    else
    printf("The top element of the queue is %d.\n",queue[front]);
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