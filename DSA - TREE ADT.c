#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node* createNode( int data )
{
	struct Node*p = (struct Node*)malloc(sizeof(struct Node) );
	p->data = data;
	p->left = NULL;
	p->right = NULL;   
		
	return p;
}

int main()
{
	struct Node *p;					//										       	3
	struct Node *p1;				// 						              6                      9
	struct Node *p2;				//      						4           7         10             1                   
	struct Node *p11;              //						    NULL  NULL	NULL NULL NULL 	 NULL	NULL	NULL
	struct Node *p12;
	struct Node *p21;
	struct Node *p22;
	
	p  = createNode( 3 );
	p1 = createNode( 6 );
	p2 = createNode( 9 );
	
	p11  = createNode( 4 );
	p12  = createNode( 7 );
	p21  = createNode( 10 );
	p22  = createNode( 1 );
	
	p->left  = p1;
	p->right = p2;
	
	p1->left  = p11;
	p1->right = p12;
	p2->left  = p21;
	p2->right = p22; 
	
	return 0;
}
