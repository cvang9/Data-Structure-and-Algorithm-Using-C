#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *arr;
};

int isEmpty( struct stack *ptr )
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

int isFull( struct stack *ptr )
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

void push( struct stack *ptr , int val)
{
	if( isFull( ptr ))
	{
		printf("STACK OVERFLOW\n");
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}

int pop( struct stack *ptr)
{
	if( isEmpty( ptr ))
	{
		printf("STACK UNDERFLOW\n");
		return -1;
	}
	else
	{
		int val = ptr->arr[ptr->top];
		ptr->top--;
		return val;
	}
}

int peek( struct stack *ptr , int i)
{
	int ind =  ptr->top-i+1;
	if( ind<0 )
	{
		printf("INVALID INDEX GIVEN\n");
		return -2;
	}
	else
	{
		return ptr->arr[ind];
	}
}

int stackTop( struct stack *ptr)
{
	return ptr->arr[ptr->top];
}

int stackBottom( struct stack *ptr )
{
	return ptr->arr[0];
}

int main()
{
	struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
	sp->size = 10;
	sp->top = -1;
	sp->arr = (int*)malloc( sp->size*sizeof(int));
	
	push( sp ,5 );
	push( sp ,6);
	push( sp ,9 );
	push( sp ,66 );
	push( sp ,99 );
	push( sp ,54 );
	push( sp ,56 );
	push( sp ,84 );
	push( sp ,99 );
	
printf("TOP ELEMENT OF STACK IS:%d\n",stackTop(sp));
printf("BOTTOM ELEMENT OF STACK IS:%d\n",stackBottom(sp));
printf("%d is now popped\n",pop(sp));
printf("%d is now popped\n",pop(sp));
printf("TOP ELEMENT OF STACK IS:%d\n",stackTop(sp));
printf("BOTTOM ELEMENT OF STACK IS:%d\n",stackBottom(sp));
printf("ELEMENT AT POSITION 4 IS:%d\n",peek(sp,4));
printf("ELEMENT AT POSITION 3 IS:%d\n",peek(sp,3));
}
