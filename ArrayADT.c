#include<stdio.h>
#include<stdlib.h>

struct myArray
	{
		int total_size;
		int used_size;
		int *ptr;
	};
	
	
	void head( struct myArray*a, int tsize, int usize)
	{
		a->total_size = tsize;
		a->used_size =  usize;
		a->ptr = (int*)malloc(tsize*sizeof(int));
	}
	
	void primt(struct myArray * a)
	{
		int i;
		for( i=0; i< a->used_size; i++)
		{
			printf("%d\n",(a->ptr)[i]);
		}
	}
	
	void scam( struct myArray * a)
	{
		int n,j;
		for( j=0; j< a->used_size; j++)
		{
			printf("ENTER ELEMENT %d\n",j);
			scanf("%d",&n);
			(a->ptr)[j]=n;
		}
	}

int main()
{
	struct myArray marks;
	head(&marks,10,2);
	printf("SCANNING\n");
	scam(&marks);
	printf("PRINTING\n");
	primt(&marks);
	
	return 0;	
	
}
