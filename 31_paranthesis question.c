#include<stdio.h>
#include<stdlib.h>

struct Node
{
	char data;
	struct Node *next;
};

int isEmpty( struct Node *top)
{
	if( top == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull( struct Node *top)
{
	struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
	if( ptr == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

struct Node *push( struct Node *top , char data )
{
	if(isFull(top))
	{
		printf("STACK OVERFLOW WHILE PUSHING\n");
		return top;
	}
	else
	{
		struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
		ptr->data = data;
		ptr->next = top;
		top = ptr;
		return top;
	}
}

void pop( struct Node **top)
{
	if( isEmpty(*top))
	{
		printf("STACK UNDERFLOW WHILE POPPING\n");
	}
	else
	{
	struct Node *ptr = *top;
	*top = (*top)->next;
	char c = ptr->data;
	free(ptr);
    }
}

int main()
{
	struct Node *top = NULL;
	char arr[10];
	int i;
	printf("ENTER THE EXPRESSION:\n");
	for( i=0; i<=8 ;i++)
	{
		scanf("%c",&arr[i]);
	}
	while( arr[i]!='\0')
	{
		if( arr[i] == '(' || '[' || '{' )
		{
			top = push( top , arr[i] );
		}
		if( arr[i] == ')' || ']' || '}' )
		{
			if(isEmpty(top))
			{
				printf("UNBALANCED EXPRESSION (by means of stack underflow)\n");
			}
			else
			{
			pop(&top);
		    }
		}
		i++;
	}
	if( top == NULL)
	{
		printf("BALANCED EXPRESSION\n");
	}
	else
	{
		printf("UNBALANCED EXPRESIION (by means of filled stack)\n");
	}
	
	return 0;
}
