#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int size;
	int top;
	int *ar;
};

int main()
{
	struct stack sp;
	sp.size = 10;
	sp.top = -1;
	sp.ar = (int*)malloc(sp.size * sizeof(int));
	
//	sp.ar[0]==2;
//	sp.top++;

	//CHECKING STACK IS EMPTY OR NOT
	if( isEmpty(sp) )
	{
		printf("STACK IS EMPTY\n");
	}
	else
	{
		printf("STACK IS NOT EMPTY\n");
	}
	
	//CHECKING STACK IS COMPLETELY FILLED OR NOT
	if( isFilled(sp) )
	{
		printf("STACK IS FILLED\n");
	}
	else
	{
		printf("STACK IS NOT FILLED\n");
	}
	
	return 0;
	
}

int isEmpty( struct stack ptr)
{
	if( ptr.top == -1)
	{
		return 1;
	}
	return 0;
	
}

int isFilled( struct stack ptr)
{
	if( ptr.top == ptr.size-1)
	{
		return 1;
	}
	return 0;
}
