#include<stdio.h>
int main(){
	int n,i,element,pos,arr[n];
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be deleted:");
	scanf("%d",&element);
	for(i=0;i<n;i++){
		if(arr[i]==element){
			pos=i;
			break;
		}
	}
	for(i=pos;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	for(i=0;i<=n;i++){
		printf("%d ",arr[i]);
	}
}
