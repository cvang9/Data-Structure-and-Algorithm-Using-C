#include<stdio.h>

void printArray( int *arr , int size )
{
	int i;
	for( i=0 ; i<size; i++ )
	{
	printf("%d  ",arr[i] );
    }
    printf("\n");
}

void bubbleSort( int *arr , int size)
{
	int i , j , temp , isSorted = 1;                      // isSorted is used to make algorithm ADAPTIVE;
	for( i=0; i<size-1; i++ )                             // (remove isSorted variable if not need of adaptive algo BUUBLE SORT);
	{
		printf("CHECK PASS: %d\n",i+1);
		isSorted = 1;
		for( j=0; j<size-1-i; j++ )
		{
			if( arr[j] > arr[j+1] )
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
				isSorted = 0;
			}
		}
		if(isSorted)
		{
			return;
		}	
	}
}

int main()
{
//	int arr[] = { 12,43,54,56,7,6 };
	int arr[] = {1,2,3,4,5,6};
	int size = 6;
	printf("ARRAY BEFORE SORTING\n");
	printArray( arr , size );
	bubbleSort( arr , size );
	printf("ARRAY AFTER SORTING\n");
	printArray( arr , size );
	
	return 0;
}
