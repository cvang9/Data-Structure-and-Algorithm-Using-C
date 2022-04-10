#include<stdio.h>
int main()
{
	int arr[20] = {1,2,4,56,75,89};
	printf("ARRAY BEFORE INSERTION\n");
	display( arr,6 );
	if( indInsert( arr,6,2,20,3) == 1 )
	{
	printf("SUCCESSFULLY INSERTED\n");
	printf(" ARRAY AFTER INSERTION\n ");
		display( arr,7);
    }
	else
	printf("UNSUCCESSFULL INSERTION\n");
    return 0;
}

void display( int arr[], int size)
{
	int i;
	for(  i=0; i < size; i++)
	{
		printf("%d ,",arr[i]);
	}
	printf("\n");
}

	int indInsert( int a[] , int size, int index, int capacity , int element)
{     int i;
    if( size>=capacity)
    return -1;
	for( i=size-1; i>=index; i--)
	{
	a[i+1]=a[i];	
	}
    a[index] = element;	
    return 1;
}

