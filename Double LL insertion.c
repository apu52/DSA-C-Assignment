#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* prev;
	struct Node* next;
};
struct Node* head;struct Node* tail;struct Node* temp2;int c;
void Insert_beg(){
	int value;printf("Enter node data: ");scanf("%d",&value);
	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data=value;
	ptr->next=NULL;
	ptr->prev=NULL;
	if (head==NULL){
		head=ptr;
		tail=ptr;
	}
	else{
		ptr->next=head;
		head=ptr;
		ptr->next->prev=head;
		tail->next=ptr;
	}
}
void Insert_last(){
	int value;printf("Enter node data: ");scanf("%d",&value);
	struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
	ptr->data=value;
	ptr->next=NULL;
	ptr->prev=NULL;
	tail->next=ptr;
	ptr->prev=tail;
	tail=ptr;
}
void Insert_spec(){
	int value;printf("Enter node data: ");scanf("%d",&value);
	struct Node* ptr= (struct Node*)malloc(sizeof(struct Node));
	ptr->data=value;
	ptr->next=NULL;
	ptr->prev=NULL;
	struct Node* temp=head;
	int i=1,loc;
	printf("Enter location to insert: ");scanf("%d",&loc);
	for(i=1;i<loc;i++){
		temp=temp->next;
	}
	ptr->next=temp->next;
	temp->next=ptr;
	ptr->prev=temp;
	ptr->next->prev=ptr;
}
void Display(){
	if (head==NULL)printf("NULL\n\n");
	else{
		if(c>0){
			struct Node* temp; temp=head;
			printf("NULL<-");
			while(temp!=NULL){
				printf("%d->",temp->data);
				temp=temp->next;
			}
			printf("NULL\n\n");
		}
		else{
			struct Node* temp; temp=head;
			printf("NULL<-");
			while(temp!=tail){
				printf("%d->",temp->data);
				temp=temp->next;
			}
			printf("%d->NULL\n\n",temp->data);
		}
	}
}
void Exit(){
	exit(0);
}
int main(){
	int choice;
	while(1){
		printf("1.Insert at beginning\n2.Insert at Last\n3.Insert at specified position\n4.Display\n5.Exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: Insert_beg();break;
			case 2: Insert_last();break;
			case 3: Insert_spec();break;
            case 4: Display();break;
			case 5: Exit();break;
			default: printf("INVALID CHOICE\n\n");
		}
	}
}
