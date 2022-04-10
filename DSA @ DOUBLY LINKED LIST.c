#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
	struct Node*prev;	
};

//TRAVERSAL FROM BOTH SIDES
void traversal( struct Node*head )
{
	printf("*FORWARD TRAVERSAL\n");
	while( head->next!=NULL )
	{
		printf("ELEMENT IS:%d\n",head->data);
		head = head->next;
	}
	printf("ELEMENT IS:%d\n",head->data);
	printf("*REVERSE TRAVERSAL\n");
	while( head!=NULL )
	{
		printf( "ELEMENT IS:%d\n",head->data);
		head = head->prev;
	}
}

int main()
{
	struct Node*head, *second , *third , *end;
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	end = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 6;
	head->next = second;
	head->prev = NULL;
	
	second->data = 7;
	second->next = third;
	second->prev = head;
	
	third->data = 8;
	third->next = end;
	third->prev = second;
	
	end->data = 9;
	end->next = NULL;
	end->prev = third;
	
	traversal( head );
	return 0;
}
