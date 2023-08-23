#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node* next;
};

void inBegin(struct Node** next_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

    new_node->data = new_data;
    new_node->next = (*next_ref);

    (*next_ref) = new_node;
}


void inEnd(struct Node** next_ref, int new_data) 
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    struct Node* last = *next_ref; 

    new_node->data = new_data;
    new_node->next = NULL;

    if (*next_ref == NULL) 
    {
        *next_ref = new_node;
        return;
    }

    while (last->next != NULL) 
        last = last->next;

    last->next = new_node;
    return;
}


void delete(struct Node** next_ref, int key) 
{
    struct Node *temp = *next_ref, *prev;

    if (temp != NULL && temp->data == key) 
    {
        *next_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) 
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("The element is not present");
        return;
    }
    prev->next = temp->next;

    free(temp);
}




// Print the linked list
void display(struct Node* node) 
{
    if(node == NULL)
    {
        printf("\nThe Linked List is empty\n");
        return;
    }
    
    printf("\nThe current Linked List is: ");
    while (node != NULL) 
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


int main() 
{
    int ch,data,n;
    struct Node* head = NULL;

    while(1)
    {
        printf("\nEnter 1 for Insert At Beginning\nEnter 2 for Insert At End\nEnter 3 to Delete the Node\nEnter 4 to Display the List\nEnter 5 to Exit\n");
        printf("Enter the choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the number to be inserted at beginning: ");
                scanf("%d",&data);
                inBegin(&head,data);
                break;
            case 2:
                printf("\nEnter the number to be inserted at end: ");
                scanf("%d",&data);
                inEnd(&head,data);
                break;
            case 3:
                printf("\nEnter the number to be deleted: ");
                scanf("%d",&n);
                delete(&head,n);
                break;
            case 4:
                display(head);
                break;
            default:
                printf("\nExiting...\n");
                exit(0);
        }
    }
}
