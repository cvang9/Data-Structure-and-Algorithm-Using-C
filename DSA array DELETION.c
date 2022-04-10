#include<stdio.h>
int main()
{
 int arr[10]={ 1,22,33,44,55,66};	
 printf("ARRAY BEFORE DELETION\n");
 display( arr,6 );
 printf("ARRAY AFTER DELETION\n");
 indDeletion( arr,6,1,10);
}
 
 void display( int ar[], int size)
 {
 	int i;
 	for( i=0; i<size; i++)
 	{
 		printf("%d, ",ar[i]);
	}
	printf("\n");
 }
 
 void indDeletion( int a[], int sz, int index, int capacity)
 {
 	if( index>capacity)
 	{
	 printf("INDEX OUT OF BOUND");
    }
    
 	else
 	{
 	int i;	
 	for( i=index; i<sz-1; i++ )
	  {
	 	a[i]=a[i+1];
	  }	
	  display( a,5 );
	}
 }
