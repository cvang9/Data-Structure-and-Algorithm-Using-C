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
	if( ptr->top== -1 )
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
	if( ptr->top== ptr->size-1 )
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
		printf("STACK OVERFLOW OCCURS\nCannot push %d in stack\n ",val);
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}

int pop( struct stack*ptr )
{
	if( isEmpty(ptr) )
	{
		printf("STACK UNDERFLOW OCCURS\nCannot pop from stack\n");
		return -1;                                                      //ASSUMING -1 IS NOT ANY ELEMENT OF STACK
	}
	else
	{
		int val = ptr->arr[ptr->top];
		 ptr->top--;
		 return val;
	}
}

int main()
{
	struct stack *sp = (struct stack*)malloc( sizeof(struct stack) );
	sp->size = 4;
	sp->top = -1;
	sp->arr = (int *)malloc( sp->size*sizeof(int));
	
	//BEFORE OPERATION CODE
	printf("BEFORE OPERATIONS , FULL STATUS:%d\n",isFull(sp));
	printf("BEFORE OPERATIONS , EMPTY STATUS:%d\n",isEmpty(sp));
	
	//OPERATION CODE
	push( sp , 5);
	push( sp , 6);
	push( sp , 9);
    printf("%d:is popped\n",pop(sp)); 
    printf("%d:is popped\n",pop(sp)); 

    //AFTER OPERATION CODE
    printf("AFTER OPERATIONS , FULL STATUS:%d\n",isFull(sp));
    printf("AFTER OPERATIONS , EMPTY STATUS:%d\n",isEmpty(sp));

	return 0;
}
