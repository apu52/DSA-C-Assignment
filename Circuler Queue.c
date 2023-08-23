#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

int cqueue[MAX_SIZE];
int front = -1, rear = -1;

int isFull() 
{
    return ((rear + 1) % MAX_SIZE == front);
}

int isEmpty() 
{
    return (front == -1 && rear == -1);
}

void enqueue() 
{
    int value;
    printf("Enter the number to be inserted: ");
    scanf("%d",&value);

    if (isFull())
    { 
        printf("Queue is full.\n");
        return;
    }
    else 
    {
        if (isEmpty())
            front = rear = 0;
        else
            rear = (rear + 1) % MAX_SIZE;

        cqueue[rear] = value;
        printf("\n%d enqueued to the queue.\n", value);
    }
}

void dequeue() 
{
    int value;
    if (isEmpty()) 
    {
        printf("\nQueue is empty.\n");
        return;
    } 
    else 
    {
        value = cqueue[front];

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX_SIZE;

        printf("\nDequeued Element: %d",value);
    }
    return;
}

void display() {
    if (isEmpty()) 
    {
        printf("\nQueue is empty.\n");
        return;
    } 
    else 
    {
        int i = front;
        printf("Queue elements: ");
        while (i != rear) {
            printf("%d ", cqueue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", cqueue[rear]);
    }
}

int main() 
{
    int choice;
	
	while(1)
	{
		printf("\n\nOperators in the queue:");
		printf("\n1.Insert\n2.Delete\n3.Display\n4.End");
		printf("\nEnter the choice: ");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
			    enqueue();
			    break;
			case 2:
                dequeue();
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
