//insertionsort
#include<stdio.h>
void Insertsort(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        int pivot=a[i];
        int j=i-1;
        while(a[j]>pivot && j>=0)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=pivot;
    }
}
printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

int main()
{
    int a[]={56,67,23,45,76,12,55};
    int n=sizeof(a)/sizeof(a[0]);
    Insertsort(a,n);
    printArray(a,n);
}
