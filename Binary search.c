#include<stdio.h>
void sort(int arr[],int size)
{
	int i,j,t;
	for(i=0;i<size-1;i++){
		for(j=0;j<size-1-i;j++){
			if(arr[j]>arr[j+1]){
				t=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=t;
			}
		}
	}
}

int main()
{
	int n,i,element,mid,pos,flag=0;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	sort(arr,n);
	printf("Enter the element to be sorted:");
	scanf("%d",&element);
	int start=0,end=n-1;
	while(start<=end){
		mid=start+(end-start)/2;
		if(element>arr[mid])
		start=mid+1;
		else if(element<arr[mid])
		end=mid-1;
		else{
			flag=1;
			pos=mid;
			break;
		}
	}
	if(flag==1){
		printf("Element found at position %d",pos);
	}
	else{
		printf("Element not found");
	}
}
