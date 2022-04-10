#include<stdio.h>
#include<stdlib.h>

struct Node *f = NULL;
struct Node *r = NULL;
	
struct Node
{
	int data;
	struct Node *next;
};

void traversal( struct Node *f )
{
	printf("QUEUE ELEMENTS ARE:\n");
	while( f != NULL)
	{
		printf("ELEMENT: %d \n",f->data );
		f = f->next;
	}
}

int isEmpty()
{
	if( f==NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull()
{
	struct Node *ptr = (struct Node*)malloc( sizeof( struct Node ));
	if( ptr==NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue( int val )
{
	if( isFull() )
	{
		printf("QUEUE IS FULL\n");
	}
	else
	{
		struct Node *ptr = (struct Node*)malloc(sizeof( struct Node ));
		ptr->next = NULL;
		ptr->data = val;
		if( f==NULL )
		{
			f = r = ptr;
		}
		else
		{
			r->next = ptr;
			r = ptr;
		}
	}
}

void dequeue()
{
	int val;
	if( isEmpty(f) )
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		val = f->data;
		f   = f->next;
		printf("ELEMENT %d is DEQUEUED\n",val );
	}
}

int main()
{
	enqueue( 6 );
	enqueue( 7 );
	enqueue( 9 );
	enqueue( 8 );
	dequeue( );
	printf("ELEMENTS AFTER OPERATIONS\n");
	traversal( f );
	
	return 0;
}
