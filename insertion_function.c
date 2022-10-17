#include<stdio.h>

void display(int arr[],int n)
{
    printf("The elements are:\n");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}

int insertion(int arr[],int n,int index,int element,int cap)
{
    if(n>=cap)
    printf("Insertion is not possible......\n");
    else
    {
        for(int i=n-1;i>=index-1;i--)
        arr[i+1]=arr[i];
        arr[index-1]=element;
    }
    return 1;
}

int main()
{
    int arr[100],n,i,element,index;
    printf("Enter the no of elements:\n");
    scanf("%d",&n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);
    display(arr,n);
    printf("\nEnter the element you want to insert and also enter its index:\n");
    scanf("%d%d",&element,&index);
    insertion(arr,n,index,element,100);
    n+=1;
    display(arr,n);
return 0;
}