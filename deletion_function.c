#include<stdio.h>

void display(int arr[],int n)
{
    printf("The elements are:\n");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

void deletion(int arr[],int n,int pos)
{
    if(pos>=n+1)
    printf("Deletion is not posssible in the array.......\n");
    else
    {
        for(int i=pos-1;i<n-1;i++)
        arr[i]=arr[i+1];
    }
}

int main()
{
int a[100],n,i,index;
printf("Enter the no of elements:\n");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
display(a,n);
printf("\nEnter the position of the array you want to delete:\n");
scanf("%d",&index);
deletion(a,n,index);
n-=1;
display(a,n);
return 0;
}