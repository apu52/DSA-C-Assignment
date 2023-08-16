#include<stdio.h>
void merge(int A[], int mid, int low, int high)
{
    int i, j, k, B[100];
    i = low;
    j = mid + 1;
    k = low;

    while (i <= mid && j <= high)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        k++;
        i++;
    }
    while (j <= high)
    {
        B[k] = A[j];
        k++;
        j++;
    }
    for ( i = low; i <= high; i++)
    {
        A[i] = B[i];
    }
}


void mergeSort(int A[], int low, int high)
{
    int mid; 
    if(low<high){
        mid = (low + high) /2;
        mergeSort(A, low, mid);
        mergeSort(A, mid+1, high);
        merge(A, mid, low, high);
    }
}

void main()
{
    int i,j,s;
    printf("Enter the size of the array: ");
    scanf("%d",&s);
    int arr[s];
    printf("Enter the numbers to be sorted using Merge Sort in the array below:-\n");
    for(i=0;i<s;i++)
        scanf("%d",&arr[i]);

    printf("Unsorted array: ");
    for (i = 0; i < s; i++)
        printf("%d ", arr[i]);

    mergeSort(arr,0,s-1);
    
    printf("\nSorted array: ");
    for (i = 0; i < s; i++)
        printf("%d ", arr[i]);
}
