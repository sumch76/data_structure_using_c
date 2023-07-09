//selectionsort
#include<stdio.h>
void SelectionSort(int a[],int n)
{
    int i,j,min,temp;
    for(i=1;i<n;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
               min=j;
            }
        }
            temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
    }
printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf(" %d",a[i]);
    }
}
int main()
{
    int a[]={12,45,67,87,34,66};
    int n=sizeof(a)/sizeof(a[0]);
    SelectionSort(a,n);
    printArray(a,n);
}
