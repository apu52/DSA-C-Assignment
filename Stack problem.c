#include<stdio.h>
#include<stdlib.h>

#define size 5
int i,top=-1,arr[size];
void push();
void pop();
void Display();

void main()
{
	int choice;
	
	while(1)
	{
		printf("\nOperators in the stack:");
		printf("\n1.for push\n2.for pop\n3.Display\n4.End:");
		printf("\nEnter the choice:");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			push();
			break;
			case 2:
			pop();
			break;
			case 3:
			Display();
			break;
			case 4:
			end(1);
		    default:
		    printf("\nInvalid Input\n");
		}
		
	}
}

void pop()
{
	if(top==-1)
	printf("\nIt is UNDERFLOW\n");
	else
	{
		printf("\nThe popped element is:%d",arr[top]);
		top--;
	}
}
void push()
{
	int x;
	if(top==size-1)
	printf("\nit is OVERFLOW");
	else
	{
		printf("\nEnter the element pushed:");
		scanf("%d",&x);
		top++;
		arr[top]=x;
	}
}
void Display()
{
	if(top==-1)
	printf("\nIt is UNDERFLOW\n");
	else
	{
		printf("\nElement present in the stack:");
		for(i=top;i>=0;i--)
		printf("%d ",arr[i]);
	}
}















