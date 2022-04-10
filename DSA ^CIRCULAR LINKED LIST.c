#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*node;
};

//TRAVERSAL
void traversal( struct Node*head )
  
{
	struct Node*ptr = head;
	do{
		printf("ELEMENT IS :%d\n",ptr->data);
		ptr = ptr->node;
	  }while(ptr!=head );
}
//INSERTION AT HEAD
 struct Node* insertAtHead( struct Node*head , int data )
 {
 	struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
 	ptr->data = data;
 	
 	struct Node*p = head;
 	p = p->node;
 	while( p->node!=head )
 	{
 	 p = p->node;
	}
	p->node = ptr;
	ptr->node = head;
	
	return ptr;
 }

int main()
{
   struct Node *head , *second , *third ,*end;
   head = (struct Node*)malloc(sizeof(struct Node));
   second = (struct Node*)malloc(sizeof(struct Node));
   third = (struct Node*)malloc(sizeof(struct Node));
   end = (struct Node*)malloc(sizeof(struct Node));
   	
   	head->data = 9;
   	head->node = second;
   	
   	second->data = 6;
   	second->node = third;
   	
   	third->data = 9;
   	third->node = end;
   	
   	end->data = 6;
   	end->node = head;
   	
   	printf("\nCIRCULAR LINKED LIST BEFORE OPERATIONS\n");
   	traversal(head);
   	head = insertAtHead( head ,6 );
   	printf("\nCIRCULAR LINKED LIST AFTER OPERATIONS\n");
   	traversal(head);
}
