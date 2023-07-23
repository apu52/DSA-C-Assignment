#include<stdio.h>
int main(){
	int n ,arr[n+1],i;
	printf("Enter the size of the array:");
	scanf("%d",&n);
	printf("Enter the array elements: \n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
		int element ,pos;
	    printf("Enter the element to be inserted:");
	    scanf("%d",&element);
	    printf("Enter the position you want to insert:");
	    scanf("%d",&pos);
	    arr[n]=0;
	    for(i=n;i>pos;i--){
	    	arr[i]=arr[i-1];
		}
		arr[pos]=element;
		for(i=0;i<n+1;i++){
			printf("%d ",arr[i]);
			
		}
	
}
