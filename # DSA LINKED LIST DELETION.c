#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node*next;
};

//CASE:1
struct Node*deletionAtHead( struct Node*head )
{
	struct Node*ptr = head;
	head = head->next;
	free(ptr);
	
	return head;
}
 
 //CASE:2
struct Node*deletionAtMid( struct Node*head , int index )
{
   struct Node*p = head;
   int i = 0;
   while( i!=index-1 )
   {
   	p=p->next;
   	i++;
   }
   struct Node*q = p->next;
   p->next = q->next;
   free(q);	
    
    return head;
}

//CASE:3
struct Node*deletionAtEnd( struct Node*head )
{
	struct Node*p = head;
	while( p->next->next !=NULL)
	{
		p=p->next;
	}
	 struct Node*q = p->next;
	 p->next = NULL;
	 free(q);
	 return head;
}

//CASE:4
struct Node*deletionAtKey( struct Node*keynode ,  struct Node*head )
{
	struct Node*p = head;
	while( p->next!= keynode )
	{
       p = p->next;	
	}
	p->next = keynode->next;
	free(keynode);
	
	return head;
}
  
  
int main()
{
	struct Node*head,*second,*third,*end;
	head = (struct Node*)malloc(sizeof(struct Node));
	second = (struct Node*)malloc(sizeof(struct Node));
	third = (struct Node*)malloc(sizeof(struct Node));
	end = (struct Node*)malloc(sizeof(struct Node));
	
	head->data = 5;
	head->next = second;
	
	second->data = 6;
	second->next = third;
	
	third->data = 7;
	third->next = end;
	 
	end-> data = 8;
	end->next = NULL;
	
	printf( "LINKED LIST BEFORE DELETION\n");
	traverse( head );
//    head = deletionAtHead( head );                           // DELETION AT HEAD            (case 1)
//    head = deletionAtMid( head , 2);                        //  DELETION A NODE IN BETWEEN  (case 2)
//    head = deletionAtEnd( head );                          //   DELETION AT END             (case 3)
//      head = deletionAtKey( second , head );              //    DELETION  AT GIVEN KEY NODE (case 4)
	printf( "LINKED LIST AFTER DELETION\n");
	traverse( head );
	
	return 0;
}

//TRAVERSAL 
void traverse( struct Node*ptr )
{
	while( ptr!=NULL)
	{
	  printf("ELEMENT IS: %d\n",ptr->data);	
	  ptr = ptr->next;
	}
}
