#include<stdio.h>
#include<stdlib.h>

struct circularQueue 
{
	int size;
	int f;
	int r;
	int *arr;
};

int isEmpty( struct circularQueue *q )
{
	if( q->f == q->r )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull( struct circularQueue *q )
{
	if( ((q->r+1)%q->size) == q->f )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqueue( struct circularQueue *q , int val )
{
	if( isFull(q) )
	{
		printf("QUEUE IS FULL\n");
	}
	else
	{
		q->r = (q->r+1)%q->size;
		q->arr[q->r] = val;
		printf("ELEMENT %d IS ENQUEUED\n",val );
	}
}

void dequeue( struct circularQueue *q )
{
	int val = -1;
	if( isEmpty(q) )
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		q->f = (q->f+1)%q->size;
		val = q->arr[q->f];
		printf("%d ELEMENT IS DEQUEUED\n" , val );
	}
}

int main()
{
	struct circularQueue *q = (struct circularQueue*)malloc(sizeof(struct circularQueue));
	q->size = 4;
	q->f = q->r = 0;
	q->arr = (int*)malloc(q->size * sizeof(int));
	enqueue( q , 5 );
	enqueue( q , 6 );
	enqueue( q , 9 );
	
	dequeue( q );
	dequeue( q );
	dequeue( q );
	
	enqueue( q , 45 );
	enqueue( q , 69);
	enqueue( q , 96);
	
	if( isEmpty(q) )
	{
		printf("QUEUE IS EMPTY\n");
	}
	if( isFull(q) )
	{
		printf("QUEUE IS FULL\n");
	}
	
	return 0;
}
