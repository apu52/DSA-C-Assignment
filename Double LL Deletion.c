#include <stdio.h>
#include <stdlib.h>
typedef struct node {
        int data;
        struct node *next;
        struct node *prev;
} node;
node *start = NULL, *new_node, *temp = NULL, *prev = NULL;

void create();
void insert_begn();
void insert_end();
void insert_bef();
void insert_pos();
void delete_begn();
void delete_end();
void delete_pos();
void display();
int count();

int main() {
        printf(" 1. Insert at Beginning\n");
        printf(" 2. Delete from Beginning\n");
        printf(" 3. Delete from End\n");
        printf(" 4. Delete at Position\n");
        printf(" 5. Display\n");
        printf(" 6. Count Items\n");
        printf(" 7. Exit\n");
        while (1) {
                int c; printf("\nEnter choice: "); scanf("%d", &c);
                switch (c) {
                        case 1: insert_begn(); break;
                        case 2: delete_begn(); break;
                        case 3: delete_end(); break;
                        case 4: delete_pos(); break;
                        case 5: display(); break;
                        case 6: count(); break;
                        case 7: exit(1);
                        default: printf("Wrong choice!\n");
                }
        }
        return 0;
}

void create() {
        int n; printf("Enter data: "); scanf("%d", &n);
        new_node = (node*)malloc(sizeof(node));
        new_node->data = n;
        new_node->next = NULL;
        new_node->prev = NULL;
}

void display() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                temp = start;
                printf("Linked list elements: START -> ");
                while (temp != NULL) {
                        printf("%d -> ", temp->data);
                        temp = temp->next;
                }
                printf("END");
        }
        printf("\n");
}

int count() {
        int c = 0;
        temp = start;
        while (temp != NULL) {
                c++;
                temp = temp->next;
        }
        printf("Item count: %d\n", c);
        return c;
}

void insert_begn() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
        		start->prev = new_node;
                new_node->next = start;
                start = new_node;
        }
}

void insert_end() {
        create();
        if (start == NULL) {
                start = new_node;
        } else {
                temp = start;
                while (temp->next != NULL) {
                        temp = temp->next;
                }
                temp->next = new_node;
        }
}

void delete_begn() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                temp = start;
                printf("Deleted: %d", temp->data);
                start = temp->next;
                free(temp);
        }
        printf("\n");
}

void delete_end() {
        if (start == NULL) {
                printf("Underflow!");
        } else {
                if (start->next == NULL) {
                        printf("Deleted: %d", start->data);
                        start = NULL;
                } else {
                        temp = start;
                        while (temp->next != NULL) {
                                prev = temp;
                                temp = temp->next;
                        }
                        printf("Deleted: %d", temp->data);
                        prev->next = NULL;
                        free(temp);
                }
        }
        printf("\n");
}

void insert_pos() {
        int c = count();
        int pos; printf("Enter position to insert at: "); scanf("%d", &pos);
        if (pos == 1) {
                insert_begn();
        } else if (pos == c) {
                insert_end();
        } else if (pos > 1 && pos < c) {
                int i = 1;
                temp = start;
                while (temp != NULL && i < pos) {
                        temp = temp->next;
                        i++;
                }
                create();
                new_node->next = temp->next;
                temp->next = new_node;
        } else {
                printf("Invalid postion!\n");
        }
}

void delete_pos() {
        int c = count();
        int pos; printf("Enter position to delete at: "); scanf("%d", &pos);
        if (pos == 1) {
                delete_begn();
        } else if (pos == c) {
                delete_end();
        } else if (pos > 1 && pos < c) {
                int i = 1;
                temp = start;
                while (temp != NULL && i < pos) {
                		prev = temp;
                        temp = temp->next;
                    	i++;
                }
                printf("Deleted: %d\n", temp->data);
                prev->next = temp->next;
                temp->next->prev = prev;
                free(temp);
        } else {
                printf("Invalid postion!\n");
        }
}
