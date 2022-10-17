#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node* top=NULL;

void push(int val)
{
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=val;
	if(top==NULL)
	newnode->next=NULL;
	else
	newnode->next=top;
	top=newnode;
	printf("\nNode is inserted.\n");
}

int pop()
{
	if(top==NULL)
	printf("Stack Underflow!....\n");
	else
	{
		int val;
		struct node *temp=top;
		val=top->data;
		top=top->next;
		free(temp);
		return val;
	}
}

int peek()
{
	if(top==NULL)
	printf("Stack Underflow!...\n");
	else
	return (top->data);
}

void display()
{
	if(top==NULL)
	printf("Stack Underflow!...\n");
	else
	{
		printf("The stack is:\n");
		struct node *temp=top;
		while(temp->next!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("%d-->NULL\n",temp->data);
	}
}

int main()
{
	int choice,val;
	do
	{
		printf("\n1.Push\n2.Pop\n3.Peek\n4.Display All\n5.Exit\n");
		printf("Enter your choice:\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the element to be pushed:\n");
				scanf("%d",&val);
				push(val);
				break;
			case 2:
				printf("The popped item is %d.\n",pop());
				break;
			case 3:
				printf("The top element from the stack is %d.\n",peek());
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exit!.\n");
				break;
			default:
				printf("Enter valid choice:(1/2/3/4)\n");
		}
	}while(choice!=5);
	return 0;
}