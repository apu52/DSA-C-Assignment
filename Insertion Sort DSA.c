#include<stdio.h>
#include<stdlib.h>
void main() //insertion sort       
{
    int i,j,k,min,x,temp, *a = NULL;
    printf("Enter the size of the array: ");
    scanf("%d",&x);
    a=(int *)malloc(x * sizeof(int)); //Dynamically allocated the array

    printf("Enter the numbers to be sorted in the array below:-\n");
    for(i=0;i<x;i++)
        scanf("%d",&a[i]);

    for(i=1;i<x;i++)
    {
        temp=a[i];
  
        for(j=i-1;j>=0 && a[j] > temp ; j--)
            a[j+1]=a[j];
            a[j+1]=temp;
        
    }
    printf("The sorted array: ");
     for(i=0;i<x;i++)
        printf("%d ",a[i]);
}
