#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5
int size=1;

struct Node 
{
    int data;
    struct Node* next;
};
typedef struct Node* node;
node front = NULL;
node rear = NULL;


void enqueue() 
{
    int data;
    if (size==MAX_SIZE) 
    {
        printf("\nOverflow!\n");
        return;
    }

    printf("Enter data to insert: ");
    scanf("%d", &data);
    node newNode = (node)malloc(sizeof(struct Node));

    newNode->data = data;
    newNode->next = NULL;
    if (rear==NULL) 
    {
        front = rear = newNode;
        return;
    }
    rear->next = newNode;
    rear = newNode;
    size++;
}

void dequeue() 
{
    if (front == NULL) 
    {
        printf("\nUnderflow!\n");
        return;
    }
    printf("Deleted Element: %d",front->data);
    node temp = front;
    front = front->next;

    if (front == NULL) 
        rear = NULL;

    free(temp);
}

void display() 
{
    if (front == NULL) 
    {
        printf("\nUnderflow!\n");
        return;
    }

    printf("Queue elements: ");
    struct Node* current = front;
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void main() 
{
    int choice;

    while (1) 
    {
        printf("\nQueue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
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
            default:
                printf("Invalid choice.\n");
        }
    }
}
