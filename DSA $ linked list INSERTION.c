#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
};

// CASE 1:
int insertAtHead( struct Node*head , int data )
{
	struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = head;
	
	return ptr;
}
 
 // CASE 2:
int insertAtMid( struct Node*head , int data , int index )
{
	struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	struct Node*p = head;
	int i = 0;
	while( i!= index-1)
	{
		p = p->next;
		i++;
	}
	ptr->next = p->next;
	p->next = ptr;
	
	return head;
}

 // CASE 3:
int insertAtEnd( struct Node*head , int data )
{
	struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	struct Node*p = head;
	int i = 0;
	while( p->next!=NULL)
	{
		p = p->next;
		i++;
	}
	p->next = ptr;
	ptr->next = NULL;
	
	return head;
}

 // CASE 4:
int insertAtGiven( struct Node*head , int data , struct Node*node )
{
	struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
	ptr->data = data;
	ptr->next = node->next;
    node->next = ptr;
	return head;
}

int main()
{
	struct Node *head, *second, *third, *end;
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	end = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 7;
	head->next = second;
	
	second->data = 8;
	second->next = third;
	
	third->data = 9;
	third->next = end;
	
	end->data = 10;
	end->next = NULL;
	
	printf("LINKED LIST BEFORE INSERTION\n");
	traverse(head);
//	head = insertAtHead( head , 6 );                              //INSERTION AT HEAD
//  head = insertAtMid( head , 66 , 2);                           //INSERTION AT MID
//   head = insertAtEnd( head, 69 );                             //INSERTION AT END 
//    head = insertAtGiven( head , 56 , end);                    //INSERTION AFTER GIVEN NODE
	printf("\nLINKED LIST AFTER INSERTION\n"); 
	traverse(head);
	
	return 0;
}

void traverse( struct Node*ptr )
{
	while( ptr!=NULL)
	{
		printf("ELEMENT : %d\n",ptr->data);
		ptr=ptr->next;
	}
}
