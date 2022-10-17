#include <stdio.h>
int choice, top, stack[100], n, val;

void push()
{
    if (top >= n - 1)
        printf("Stack Overflow!\n");
    else
    {
        printf("Enter the element to be pushed:\n");
        scanf("%d", &val);
        top++;
        stack[top] = val;
    }
}

void pop()
{
    if (top <= -1)
        printf("Stack Underflow!\n");
    else
    {
        printf("The popped element is %d.\n", stack[top]);
        top--;
    }
}

void display()
{
    if (top >= 0)
    {
        for (int i = top; i >= 0; i--)
            printf("%d\n", stack[i]);
        printf("\n Press Next Choice");
    }
    else
        printf("\nThe stack is empty\n");
}

void peek()
{
    if (top > -1)
        printf("The top element of the stack is :%d\n", stack[top]);
    else
        printf("Stack Underflow!\n");
}

int main()
{
    top = -1;
    printf("Enter the size of stack:\n");
    scanf("%d", &n);
    do
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Peek\n5.Exit\n");
        printf("Enter your choice:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peek();
            break;
        case 5:
            printf("\n\nExit Point.\n");
            break;
        default:
            printf("Please enter a valid choice:(1/2/3/4)\n");
        }
    } while (choice != 5);
    return 0;
}