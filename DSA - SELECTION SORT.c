#include<stdio.h>

void printArray( int *A , int size )
{
	int i;
	for( i=0; i<size; i++ )
	{
		printf("%d ",A[i] );
	}
	printf("\n");
}

void selectionSort( int *A , int size )
{
	int i , j , temp , indexofmin;
	for( i=0; i<size-1; i++ )
	{
		indexofmin = i;
		for( j=i+1; j<size; j++ )                        // FOR SEARCHING SMALLEST ELEMENT
		{
			if( A[j]<A[indexofmin] )
			{
				indexofmin = j;
			}
		}
		// smallest element founded now we have to swap it with i element;
		temp = A[i];                                    
	    A[i] = A[indexofmin];
	    A[indexofmin] = temp;
		
	}
}

int main()
{
	int A[] = { 12,3,23,43,4,5};
	int size = 6;
	printf("ARRAY BEFORE SORTING\n");
	printArray( A , size );
	selectionSort( A , size );
	printf("ARRAY AFTER SORTING\n");
	printArray( A , size ); 
	
	return 0;
}
