#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *next;
};

int isEmpty( struct Node *ptr )
{
	if( ptr == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isFull( struct Node *ptr )
{
	struct Node *sp = (struct Node*)malloc(sizeof(struct Node));
	if( sp == NULL )
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
	if(isFull(top))
	{
		printf("STACK OVERFLOW\n");
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

int pop( struct Node** top )
{
	if( isEmpty(*top))
	{
		printf("STACK UNDERflOW\n");
		return -1;
	}
	else
	{
		struct Node *n = *top;
		*top= (*top)->next;
		int x = n->data;
		free(n);
		return x;
	}
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

int stackBottom( struct Node *top)
{
	while( top!=NULL )
	{
		top=top->next;
	}
	return top->data;
}

int stackTop( struct Node *top )
{
	return top->data;
}

void taversal( struct Node *top )
{
	while( top!=NULL )
	{
		printf("ELEMENT IS:%d\n",top->data);
		top=top->next;
	}
}

int main()
{
	struct Node *top = NULL;
	top = push( top , 7);
	top = push( top , 14);
	top = push( top , 28);
	top = push( top , 35);
	printf("STACKS BEFORE OPERATION\n");
	traversal(top);
	printf("%d is now popped\n",pop(&top));
	printf("%d is the 3 element\n",peek(top,3));
	printf("%d is top of stack\n",stackTop(top));
	printf("%d us bottom element of stack\n",stackBottom(top));
	printf("STACKS AFTER OPERATION\n");
	traversal(top);
	return 0;
}
