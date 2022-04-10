#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
};

int isEmpty( struct Node*top)
{
	if( top==NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull( struct Node*top )
{
	struct Node *n = (struct Node*)malloc(sizeof(struct Node));
	if( n==NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Node *push( struct Node *top , int data )
{
	if( isFull(top))
	{
	  printf("STACK OVERFLOW\n");
	  return top;
	}
	else
	{
		struct Node *n=(struct Node*)malloc( sizeof(struct Node));
		n->data = data;
		n->next = top;
		top = n;
		return top;
	}
}

int pop( struct Node** top )
{
	if( isEmpty(*top) )
	{
		printf("STACK UNDERFLOW\n");
		return -1;
	}
	else
	{
		struct Node*n= *top;
		int x = n->data;
		*top = (*top)->next;
		free(n);
		return x;
	}
}

int stackTop( struct Node *top )
{
	return top->data;
}
 
 int stackBottom( struct Node *top )
 {
 	while( top->next!=NULL )
 	{
 	 	top = top->next;
	}
	return top->data;
 }
 
 int peek( struct Node *top , int position )
{
	int i;
	struct Node *n = top;
	for( i=1; (i<=position-1 && n!=NULL); i++)
	{
		n = n->next;
	}
	if( n!=NULL)
	{
		return n->data;
	}
	else
	{
		return -2;
	}
}
 
 void traversal( struct Node*top )
 {
 	while( top!=NULL )
 	{
 		printf("ELEMENT IS:%d\n",top->data);
 		top=top->next;
	}
 }

int main()
{
	int i;
	struct Node *top = NULL;
    top = push( top , 5);
    top = push( top , 6);
    top = push( top , 7);
    top = push( top , 8);
    top = push( top , 9);
    top = push( top , 5);
    printf("STACK ELEMENTS BEFORE\n");
    traversal(top);
	printf("%d: is now Popped\n",pop(&top));
	printf("STACK ELEMENTS AFTER\n");
    traversal(top);
    printf("TOP OF STACK IS :%d\n",stackTop(top));
    printf("BOTTOM OF STACK IS :%d\n",stackBottom(top));
    for( i=1; i<=5;i++)
    {
    	printf("ELEMENT %d is at position %d\n",peek(top,i),i);
	}
    return 0;
}
