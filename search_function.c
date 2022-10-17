#include<stdio.h>

int linearsearch(int arr[],int n,int b)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(b==arr[i])
        return i+1;
    }
    return -1;
}

int binarysearch(int arr[],int n,int b)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(arr[mid]==b)
        return mid+1;
        else if(arr[mid]<b)
            low=mid+1;
        else
            high=mid-1;
    }
    return -1;
}

int main()
{
int a[100],n,i,search,ls,bs;
printf("Enter the no of element in the array:\n");
scanf("%d",&n);
printf("Enter the elements:\n");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
printf("Enter the element to be searched:\n");
scanf("%d",&search);
ls=linearsearch(a,n,search);
bs=binarysearch(a,n,search);
if(ls==-1 && bs==-1)
printf("Element is not found.....");
else
printf("For linear search %d is found at %d location.\nFor binary search %d is found at %d location",search,ls,search,bs);
return 0;
}