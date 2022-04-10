#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
    struct node*next;                                            //POINTERS WHICH POINTS NEXT NODE
};

int main()
{
	struct node *head,*second,*third,*fourth;                    //POINTERS WHICH POINTS FROM HEAP TO STACK STORAGE 
	head = (struct node*)malloc(sizeof(struct node));
	second = (struct node*)malloc(sizeof(struct node));
	third = (struct node*)malloc(sizeof(struct node));
	fourth = (struct node*)malloc(sizeof(struct node));
	// 1st||HEAD NODE 
	head-> data = 7;
	head->next = second;
	//2nd NODE
	second->data = 8;
	second->next = third;
	//3rd NODE
	third->data = 9;
	third->next = fourth;
	//4th||TAIL NODE
	fourth->data = 69;
	fourth->next = NULL;
	//TRAVERSAL
	traversal( head );
	
	return 0;
}

void traversal( struct node*ptr )
{
	while( ptr!=NULL )                                            //STOPS WHEN FOUND AN NULL NODE (fifth one)
	{
		printf("DATA IS :%d\n",ptr->data );
		ptr=ptr->next;
	}
}
