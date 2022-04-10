#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


void printArray( int A[] , int n )
{
	int i=0;
	for( i=0; i<n; i++ )
	{
		printf("%d ",A[i]);
	}
	printf("\n");
}

int maximum( int A[] , int n )
{
	int i;
	int max = 2;
	for( i=0; i<n; i++ )
	{
		if( A[i] > max )
		{
			max = A[i];
		}
	}
	return max;
}
void countSort( int A[] , int n )
{
	int i, j;
	int max = maximum( A  , n );
	int *count = (int*)malloc( max+1 * sizeof(int) );
	for( i=0; i<max+1; i++ )
	{
		count[i] = 0;
	}
	for( i=0; i<n; i++ )
	{
		count[A[i]]++;
	}
	i=0;
	j=0;
	while( i < max+1 )
	{
		if( count[i] > 0 )
		{
			A[j] = i;
			count[i]--;
			j++;
		}
		else
		{
			i++;
		}
	}
	
}
int main()
{
	int A[] = { 4,5,6,9,10,11,12 };
	int n = 7;
	printf("ARRAY BEFORE SORTING\n");
	printArray( A ,n );
	countSort( A ,n );
	printf("ARRAY AFTER SORTING\n");
	printArray( A ,n );
	
	return 0;
}
