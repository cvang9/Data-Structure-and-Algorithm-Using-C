#include<stdio.h>

int linearSearch( int a[], int size, int element )
{
	 int i;
	 for( i=0; i<size; i++)
	 {
	 	if( a[i]==element );
	 	 {
	 	    return i;
		 }
	 }
	 return -1;
}
 
 int binarySearch( int a[], int size, int element )
 {   
     int low=0;
 	 int high = size-1;
    while( low<=high )
    {
	   int mid = ( low + high)/2;
 	   if( a[mid]==element)
 	   {
 	     return mid;
	   }
 	   else if ( a[mid]<element )
 	    {
 	   	    low = mid+1;
		}
 	   else
 	   {
 	   	    high=mid-1;
	   }
    }
    return -1;
 }
  
int main()
{
	//FOR LINEAR SEARCHING
	int arr[10]={1,3,2,6,5,4,9,8};
	int element=4;
	int size1 = sizeof(arr)/sizeof(int);
	int searchIndex= linearSearch( arr, size1, element);
	printf(" ELEMENT %d IS AT INDEX %d\n",element,searchIndex);
	//FOR BINARY SEARCHING
	int arrr[10]={1,2,3,4,5,6,7,8,9};
	int elementB=6;
	int sizeB = sizeof(arrr)/sizeof(int);
	int searchIndexB= binarySearch( arrr, sizeB, elementB);
	printf(" ELEMENT %d IS AT INDEX %d\n",elementB,searchIndexB);
	
}
 
 
 
 
 
 
 
 
 
 
