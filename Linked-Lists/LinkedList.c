/*
* Simple Linked List Implementation
* under handles : l0n3w0lf / l0n3noob / chicagobostondeveloper@gmail.com / kksv / varmas 
*/

#include<stdio.h>
#include<stdlib.h>

struct node{
struct node* next;
int data;
};

void TraverseListH2T(struct node* head){
if(head==NULL){
  printf("\nEmpty List\n");
  return;
  }

  struct node* tmp = head;
	
	//Start data function here
	printf("%d ",tmp->data);
	//End data function here

	if(tmp->next!=NULL){	
	TraverseListH2T(tmp->next);
	}
}

void TraverseListT2H(struct node* head){
  if(head==NULL){
    printf("\nEmpty List\n");
    return;
  }
  
  struct node* tmp = head;
	
	if(tmp->next!=NULL){
	  TraverseListT2H(tmp->next);
	}
	
	//Start data function here
	printf("%d ",tmp->data);
	//End data function here
}

void InsertAtHead(struct node** head,struct node* newNode){
	newNode->next=*head;
	*head=newNode;
}

void DeleteAtHead(struct node** head){
	struct node* tmp_head=*head;
	*head=tmp_head->next;
	free(tmp_head);
}

void DeleteAtTail(struct node**head){
	struct node* tmp_head=*head;
	struct node* next;
	while(tmp_head!=NULL){
	  next=tmp_head->next;
	  free(tmp_head);
	  tmp_head=next;
	}

}

void InsertAtTail(struct node** head,struct node* newNode){
	struct node* tmp_head = *head;
	while(tmp_head->next!=NULL)
	  tmp_head=tmp_head->next;
	tmp_head->next=newNode;
}

int InsertAtSomeplace(int count,struct node* newNode,struct node** head){
	struct node* tmp_head = *head;
	int temp_count=0;
	while(tmp_head->next!=NULL){
	  tmp_head=tmp_head->next;
	  if(++temp_count==count-1)
		  break; 
	 }
	
	if(temp_count==count-1){
	  newNode->next=tmp_head->next;
	  tmp_head->next=newNode;
	  return 1;
	}
	return 0;
}

struct node* newNode(int data){
  struct node* tmp_Node = NULL;
  tmp_Node = malloc(sizeof(struct node));
	tmp_Node->data = data;
	tmp_Node->next = NULL;
return tmp_Node;
}

int main(int argc,char *argv[]){
	
struct node* head=NULL;
struct node* one=NULL;
struct node* two=NULL;
	
	head = malloc(sizeof(struct node));
	one = malloc(sizeof(struct node));

	head->data = 1;
	head->next=one;
	
	one->data = 11;
	
	two = newNode(2);
	
	one->next = two;

	printf("Before Insertion H2T \n");
	TraverseListH2T(head);
	
	printf("Before Insertion T2H \n");
	TraverseListT2H(head);

	InsertAtHead(&head,newNode(13));
	printf("\nAfter Insertion at Head\n");
	TraverseListH2T(head);
	
	InsertAtTail(&head,newNode(99));
	printf("\nAfter Insertion at Tail\n");
	TraverseListH2T(head);

	printf("\nAfter Insertion at Someplace: (1,0 flags) %d\n",InsertAtSomeplace(2,newNode(256),&head));
	TraverseListH2T(head);	

	printf("\nAfter Deletion at Head\n");
	DeleteAtHead(&head);
	TraverseListH2T(head);

	printf("\nAfter Deletion at Tail\n");
	DeleteAtTail(&head);
	TraverseListH2T(head);

	printf("\nProgram ended\n");
	
	TraverseListH2T(NULL);

return 0;
}
