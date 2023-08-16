#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int i,f=-1,r=-1,arr[SIZE];
void insert();
void delete();
void display();

void main()
{
	int choice;
	
	while(1)
	{
		printf("\nOperators in the queue:");
		printf("\n1.Insert\n2.Delete\n3.Display\n4.End");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			    insert();
			    break;
			case 2:
			    delete();
			    break;
			case 3:
			    display();
			    break;
			case 4:
			    exit(0);
                break;
		    default:
		        printf("\nInvalid Input\n");
		}
		
	}
}

void delete()
{
	if(f==-1 || f>r)
	    printf("\nUNDERFLOW!\n");
    else 
    {
        printf("\nThe deleted element is: %d",arr[f]);
        f++;
    }
}
void insert()
{
	int x;
	if(r==SIZE-1)
	    printf("\nOVERFLOW!");
    else
    {
        if(f==-1)
            f=0;
        printf("\nEnter the element inserted: ");
        scanf("%d",&x);
        r++;
        arr[r]=x;
    }
}
void display()
{
	if(f==-1)
	    printf("\nNo elements present in queue.\n");
	else
	{
		printf("\nElement present in the queue: ");
		for(i=f;i<=r;i++)
		    printf("%d ",arr[i]);
	}
}
