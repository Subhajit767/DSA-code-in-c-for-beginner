#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left,*right;
};

struct node* create()
{
    int x;
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter data: (Press -1 for NULL)\n");
    scanf("%d",&x);
    if(x==-1)
    return NULL;
    newnode->data=x;
    printf("Enter left child of %d:\n",x);
    newnode->left=create();
    printf("Enter right child of %d:\n",x);
    newnode->right=create();
    return newnode;
}

void preorder(struct node* root)
{
    if(root==NULL)
    return;
    printf(" %d ",root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(struct node* root)
{
    if(root==NULL)
    return;
    inorder(root->left);
    printf(" %d ",root->data);
    inorder(root->right);
}

void postorder(struct node* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
    postorder(root->right);
    printf(" %d ",root->data);
}

int main()
{
    struct node* root=NULL;
    root=create();
    printf("\nPreorder is:\n");
    preorder(root);
    printf("\nInorder is:\n");
    inorder(root);
    printf("\nPostorder is:\n");
    postorder(root);
    return 0;
}