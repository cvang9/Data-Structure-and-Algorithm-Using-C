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

void push( struct stack *ptr , char val )
{
	if( isFull(ptr) )
	{
		printf("STACK OVERFLOW\n");
	}
	else
	{
		ptr->top++;
		ptr->arr[ptr->top] = val;
	}
}

char pop( struct stack *ptr )
{
	if( isEmpty(ptr) )
	{
		printf("STACK UNDERFLOW\n");
		return 'a';
	}
	else
	{
		char ch = ptr->arr[ptr->top];
		ptr->top--;
		return ch;
	}
}
	
	int match( char a , char b )
	{
		if( a=='{' && b=='}')
		{
			return 1;
		}
		if( a=='[' && b==']')
		{
			return 1;
		}
		if( a=='(' && b==')')
		{
			return 1;
		}
		return 0;	
	}
	
	int mBracesMatching( char *exp )
	{
		struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
		sp->top = -1;
		sp->size = 20;
		sp->arr = (char*)malloc(sp->size * sizeof(char));
		char popped_char;
		int i;
		for( i=0; exp[i]!='\0'; i++)
		{
		    if( exp[i] == '{' || exp[i] == '[' || exp[i] == '(' )
		    {
		    	push(sp,exp[i]);
		    }
		    if( exp[i] == '}' || exp[i] == ']'|| exp[i] == ')')
		    {
		    	if( isEmpty(sp) )
		    	{
	     			return 0;
		    	}
			  popped_char = pop(sp);
			  if(!match(popped_char , exp[i]))
	        	{
		        	return 0;
	    	    }
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
		char * exp = "{2{}+()()[][9-8]*(9-0)}";
		if(mBracesMatching(exp))
		{
			printf("EXPERSSION IS BALANCED\n");
		}
		else
		{
			printf("EXPRESSION IS UNBALANCED\n");
		}
		
		return 0;
	}
