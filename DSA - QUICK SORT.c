#include<stdio.h>


void printArray( int A[] , int n )
{
	int i;
	for( i=0; i<n; i++ )
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}
int partition( int A[] , int low , int high )
{
	int pivot = A[low];
	int i = low+1;
	int j = high;
	int temp;
	do
	{
		while( A[i] <= pivot )
		{
		   i++;
		}
		
		while( A[j] > pivot )
		{
			j--;
		}
		
		if( i < j )
		{
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}while( i < j );
	
	if( j <= i )
	{
	   temp = A[low];
	   A[low] = A[j];
	   A[j] = temp;
    }
  
    
    return j;
}


void quickSort( int A[] , int low , int high )
{
	if( low < high )
	{
	int partitionIndex;
	partitionIndex = partition( A , low ,high );
	quickSort( A , low , partitionIndex-1 );
	quickSort( A , partitionIndex+1 , high );
    }
	
}
int main()
{
	int A[] = { 6,5,3,4,9,7,8 };
	int n = 7;
	printf("ARRAY BEFORE SORTING\n");
	printArray( A , n);
	quickSort( A , 0 , 6);
	printf("ARRAY AFTER SORTING\n");
	printArray( A , n );
	
	return 0;
}
