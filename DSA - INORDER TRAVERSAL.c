#include<stdio.h>
#include<stdlib.h>

struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node * createNode( int data )
{
   struct Node *root = (struct Node*)malloc( sizeof( struct Node) );
   root->data = data;
   root->left = NULL;
   root->right = NULL;
   return root;
   	
}

void inOrder( struct Node *root )
{
	if( root!=NULL )
	{
		inOrder( root->left );
		printf( "%d\n" , root->data );
		inOrder( root->right );
	}
}

int main()
{
	struct Node *p ,*p1 ,*p2 ,*p3 ,*p4;

    p  = createNode( 5 );
    p1 = createNode( 7 );
    p2 = createNode( 3 );
    p3 = createNode( 6 );
    p4 = createNode( 9 );
	
	p->left = p1;
	p->right = p2;
	p1->left = p3;
	p1->right = p4;
	
	inOrder( p );
		
	return 0;
}
