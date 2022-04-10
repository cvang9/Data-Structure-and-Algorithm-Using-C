#include<stdio.h>
#include<stdlib.h>


struct Node 
{
	int data;
	struct Node *left;
	struct Node *right;
};

struct Node *nodeCreation( int data )
{
	struct Node *root = (struct Node*)malloc(sizeof(struct Node) );
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}


// PRE ORDER SEQUENCE =    ROOT -> LEFT SUB_ROOT -> RIGHT_SUBROOT
void preOrder( struct Node *root )
{
	if( root!=NULL)
	{
	printf("%d ",root->data );
	preOrder( root->left );
	preOrder( root->right );
    }
	
}

int main()
{
	struct Node *p;    
	struct Node *p1;
	struct Node *p2;
	struct Node *p3;
	struct Node *p4;
	struct Node *p5;
	struct Node *p6;
	
//															2
//			                                              /  \
//                                                      3     4
//													  /  \   / \		                                                      
//                                                   5    6 8   7

    p  = nodeCreation( 2 );
    p1 = nodeCreation( 3 );
    p2 = nodeCreation( 4 );
    p3 = nodeCreation( 5 );
    p4 = nodeCreation( 6 );
    p5 = nodeCreation( 7 );
    p6 = nodeCreation( 8 );
    
    
    p->left   = p1;
    p->right  = p2;
    p1->left  = p3;
    p1->right = p4;
    p2->left  = p6;
    p2->right = p5;
	
// TRAVERSING A TREE USING  [ PRE ORDER TRAVERSAL ]
    preOrder( p );

	return 0;
}
