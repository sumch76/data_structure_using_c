//mergesort
#include <stdio.h>

void merge(int a[], int s1, int e1, int s2, int e2);
void mergesort(int a[], int i, int j);
void printArray(int a[], int n);

void mergesort(int a[], int i, int j) {
    if (i < j) {
        int mid = (i + j) / 2;
        mergesort(a, i, mid);
        mergesort(a, mid + 1, j);
        merge(a, i, mid, mid + 1, j);
    }
}

void merge(int a[], int s1, int e1, int s2, int e2) {
    int temp[50], i = s1, j = s2, k = 0;

    while (i <= e1 && j <= e2)
     {
        if (a[i] < a[j]) 
        {
            temp[k++] = a[i++];
        }
              else 
           {
            temp[k++] = a[j++];
           }
    }

    while (i <= e1) 
    {
        temp[k++] = a[i++];
    }

    while (j <= e2)
     {
        temp[k++] = a[j++];
      }

    for (k = 0, i = s1; i <= e2; i++, k++) {
        a[i] = temp[k];
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int a[] = {56, 67, 23, 45, 76, 12, 55};
    int n = sizeof(a) / sizeof(a[0]);
    mergesort(a,0,n - 1);
    printArray(a, n);
    return 0;
}
