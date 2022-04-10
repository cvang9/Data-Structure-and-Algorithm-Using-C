#include<stdio.h>

void printArray( int *arr , int size )
{
	int i;
	for( i=0; i<size; i++ )
	{
		printf("%d ",arr[i] );
	}
	printf("\n");
}

void insertionSort( int *arr , int size )
{
	int i , j , key ;
	//NO. OF PASSES
	for( i=1; i<=size-1 ; i++ )
	{
		key = arr[i];
		j = i-1;
		// NO. OF COMPARISONS
		while( j>=0 && arr[j]>key )
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key; 
	}
}

// DRY RUN

// 1st pass:
// i=1 , j=0 , key = 4;
// as 4<12 condition true 
// result ->  4,12,56,7,4,67

// 2nd pass:
// i=2 , j=1 , key=56 ;
// as 56>12 condition false 
// result -> 4,12,56,7,4,67

// 3rd pass:
// i=3 , j=2 , key=7 ;
// as 7<56 condition true for 56 , 12 and false for 4
// 56 -> 4,12,56,56,4,67 ( j=2 )
// 12->  4,12,12,56,4,67 ( j=1 ) 
// 4->   4,7,12,56,4,67  ( j=0 )                     because [ a[j+1] = key; ]
// result -> 4,7,12,56,4,67

// 4th pass:
// i=4 , j=3 , key=4 ;
// as 4<56 condition true for 56,12,7 and false for 4
// result -> 4,4,7,12,56,67

// 5th pass:
// i=5 , j=4 , key=67 ;
// as 67>56 condition false 
// result -> 4,4,7,12,56,67

int main()
{
	int arr[] = { 12,4,56,7,4,67};
	int size = 6;
	printf("ARRAY BEFORE SORTING\n");
	printArray( arr , 6 );
	insertionSort( arr , 6);
	printf("ARRAY AFTER SORTING\n");
	printArray( arr , 6 );
	
	return 0;
}
