#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* next;
}*head;

struct node* createll(struct node* head, int n)
{
	int i,item;
	struct node* temp, *newnode;
	temp=(struct node *)malloc(sizeof(struct node));
	if (temp==NULL)
	{
		printf("Memory not allocated.\n");
		exit(0);
	}
	printf("Enter the 1st element:\n");
	scanf("%d", &item);
	temp->data=item;
	temp->next=NULL;
    head=temp;
	for(i=2;i<=n;i++)
    {
		newnode=(struct node *)malloc(sizeof(struct node)); 
		if (newnode==NULL)
		{
			printf("Memory not allocated.\n");
			exit(0);
		}
		printf("Enter the %d element:\n",i); 
		scanf("%d",&item); 
		newnode->data=item; 
		newnode->next=NULL; 
		temp->next=newnode; 
		temp=newnode;
	}
 	return head;
}

void printll(struct node* head)
{
	struct node* temp;
	
	if (head==NULL)
	{
		printf("List is empty.\n"); 
		exit(0);
	}  
	temp=head;
	while(temp!=NULL)
	{
 		printf("\n%d ",temp->data); 
		temp=temp->next;
	}
}

struct node* addbeg(struct node* head, int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node)); 
	temp->data=item;
	temp->next=NULL; 
    temp->next=head;
	head=temp;
	return head;
}

struct node* addend(struct node* head, int item)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
 	temp->data=item;
 	temp->next=NULL; 
	struct node *p=head;
	while (p->next!=NULL)
 		p=p->next;
	p->next=temp;
    return head;
 }
 
struct node* addnode(struct node* head, int item,int a)
{
	struct node *p=head;
	while(p->next!=NULL) 
	{
 		if (p->next->data==a)
		{
 			struct node* temp=(struct node*)malloc(sizeof(struct node));
 			temp->data=item;
 			temp->next=p->next;
			p->next=temp;
			return head;
		}
    	p=p->next;
	}
	return 0;
}
 
struct node* addNODE(struct node* head, int item, int a)
{
	struct node *p=head;
	while (p->next!=NULL)
	{
		if(p->data==a)
		{
			struct node* temp=(struct node *)malloc(sizeof(struct node));
			temp->data=item;
			temp->next=p->next;
			p->next=temp; 
			return head;
		}
		p=p->next;
	}
	return 0;
}

struct node* delbeg(struct node* head)
{
	struct node* temp=head;
	head=head->next;
	free(temp);
	return head;
}
 
struct node* delend(struct node* head)
{
	struct node* p=head;
	while (p->next->next!=NULL)
		p=p->next;
	struct node* temp=p->next;
	p->next=NULL;
	free (temp);
    return head;
}

struct node* delpart(struct node* head, int item)
{
	struct node* temp=head; 
	struct node* p=head->next;
	while (p!=NULL)
	{
		if (p->data==item)
		{
			temp->next=p->next;
			p->next=NULL;
			free(p);
		}
		p=p->next;
 		temp-temp->next;
 	}
 	return head;
}

int main()
{
	int n, choice,item, a;
  	printf("Enter the no of elements: \n"); 
	scanf("%d", &n); 
	head=createll(head,n);
	printf("The elements are:\n"); 
	printll(head); 
	while(1)
	{
		printf("\n1.Add at beg\n2.Add at end\n3.Add before a node\n4.Add after a node\n5.Delete fro beginning\n6.Delete from end\n7.Delete a particular node\n8.Exit\n"); 
		printf("Enter your choice:\n");
		scanf("%d", &choice); 
		switch(choice)
		{
			case 1:
 				printf("Enter data to insert:\n");
				scanf("%d", &item); 
				head=addbeg(head, item); 
				printf("After inserting:\n"); 
				printll(head);
				break;
			case 2:
				printf("Enter data to insert: \n");
				scanf("%d", &item); 
				head=addend(head, item); 
				printf("After inserting:\n"); 
				printll(head);
				break;
			case 3:
				printf("Enter the element to which data will be inserted before it:\n"); 
				scanf("%d",&a); 
				printf("Enter data to insert:\n");
				scanf("%d",&item); 
				head=addnode(head, item, a);
				printf("After inserting:\n");
				printll(head);
				break;
			case 4: 
				printf("Enter the element to which data will be inserted after it:\n"); 
				scanf("%d",&a);
				printf("Enter data to insert:\n");
				scanf("%d", &item); 
				head=addNODE(head,item,a);
				printf("After inserting:\n");
				printll(head);
				break;
			case 5:
				head=delbeg (head);
 				printf("After deleting:\n"); 
				printll(head);
				break;
			case 6:
				head=delend (head);
				printf("After deleting:\n"); 
				printll(head);
				break;
			case 7:
				printf("Enter the item to be deleted:\n"); 
				scanf("%d", &item); 
				head=delpart(head, item); 
				printf("After deleting:\n"); 
				printll(head);
				break;
			case 8:
				exit(0);
				break;
			default:
				printf("Wrong Input\n");
		}

	}
	return 0;
}