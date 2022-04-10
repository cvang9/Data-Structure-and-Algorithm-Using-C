#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	char *arr;
};

int isEmpty( struct stack *ptr )
{
	if( ptr->top==-1 )
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

void push( struct stack *ptr , char val)
{
	if( isFull(ptr) )
	{
		printf("STACK OVERFLOW\n");
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top]=val;
	}
}

void pop( struct stack *ptr )
{
	if( isEmpty(ptr) )
	{
		printf("STACK UNDERFLOW\n");
	}
	else
	{
		ptr->top--;
	}
}

int paranthesisMatching( char *exp )
{
	struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
	sp->size = 20;
	sp->top = -1;
	sp->arr = (char*)malloc( sp->size * sizeof(char) );
	int i;
	
	for( i=0; exp[i]!='\0'; i++ )
	{
		if( exp[i]=='(')
		{
			push(sp,exp[i] );
		}
		else if( exp[i]==')' )
		{
			if( isEmpty(sp))
			{
				return 0;
			}
			pop(sp);
		}
	}
	if( isEmpty(sp))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int main()
{
	char *exp = "(())(*&)";
	if(paranthesisMatching(exp))
	{
		printf("EXPRESSION IS BALANCED\n");
	}
	else
	{
		printf("EXPRESSION IS UNBALANCED\n");
	}
}

//# <PINTU HACKER SOCIETY>



