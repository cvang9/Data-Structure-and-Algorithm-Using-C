#include<stdio.h>


void printArray( int *A , int n )
{
	int i;
	for( i=0; i<n; i++ )
	{
		printf("%d ",A[i] );
	}
	printf("\n");
}

void mergeProcedure( int A[] , int low ,int mid ,int high )
{
	int i ,j ,k ,B[20];
	i = low;
	j = mid+1;
	k = low;
	while( i<=mid && j<=high )
	{
		if( A[i]<A[j] )
		{
			B[k] = A[i];
			i++;
			k++;
		}
		else
		{
			B[k] = A[j];
			j++;
			k++;
		}
	}
	while( i<=mid )
	{
		B[k] = A[i];
		i++;
		k++;
	}
	while( j<=high )
	{
		B[k] = A[j];
		j++;
		k++;
	}
	for( i=low; i<=high; i++ )
    {
      A[i] = B[i];	
    }
}

void mergeSort( int *A , int low , int high )

{
	int mid;
	if( low<high )
	{
    mid = (low + high)/2;
	mergeSort( A , low , mid);
	mergeSort( A , mid+1 , high );
	mergeProcedure( A , low ,mid ,high );
   }
}

int main()
{
	int A[] = { 6,5,3,4,9,7,8};
	int n = 7;
	printf("ARRAY BEFORE SORTING\n");
	printArray( A , n );
	mergeSort( A , 0 , 6);
	printf("ARRAY AFTER SORTING\n");
	printArray( A , n );
	
	return 0;
}
