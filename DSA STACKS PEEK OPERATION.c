#include<stdio.h>
#include<stdlib.h>

struct stack 
{
	int size;
	int top;
	int *arr;
};

int isEmpty( struct stack*ptr )
{
	if( ptr->top == -1 )
	{
		return 1;
	}
	else
	{
	  return 0;
	}
}

int isFull( struct stack*ptr )
{
	if( ptr->top == ptr->size-1 )
	{
		return 1;
	}
	else
	{
	  return 0;
	}
}

void push( struct stack*ptr , int val )
{
	if( isFull(ptr))
	{
		printf("STACK OVERLOW\n");
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top] = val;
	}
}

int pop( struct stack*ptr )
{
	if( isEmpty( ptr ))
	{
		printf("STACK UNDERFLOW\n");
		return-1;
	}
	else
	{
		int val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}
  int peek( struct stack*ptr , int i)
	{
		int arrayIndex = ptr->top-i+1;
		if( (arrayIndex)<0 )
		{
			printf("INVALID POSITION ENTERED\n");
			return -2;
		}
		else
		{
			return ptr->arr[arrayIndex];
		}
	}

int main()
{   int j;
	struct stack*sp = (struct stack*)malloc(sizeof(struct stack));
	sp->size = 10;
	sp->top = -1;
	sp->arr = (int*)malloc( sp->size*sizeof(int));

	push( sp , 4);							   							//     | 	8	|
	push( sp , 6);                                                    //       |    7   |      <----STACK
	push( sp , 7);                                                   //        |  	6	|
	push( sp , 8);                                                  //         |____4___|
	push( sp , 9);
	printf( "%d is popped\n",pop(sp));
	for( j=1 ; j<=sp->top+1; j++)
	{
	     printf( "%d is element of %d position\n",peek(sp ,j),j );	
	}
	
}
