#include<stdio.h>
void main()
{
	int i,j,swap,*a=NULL,m,x;
	printf("Enter the size of the array:");
	scanf("%d",&x);
	a=(int *)malloc(x*sizeof(int));
	
	printf("Enter the array elements:");
	for(i=0;i<x;i++)
	scanf("%d",&a[i]);
	for(i=0;i<x-1;i++)
	{
		for(j=0;j<x-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap=a[j];
				a[j]=a[j+1];
				a[j+1]=swap;
				
				for(m=0;m<x;m++)
				if(m==j)
				printf("(%d)",a[m]);
				else
				printf("%d",a[m]);
				printf("\n");
				getch();
			}
		}
	}
	
	printf("The array after bubble sort: ");
	for(i=0;i<x;i++)
	printf("%d ",a[i]);
}









