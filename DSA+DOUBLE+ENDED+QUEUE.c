#include<stdio.h>
#include<stdlib.h>

struct DEqueue
{
	int size;
	int f;
	int r;
	int *arr;
};

int isEmpty( struct DEqueue *dq )
{
	if( dq->r == -1)
	{
	   return 1;	
	}
	else
	{
		return 0;
	}
}

int isFull( struct DEqueue *dq )
{
	if( dq->r == dq->size-1 )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enqAtFront( struct DEqueue *dq , int val )
{
	if( dq->f >= 0 )
	{
	   dq->arr[dq->f] = val;
	   dq->f--;
	}
	else
	{
		printf("EITHER QUEUE IS EMPTY OR QUEUE IS FULL AT FRONT\n");
	}
}

void enqAtRear( struct DEqueue *dq , int val )
{
	if( isFull( dq ))
	{
		printf("QUEUE IS FULL AT REAR\n");
	}
	else
	{
		dq->r++;
		dq->arr[dq->r] = val;
	}
}

int deqAtFront( struct DEqueue *dq )
{
	int val = -1;
	if( isEmpty( dq ) )
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		dq->f++;
		val =  dq->arr[dq->f];
	}
	return val;
}

int deqAtRear( struct DEqueue *dq )
{
	int val = -1;
	if( isEmpty( dq ))
	{
		printf("QUEUE IS EMPTY\n");
	}
	else
	{
		val = dq->arr[dq->r];
		dq->r--;
	}
	return val;
}

int main()
{
	struct DEqueue *dq = (struct DEqueue*)malloc( sizeof( struct DEqueue ) );
	dq->size = 10;
	dq->f = dq->r = -1;
	dq->arr = (int*)malloc( dq->size * sizeof( int ) );
	
	enqAtRear( dq , 5 );
	enqAtRear( dq , 6 );
	enqAtRear( dq , 7 );
	enqAtRear( dq , 8 );
	enqAtRear( dq , 9 );
	printf("%d: ELEMENT IS DEQUEUED AT REAR\n",deqAtRear(dq) );
	printf("%d: ELEMENT IS DEQUEUED AT FRONT\n",deqAtFront(dq) );
	enqAtFront( dq , 69 );
	enqAtFront( dq , 69 );
	printf("%d: ELEMENT IS DEQUEUED AT FRONT\n",deqAtFront(dq) );
		
	return 0;
}
